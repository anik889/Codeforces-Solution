import requests
import re
from collections import defaultdict

HANDLE = "Onex"
README = "README.md"
FOCUS_RANGE  = "1200 – 1600"
WEAKEST_AREA = "To Be Updated"

SKIP_TAGS = {"*special problem", "2-sat", "fft", "flows", "string suffix structures"}

def fetch(endpoint, **params):
    r = requests.get(f"https://codeforces.com/api/{endpoint}", params=params, timeout=20)
    r.raise_for_status()
    data = r.json()
    if data["status"] != "OK":
        raise Exception(data.get("comment", "CF API error"))
    return data["result"]

def main():
    print(f"Fetching submissions for {HANDLE}...")
    subs = fetch("user.status", handle=HANDLE, from_=1, count=100000)

    solved = set()
    tag_count = defaultdict(int)

    for s in subs:
        if s.get("verdict") != "OK":
            continue
        p = s["problem"]
        key = (p.get("contestId"), p.get("index"))
        if key in solved:
            continue
        solved.add(key)
        for tag in p.get("tags", []):
            if tag not in SKIP_TAGS:
                tag_count[tag] += 1

    total_solved = len(solved)
    strongest = max(tag_count, key=tag_count.get) if tag_count else "Implementation"
    strongest_area = f"{strongest.title()} ({tag_count[strongest]} problems)"

    print(f"Fetching contest history for {HANDLE}...")
    ratings = fetch("user.rating", handle=HANDLE)
    total_contests = len(ratings)

    print(f"Problems solved : {total_solved}")
    print(f"Contests joined : {total_contests}")
    print(f"Strongest area  : {strongest_area}")

    with open(README, "r", encoding="utf-8") as f:
        content = f.read()

    block = f"""<!-- DASHBOARD_START -->
| Metric | Value |
|:--|:--|
| Total Problems Solved | `{total_solved}` |
| Total Contests Joined | `{total_contests}` |
| Current Focus Range | `{FOCUS_RANGE}` |
| Strongest Area | `{strongest_area}` |
| Weakest Area | `{WEAKEST_AREA}` |
<!-- DASHBOARD_END -->"""

    new_content, n = re.subn(
        r"<!-- DASHBOARD_START -->.*?<!-- DASHBOARD_END -->",
        block, content, flags=re.DOTALL
    )

    if n == 0:
        print("Sentinels not found — appending to end of README.")
        new_content = content.rstrip() + "\n\n" + block + "\n"

    with open(README, "w", encoding="utf-8") as f:
        f.write(new_content)

    print("README updated successfully.")

if __name__ == "__main__":
    main()
