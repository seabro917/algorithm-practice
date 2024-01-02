#include <iostream>
using namespace std;

struct ListNode{
    int val;
    struct ListNode *next;
};

class Solution{
public:
    /**
     *
     * @param head ListNode类
     * @param m int整型
     * @param n int整型
     * @return ListNode类
     */
    ListNode *reverseBetween(ListNode *head, int m, int n)
    {
        // 原链表分成三个部分
        // 定位前后两个链表，之后这两个链表之间的链表进行反转操作。
        int i = 1;
        int j = 1;
        
        // 关键！！！！
        // 创建一个dummy的结点从-1开始，这是为了保证当第一个输入为1的时候程序仍能正常运行。
        // 保证dummy从头到尾没有被赋值，最后直接返回dummy的next（即head）。
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        
        // 定位三个子链表的端点。
        ListNode *first_list_end = dummy;
        ListNode *third_list_begin = dummy;
        ListNode *second_list_begin = dummy;
        ListNode *second_list_end = dummy;
        while(i<m){
            first_list_end = first_list_end->next;
            i++;
        }
        
        while(j<n+1){
            second_list_end = second_list_end->next;
            j++;
        }

        // 取出两个子链表。
        second_list_begin = first_list_end->next;
        third_list_begin = second_list_end->next;

        // 切断三个链表之间的连接。
        first_list_end->next = NULL;
        second_list_end->next = NULL;


        // 对中间的链表进行反转操作。
        // 存储一下中间链表的首节点。
        ListNode *temp = second_list_begin; 

        // 用于循环的中间变量。
        ListNode *pre = NULL;
        ListNode *next = NULL;
 
        while(second_list_begin != NULL){
            next = second_list_begin->next;
            second_list_begin->next = pre;
            pre = second_list_begin;
            second_list_begin = next;
        }

        // 最后重新链接这三个链表，注意链接时候的方向。
        first_list_end->next = second_list_end;
        temp->next = third_list_begin;
         
        return dummy->next;
    }
};