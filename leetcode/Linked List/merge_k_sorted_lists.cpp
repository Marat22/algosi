// https://leetcode.com/problems/merge-k-sorted-lists/description/

#include <functional>
#include <algorithm>
#include <vector>
#include <queue> // Required for priority_queue

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        lists.erase(
            remove_if(
                lists.begin(),
                lists.end(),
                [](ListNode* node) { return node == nullptr; }
            ),
            lists.end()
        );

        if (lists.size() == 0) {
            return nullptr;
        }

        auto compare = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };

        priority_queue<ListNode*, vector<ListNode*>, decltype(compare)> min_heap(compare);

        for (ListNode* list : lists) {
            min_heap.push(list);
        }

        ListNode* res = min_heap.top();
        ListNode* res_node = res;
        min_heap.pop();

        if (res->next != nullptr) {
            min_heap.push(
                res->next
            );
        }

        while (min_heap.size() != 0) {
            res_node->next = min_heap.top();
            res_node = res_node->next;
            min_heap.pop();
            
            if (res_node->next != nullptr) {
                min_heap.push(
                    res_node->next
                );
            }
        }

        return res;
    }
};