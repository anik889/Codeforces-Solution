import requests
import re
import sys
from collections import defaultdict

# ── CONFIG ────────────────────────────────────────────────────────────────────
CF_HANDLE        = "Onex"
README_PATH      = "README.md"

# These two are MANUAL — CF API cannot derive them.
# Update them yourself when your grind focus shifts.
FOCUS_RANGE      = "1200 – 1600"
WEAKEST_AREA     = "To Be Updated"

# Tags to skip when computing strongest/weakest (meta-tags, not skill areas)
SKIP_TAGS = {
    "*special problem", "2-sat", "fft", "flows", "string suffix structures",
}
# ─────────────────────────────────────────────────────────────────────────────


def cf_get(endpoint: str, **params) -> dict:
    url = f"https://codeforces.com/api/{endpoint}"
    resp = requests.get(url, params=params, timeout=20)
    resp.raise_for_status()
    data = resp.json()
    if data["status"] != "OK":
        raise RuntimeError(f"CF API error: {data.get('comment', 'unknown')}")
    return data["result"]


def fetch_dashboard_stats(handle: str) -> dict:
    print(f"  → Fetching submissions for {handle}...")
    submissions = cf_get("user.status", handle=handle, from_=1, count=100000)

    # ── Unique problems solved (distinct contestId+index with verdict OK) ──
    solved_set   = set()
    tag_ac_count = defaultdict(int)   # tag → number of DISTINCT problems AC'd with that tag

    for s in submissions:
        if s.get("verdict") != "OK":
            continue
        prob  = s["problem"]
        key   = (prob.get("contestId"), prob.get("index"))
        if key in solved_set:
            continue
        solved_set.add(key)
        for tag in prob.get("tags", []):
            if tag not in SKIP_TAGS:
                tag_ac_count[tag] += 1

    total_solved = len(solved_set)

    # ── Strongest area: tag with most unique AC'd problems ──
    if tag_ac_count:
        strongest_tag   = max(tag_ac_count, key=lambda t: tag_ac_count[t])
        strongest_count = tag_ac_count[strongest_tag]
        strongest_area  = f"{strongest_tag.title()} ({strongest_count} problems)"
    else:
        strongest_area  = "Implementation"

    # ── Contests joined: number of rated contest entries ──
    print(f"  → Fetching rating history...")
    rating_changes  = cf_get("user.rating", handle=handle)
    total_contests  = len(rating_changes)

    return {
        "total_solved":   total_solved,
        "total_contests": total_contests,
        "focus_range":    FOCUS_RANGE,
        "strongest_area": strongest_area,
        "weakest_area":   WEAKEST_AREA,
    }


def update_readme(stats: dict, path: str) -> None:
    """
    Replaces content between these sentinel comments in README.md:

        <!-- DASHBOARD_START -->
        <!-- DASHBOARD_END -->

    The block matches the exact table format from your README.
    """
    with open(path, "r", encoding="utf-8") as f:
        content = f.read()

    block = "\n".join([
        "<!-- DASHBOARD_START -->",
        "| 📈 **PERFORMANCE DASHBOARD** ||",
        "| :--- | :--- |",
        f"| Total Problems Solved | **{stats['total_solved']:,}** |",
        f"| Total Contests Joined | **{stats['total_contests']}** |",
        f"| Current Focus Range | {stats['focus_range']} |",
        f"| Strongest Area | {stats['strongest_area']} |",
        f"| Weakest Area | {stats['weakest_area']} |",
        "",
        "*🤖 Auto-updated via GitHub Actions · [workflow](.github/workflows/update-dashboard.yml)*",
        "<!-- DASHBOARD_END -->",
    ])

    pattern     = r"<!-- DASHBOARD_START -->.*?<!-- DASHBOARD_END -->"
    new_content, n = re.subn(pattern, block, content, flags=re.DOTALL)

    if n == 0:
        print("⚠️  Sentinels not found — appending dashboard at end of README.")
        new_content = content.rstrip() + "\n\n" + block + "\n"

    with open(path, "w", encoding="utf-8") as f:
        f.write(new_content)

    print(f"✅ Dashboard updated in {path}")


def print_stats(stats: dict) -> None:
    print()
    print("  ┌─────────────────────────────────────────┐")
    print("  │        📈 PERFORMANCE DASHBOARD         │")
    print("  ├────────────────────────┬────────────────┤")
    print(f"  │ Total Problems Solved  │ {stats['total_solved']:<14} │")
    print(f"  │ Total Contests Joined  │ {stats['total_contests']:<14} │")
    print(f"  │ Current Focus Range    │ {stats['focus_range']:<14} │")
    print(f"  │ Strongest Area         │ {stats['strongest_area'][:14]:<14} │")
    print(f"  │ Weakest Area           │ {stats['weakest_area'][:14]:<14} │")
    print("  └────────────────────────┴────────────────┘")
    print()


if __name__ == "__main__":
    handle = sys.argv[1] if len(sys.argv) > 1 else CF_HANDLE
    print(f"\n🔍 Fetching Codeforces data for: {handle}")
    stats  = fetch_dashboard_stats(handle)
    print_stats(stats)
    update_readme(stats, README_PATH)
