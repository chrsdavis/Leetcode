// If you do this with constant space, then you need to figure out how to reverse the first n bits of a byte
// ie only the n-long initial subspan is reversed, not the entire byte

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
    int getDecimalValue(ListNode* head) {
        vector<int> digits;
        while (head) {
            digits.push_back(head->val);
            head = head->next;
        }
        int ans = 0;
        for (int i = 0; i < digits.size(); i++) {
            ans |= digits[digits.size() - 1 - i] << i;
        }
        return ans;
    }
};