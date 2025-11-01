// https://leetcode.com/problems/linked-list-cycle/

#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {

        
        // vector<ListNode*> ordered_arr;

        unordered_set<ListNode*> hz;
        unordered_set<int> hz2;
        while (head != NULL) {
            if (hz.count(head)) // in
                return true;
            // ordered_arr.push_back(head);
            hz.insert(head);

            // if (hz2.count(head->val)) {
            //     return true;
            // }
            // hz2.insert(head->val);
            head = head->next;
        }
        return false;
        
    }
};