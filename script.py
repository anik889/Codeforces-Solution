# =========================================================
# Codeforces → GitHub Automatic Sync Script
# =========================================================
#
# Features:
# - Fetches accepted submissions from Codeforces
# - Downloads source code automatically
# - Organizes by rating range
# - Uses professional filename format
# - Prevents duplicates
# - Generates folder structure automatically
# - Auto commits & pushes to GitHub
#
# =========================================================
# REQUIREMENTS
# =========================================================
#
# pip install requests beautifulsoup4
#
# =========================================================

import os
import re
import time
import requests
import subprocess
from bs4 import BeautifulSoup

# =========================================================
# CONFIG
# =========================================================

HANDLE = "Onex"

REPO_PATH = r"D:\codeforces repo\Codeforces-Solution"

GIT_BRANCH = "main"

HEADERS = {
    "User-Agent": "Mozilla/5.0"
}

# =========================================================
# RATING FOLDERS
# =========================================================

RATING_BUCKETS = [
    (800, 999),
    (1000, 1199),
    (1200, 1399),
    (1400, 1599),
    (1600, 1799),
    (1800, 1999),
    (2000, 5000)
]

# =========================================================
# HELPERS
# =========================================================

def sanitize_filename(name):
    name = re.sub(r'[^a-zA-Z0-9 ]', '', name)
    name = name.strip().replace(" ", "_")
    return name


def get_rating_folder(rating):
    if rating is None:
        return "UNRATED"

    for low, high in RATING_BUCKETS:
        if low <= rating <= high:
            if high >= 5000:
                return "2000+"
            return f"{low:04d}-{high}"

    return "UNRATED"


def create_folder_if_not_exists(path):
    if not os.path.exists(path):
        os.makedirs(path)


# =========================================================
# FETCH SUBMISSIONS
# =========================================================

def fetch_submissions(handle):
    url = f"https://codeforces.com/api/user.status?handle={handle}"

    response = requests.get(url, headers=HEADERS)

    data = response.json()

    if data["status"] != "OK":
        raise Exception("Failed to fetch submissions")

    return data["result"]


# =========================================================
# DOWNLOAD SOURCE CODE
# =========================================================

def download_source(contest_id, submission_id):

    url = f"https://codeforces.com/contest/{contest_id}/submission/{submission_id}"

    response = requests.get(url, headers=HEADERS)

    if response.status_code != 200:
        print(f"[FAILED] Submission {submission_id}")
        return None

    soup = BeautifulSoup(response.text, "html.parser")

    source = soup.find("pre", id="program-source-text")

    if not source:
        print(f"[NO SOURCE FOUND] {submission_id}")
        return None

    return source.text


# =========================================================
# SAVE SOLUTION
# =========================================================

def save_solution(problem, code):

    contest_id = problem["contestId"]
    index = problem["index"]
    name = sanitize_filename(problem["name"])

    rating = problem.get("rating", None)

    folder = get_rating_folder(rating)

    folder_path = os.path.join(REPO_PATH, folder)

    create_folder_if_not_exists(folder_path)

    filename = f"{contest_id}{index}_{name}.cpp"

    file_path = os.path.join(folder_path, filename)

    if os.path.exists(file_path):
        print(f"[SKIPPED] {filename}")
        return False

    with open(file_path, "w", encoding="utf-8") as f:
        f.write(code)

    print(f"[SAVED] {filename}")

    return True


# =========================================================
# GIT PUSH
# =========================================================

def git_push():

    print("\n[INFO] Pushing to GitHub...\n")

    subprocess.run(["git", "add", "."], cwd=REPO_PATH)

    subprocess.run(
        ["git", "commit", "-m", "Update Codeforces solutions"],
        cwd=REPO_PATH
    )

    subprocess.run(
        ["git", "push", "origin", GIT_BRANCH],
        cwd=REPO_PATH
    )

    print("\n[DONE] GitHub updated.\n")


# =========================================================
# MAIN
# =========================================================

def main():

    print(f"\nFetching submissions for: {HANDLE}\n")

    submissions = fetch_submissions(HANDLE)

    accepted = []

    seen = set()

    for sub in submissions:

    
        if sub.get("verdict") != "OK":
            continue

        if "contestId" not in sub or "problem" not in sub:
            continue

        contest_id = sub["contestId"]
        submission_id = sub["id"]
        problem = sub["problem"]
        if sub["verdict"] != "OK":
            continue

        problem = sub["problem"]

        key = (
            problem.get("contestId"),
            problem.get("index")
        )

        if key in seen:
            continue

        seen.add(key)

        accepted.append(sub)

    print(f"Accepted unique problems: {len(accepted)}\n")

    saved_count = 0

    for sub in accepted:

        contest_id = sub["contestId"]
        submission_id = sub["id"]

        problem = sub["problem"]

        try:

            code = download_source(
                contest_id,
                submission_id
            )

            if not code:
                continue

            saved = save_solution(problem, code)

            if saved:
                saved_count += 1

            time.sleep(1)

        except Exception as e:
            print(f"[ERROR] {e}")

    print(f"\nSaved new files: {saved_count}\n")

    git_push()


# =========================================================

if __name__ == "__main__":
    main()

# =========================================================