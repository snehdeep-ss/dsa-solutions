/*
 * Problem:  721. Accounts Merge
 * URL:       https://leetcode.com/problems/accounts-merge/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   99 ms  (beats 11.4%)
 * Memory:    50104000  (beats 17.1%)
 * Date:      2026-05-09
 * Context:  Day 24 — Union-Find (Disjoint Set Union)
 */

class Solution {

    string find(unordered_map<string, string>& parents, string a) {
        if (a != parents[a]) {
            parents[a] = find(parents, parents[a]); // Path compression
        }
        return parents[a];
    }

    void unionEmails(unordered_map<string, string>& parents,
                     unordered_map<string, int>& size, const string& a, const string& b) {
        string a_parent = find(parents, a);
        string b_parent = find(parents, b);
        if (a_parent == b_parent)
            return;

        if (size[a_parent] < size[b_parent]) {
            swap(a_parent, b_parent);
        }
        parents[b_parent] = a_parent;
        size[a_parent] += size[b_parent];
    }

public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, string> parents;
        unordered_map<string, string> emailToName;
        unordered_map<string, int> size;

        for (auto& ac : accounts) {
            string name = ac[0];

            for (int i = 1; i < ac.size(); i++) {
                string email = ac[i];
                emailToName[email] = name;
                parents[email] = email;
                size[email] = 1;
            }
        }

        for (auto& ac : accounts) {
            if (ac.size() <= 2)
                continue;

            string firstEmail = ac[1];

            for (int i = 2; i < ac.size(); i++) {
                unionEmails(parents, size, firstEmail, ac[i]);
            }
        }

        unordered_map<string, vector<string>> groups;

        for (const auto& pair : parents) { 
            const string& email = pair.first;
            string root = find(parents, email);
            groups[root].push_back(email);
        }

        vector<vector<string>> ans;
        for (auto& [root, emails] : groups) {
            sort(emails.begin(), emails.end());
            vector<string> temp;
            temp.push_back(emailToName[root]);
            temp.insert(temp.end(), emails.begin(), emails.end());
            ans.push_back(temp);
        }

        return ans;
    }
};