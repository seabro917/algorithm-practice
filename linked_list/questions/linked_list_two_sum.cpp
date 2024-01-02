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
// leetcode 2
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* ptr = dummy;
        int carry_in = 0;
        while (l1 || l2) {
            int l1_val = l1 ? l1->val : 0;
            int l2_val = l2 ? l2->val : 0;
            int sum_temp = l1_val + l2_val + carry_in;
            int val_temp = sum_temp % 10;
            // 题目已经说每个结点数值小于9,所以和肯定小于20,直接减即可.
            ptr->next = new ListNode(val_temp);
            ptr = ptr->next;
            carry_in = sum_temp / 10;
            if (l1) {
                l1 = l1->next;
            }
            if (l2) {
                l2 = l2->next;
            }
        }
        if (carry_in) {
            ptr->next = new ListNode(carry_in);
        }
        return dummy->next;
    }
};