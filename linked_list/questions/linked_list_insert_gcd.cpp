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
// leetcode 2807
class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* dummy = new ListNode (-1);
        dummy->next = head;
        while (head->next) {
            int gcd_val = gcd(head->val, head->next->val);
            ListNode* temp = new ListNode(gcd_val);
            temp->next = head->next;
            head->next = temp; 
            // 要多移动一个刚刚加入的数值为公约数的结点位置
            head = head->next->next;
        } 
        return dummy->next;
    }
};