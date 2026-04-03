/*
 * Problem:  133. Clone Graph
 * URL:       https://leetcode.com/problems/clone-graph/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   0 ms  (beats 100.0%)
 * Memory:    12156000  (beats 45.7%)
 * Date:      2026-04-03
 * Context:  Day 21 — Graph Foundations + BFS/DFS
 */

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {

    void dfs(Node* node, unordered_map<Node*, Node*>& mp) {
        if (!node)
            return;

        Node* newNode = new Node(node->val);
        mp[node] = newNode;

        for (auto nei : node->neighbors) {
            if (mp.find(nei) == mp.end()) {
                dfs(nei, mp);
            }
        }

        for (auto nei : node->neighbors) {
            newNode->neighbors.push_back(mp[nei]);
        }
    }

public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> mp;
        dfs(node, mp);
        return mp[node];
    }
};