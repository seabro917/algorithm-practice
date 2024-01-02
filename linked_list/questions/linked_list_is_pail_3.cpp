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
//  leetcode 234
// 数据放在数组里面再判断...
// 或者和我之前写的一样把后半部分链表翻转，然后依次比较
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> arr;
        while (head) {
            arr.emplace_back(head->val);
            head = head->next;
        }
        int i = 0;
        int j = arr.size() - 1;
        while (i < j) {
            if (arr[i] != arr[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};