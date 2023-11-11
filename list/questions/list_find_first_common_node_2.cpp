/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//  leetcode 160
// https://leetcode.cn/problems/intersection-of-two-linked-lists/solutions/10774/tu-jie-xiang-jiao-lian-biao-by-user7208t/?envType=study-plan-v2&envId=top-100-liked
// 和环形链表入口点一样有一定的数学推导在里面，见题解。
// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         ListNode* A = headA;
//         ListNode* B = headB;
//         int len_A = 0;
//         int len_B = 0;
//         // 找到两个链表各自的长度
//         while (A) {
//             len_A++;
//             A = A->next;
//         }
//         while (B) {
//             len_B++;
//             B = B->next;
//         }
//         cout << len_A << endl;
//         // 长度长的链表先走两个链表长度的差值步数
//         if (len_A >= len_B) {
//             for (int i = 0; i < len_A - len_B; i++) {
//                 headA = headA->next;
//             }
//         }
//         else if (len_B > len_A) {
//             for (int i = 0; i < len_B - len_A; i++) {
//                 headB = headB->next;
//             }
//         }
//         // 两个链表一起走
//         while (headA && headB) {
//             if (headA == headB) {
//                 return headA;
//             }
//             headA = headA->next;
//             headB = headB->next;
//         }
//         return NULL;
//     }
// };



class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* cur_A = headA;
        ListNode* cur_B = headB;
        // 两个链表直接开始走，一个到头了(null)就把他指向另一个链表头
        // 然后接着走，这样他们相等的时候要么是公共结点，要么就是他们同时走到了结尾(null)
        //  --> 因为通过接到另一个链表表头，他们实际上走过的路程都是A+B(两个链表长度之和)
        while (cur_A != cur_B) {
            cur_A = cur_A == nullptr ? headB : cur_A->next;
            cur_B = cur_B == nullptr ? headA : cur_B->next;
        }
        return cur_A;
    }
};


