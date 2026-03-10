/*
 * Problem:  92. Reverse Linked List II
 * URL:       https://leetcode.com/problems/reverse-linked-list-ii/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   0 ms  (beats 100.0%)
 * Memory:    11088000  (beats 96.8%)
 * Date:      2026-03-10
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
    if (!head || left == right) return head;
    
    // Create a dummy node to handle edge cases when left = 1
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    
    // Step 1: Find the node before left (left_prev)
    ListNode* left_prev = dummy;
    for (int i = 1; i < left; i++) {
        left_prev = left_prev->next;
    }
    
    // Step 2: Find left node
    ListNode* left_node = left_prev->next;
    
    // Step 3: Find right node
    ListNode* right_node = left_node;
    for (int i = left; i < right; i++) {
        right_node = right_node->next;
    }
    
    // Step 4: Store the node after right
    ListNode* right_next = right_node->next;
    
    // Step 5: Break the connection
    right_node->next = nullptr;
    
    // Step 6: Reverse the sublist from left_node to right_node
    ListNode* prev = nullptr;
    ListNode* curr = left_node;
    ListNode* next = nullptr;
    
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    // Step 7: Connect everything back
    left_prev->next = right_node;  // Connect left_prev to new head
    left_node->next = right_next;   // Connect tail to right_next
    
    return dummy->next;
}
};