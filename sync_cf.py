import os
import time
import requests

# Configuration
HANDLE = "Onex"  # <-- Change this to your Codeforces handle
EXTENSIONS = {"C++": "cpp", "Python": "py", "Java": "java", "GNU C++": "cpp"}

def fetch_submissions():
    url = f"https://codeforces.com{HANDLE}&from=1&count=5000"
    response = requests.get(url).json()
    if response["status"] != "OK":
        print("Error fetching data from Codeforces.")
        return []
    return response["result"]

def main():
    submissions = fetch_submissions()
    accepted = [s for s in submissions if s.get("verdict") == "OK"]
    
    for sub in reversed(accepted): # Process oldest to newest
        contest_id = sub.get("contestId")
        problem = sub.get("problem", {})
        idx = problem.get("index")
        name = problem.get("name")
        rating = problem.get("rating") # Fetch problem difficulty rating
        lang = sub.get("programmingLanguage", "")
        submission_id = sub.get("id")
        
        if not contest_id or not idx:
            continue
            
        # 1. Determine the folder name based on difficulty rating
        if rating is None:
            folder_name = "Unrated-Difficulty"
        else:
            folder_name = f"{rating}-Difficulty"
            
        # Create the difficulty folder if it doesn't exist
        if not os.path.exists(folder_name):
            os.makedirs(folder_name)
            
        # 2. Determine file extension
        ext = "txt"
        for k, v in EXTENSIONS.items():
            if k in lang:
                ext = v
                break
                
        # 3. Format name: "4A - Watermelon.cpp"
        filename = f"{contest_id}{idx} - {name}.{ext}"
        # Clean filename for operating system compatibility
        filename = "".join(c for c in filename if c.isalnum() or c in "._- ").strip()
        
        # Complete relative path: e.g., "800-Difficulty/4A - Watermelon.cpp"
        filepath = os.path.join(folder_name, filename)
        
        # Skip if we already downloaded this solution
        if os.path.exists(filepath):
            continue
            
        print(f"Downloading new code to {filepath}")
        
        # Template content (Codeforces API doesn't share source code text directly)
        content = (
            f"// Submission ID: {submission_id}\n"
            f"// Problem: {name}\n"
            f"// Difficulty: {rating if rating else 'Unrated'}\n"
            f"// Link: https://codeforces.com{contest_id}/problem/{idx}\n\n"
        )
        
        with open(filepath, "w", encoding="utf-8") as f:
            f.write(content)
            
        time.sleep(0.5) # Prevent aggressive scraping limits

if __name__ == "__main__":
    main()
