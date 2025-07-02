// Can make this a lot simpler with a stack
// O(n) time, O(n) space
// To get O(1) space, split list in half, reverse second half, then zipper merge together.

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
        vector<ListNode*> nodes;
        ListNode* ptr = head;
        while (ptr) {
            nodes.push_back(ptr);
            ptr = ptr->next;
        }

        if (nodes.size() < 2) return;
        vector<ListNode*> ordered_nodes;
        ordered_nodes.reserve(nodes.size());
        for (int i = 0; i < nodes.size() / 2; i++) {
            ordered_nodes.push_back(nodes[i]);
            ordered_nodes.push_back(nodes[nodes.size() - 1 - i]);
        }
        if (nodes.size() % 2 != 0)
            ordered_nodes.push_back(nodes[nodes.size() / 2]);

        ordered_nodes.push_back(nullptr);
        for (int i = 0; i < ordered_nodes.size() - 1; i++) {
            ordered_nodes[i]->next = ordered_nodes[i+1];
        }
    }
};