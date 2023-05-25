#include <iostream>
using namespace std;

//   Definition for singly-linked list.
  struct ListNode{
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

  class Solution{
  public:
      /**
       *
       * @param head1 ListNode类
       * @param head2 ListNode类
       * @return ListNode类
       */
      ListNode *addInList(ListNode *head1, ListNode *head2){
        // 先反转两个链表以方便从最低位置（LSB）开始提取数字。
        // 得到两个链表代表的数字后,直接相加,将得到的数字每一位一次用取模的方式放入新链表内。
        ListNode *p1 = head1;
        ListNode *p2 = head2;
        ListNode *new_head = new ListNode(-1);
        ListNode *itr = new_head;

        // 反转两个链表.
        p1 = reverseList(p1);
        p2 = reverseList(p2);

        // 直接遍历反转过后的两个链表，同时考虑进位。
        int quotient = 0;
        int remainder = 0;
        while(p1 != NULL && p2 != NULL){
            // quotient代表的要进位的值。
            int cur_sum = p1->val + p2->val + quotient;
            quotient = cur_sum / 10;
            remainder = cur_sum % 10;
            itr->next = new ListNode(remainder);
            itr = itr->next;
            p1 = p1->next;
            p2 = p2->next;
        }
        
        // 当两个链表之中较短的那个走完之后，剩下的那个接着走。
        // p2先走完的情况（p2较短）。
        while(p1 != NULL){
            int cur_sum = p1->val + quotient;
            quotient = cur_sum / 10;
            remainder = cur_sum % 10;
            itr->next = new ListNode(remainder);
            itr = itr->next;
            p1 = p1->next;
        }

        // p1先走完的情况（p1较短）。
        while(p2 != NULL){
            int cur_sum = p2->val + quotient;
            quotient = cur_sum / 10;
            remainder = cur_sum % 10;
            itr->next = new ListNode(remainder);
            itr = itr->next;
            p2 = p2->next;
        } // 注意这两个while只有一个会运行，另一个会被跳过。

        // 最后如果quotient不为0，说明要多增加一个结点，用于存放多出来的最高位进位。
        if(quotient != 0){
            itr->next = new ListNode(quotient);
        }

        // 最后反转整个得到的链表，以达到题设要求的链表连接方向。
        return reverseList(new_head->next);
      }

      ListNode *reverseList(ListNode *phead){
        ListNode *pre = NULL;
        ListNode *next = NULL;
        while(phead != NULL){
            next = phead->next;
            phead->next = pre;
            pre = phead;
            phead = next;
        }
        return pre;
      }
  };