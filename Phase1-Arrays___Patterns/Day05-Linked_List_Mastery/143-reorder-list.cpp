/*
 * Problem:  143. Reorder List
 * URL:       https://leetcode.com/problems/reorder-list/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   0 ms  (beats 100.0%)
 * Memory:    22556000  (beats 99.9%)
 * Date:      2026-03-17
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

    ListNode* findMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* next = nullptr;
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

public:
    void reorderList(ListNode* head) {

        if(!head || !head->next || !head->next->next) return;
        ListNode* mid = findMid(head);

        ListNode* midNext = mid->next;
        mid->next = nullptr;

        ListNode* revMidHead = reverseList(midNext);

        ListNode* first = head;
        ListNode* second = revMidHead;

        while(second) {

            ListNode* fTemp = first->next;
            ListNode* sTemp = second->next;

            first->next = second;
            second->next = fTemp;

            first = fTemp;
            second = sTemp;
        }
    }
};