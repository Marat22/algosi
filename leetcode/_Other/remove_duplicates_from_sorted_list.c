/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* prev_node = head;
    while (prev_node && prev_node->next) {
        if (prev_node->val == prev_node->next->val) {
            prev_node->next = prev_node->next->next;
        }
        else {
            prev_node = prev_node->next;
        }
    }
    return head;
}