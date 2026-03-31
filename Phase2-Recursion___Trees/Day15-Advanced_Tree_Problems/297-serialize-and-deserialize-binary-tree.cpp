/*
 * Problem:  297. Serialize and Deserialize Binary Tree
 * URL:       https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   25 ms  (beats 70.6%)
 * Memory:    36272000  (beats 33.7%)
 * Date:      2026-03-31
 * Context:  Day 15 — Advanced Tree Problems
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "";
        if (!root)
            return res;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            if (curr) {
                res += to_string(curr->val);
                res += ",";

                q.push(curr->left);
                q.push(curr->right);
            } else
                res += "#,";
        }

        if (!res.empty())
            res.pop_back();
        cout << res << endl;
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty())
            return nullptr;

        vector<string> nodes;
        stringstream ss(data);

        string token;

        while (getline(ss, token, ',')) {
            nodes.push_back(token);
        }

        int index = 0;
        queue<TreeNode*> q;

        TreeNode* root = new TreeNode(stoi(nodes[index++]));

        q.push(root);

        while (!q.empty() && index < nodes.size()) {
            TreeNode* curr = q.front();
            q.pop();

            if (nodes[index] != "#") {
                curr->left = new TreeNode(stoi(nodes[index]));
                q.push(curr->left);
            }
            index++;

            if (index < nodes.size() && nodes[index] != "#") {
                curr->right = new TreeNode(stoi(nodes[index]));
                q.push(curr->right);
            }
            index++;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));