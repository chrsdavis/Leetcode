// https://leetcode.com/problems/merge-two-sorted-lists/
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
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
            ListNode head(0xffff);
            ListNode* tail = &head;
            while(list1 && list2)
            {
                // find the minimum value
                ListNode*& min = list1->val < list2->val ? list1 : list2;
                // push new min node to the final list
                tail = tail->next = min;
                // progress the current minimum list
                min = min->next;
            } // 1 longer than the other
            tail->next = list1 ? list1 : list2;
            return head.next; // head is temp node
        }
};
