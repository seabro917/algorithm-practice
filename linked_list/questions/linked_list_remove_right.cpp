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
// leetcode 2487
// 单调栈写法
// class Solution {
// public:
//     ListNode* removeNodes(ListNode* head) {
//         stack<ListNode*> stk;
//         // 设置dummy结点的val为inf,保证dummy不被弹出
//         ListNode* dummy = new ListNode(INT32_MAX);
//         dummy->next = head;
//         ListNode* itr = head;
//         stk.push(dummy);
//         while (itr) {
//             while (!stk.empty() && stk.top()->val < itr->val) {
//                 stk.pop();
//             }
//             stk.top()->next = itr;
//             stk.push(itr);
//             itr = itr->next;
//         }  
//         return dummy->next;
//     }
// };


// 递归写法
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        if (!head) {
            return nullptr;
        }
        head->next = removeNodes(head->next);
        if (head->next && head->val < head->next->val) {
            return head->next;
        }
        else {
            return head;
        }
    }
};