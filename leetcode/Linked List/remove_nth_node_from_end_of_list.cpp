// https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* arr[30];

        int index_of_last_node = -1;
        ListNode* curr = head;

        while (curr) {
            arr[++index_of_last_node] = curr;
            curr = curr->next;
        }

        int index_of_node_to_delete = index_of_last_node - (n - 1);
        
        if (index_of_node_to_delete == 0) {
            head = head->next;
        }
        else {
            arr[index_of_node_to_delete - 1]->next = arr[index_of_node_to_delete]->next; 
        }

        return head;
    }
};