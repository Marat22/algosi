// https://leetcode.com/problems/reorder-list/description/

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
    void reorderList(ListNode* head) {
        // DETERMINE WHERE SECOND HALF STARTS
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // REVERSE SECOND HALF
        ListNode* second = slow->next;
        slow->next = nullptr;
        ListNode* prev = nullptr;
        while (second) {
            ListNode* tmp = second->next;
            second->next = prev;
            prev = second;
            second = tmp;
        }

        // UPDATE NEXTS
        ListNode* first = head;
        second = prev;

        while (second) {
            ListNode* tmp1 = first->next, *tmp2=second->next;
            first->next = second;
            second->next = tmp1;
            first = tmp1;
            second = tmp2;
        }

    }
};