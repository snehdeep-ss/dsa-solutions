/*
 * Problem:  23. Merge K Sorted Lists
 * URL:       https://leetcode.com/problems/merge-k-sorted-lists/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   0 ms  (beats 100.0%)
 * Memory:    18248000  (beats 92.2%)
 * Date:      2026-03-21
 * Context:  Day 5 — Linked List Mastery
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto comp = [](ListNode* a, ListNode* b) { return a->val > b->val; };

        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> pq;

        for (auto node : lists) {
            if (node)
                pq.push(node);
        }

        ListNode dummy;
        ListNode* curr = &dummy;

        while (!pq.empty()) {
            ListNode* temp = pq.top();
            pq.pop();
            ListNode* next = temp->next;
            if (next)
                pq.push(next);
            curr->next = temp;
            curr = curr->next;
        }
        return dummy.next;
    }
};