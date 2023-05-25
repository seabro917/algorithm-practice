#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
};

class Solution
{
public:
    /**
     *
     * @param head ListNode类
     * @param k int整型
     * @return ListNode类
     */
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        // 把“将给定链表每K个结点进行一次翻转”的问题拆分成“每次给定固定的端点，对当前链表的给定范围的子链表进行翻转”。

        // 创建dummy结点。
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;

  /*       // 查找整个链表一共存在几个结点。
        int total = 0;
        ListNode *counter = dummy;
        while (counter->next != NULL)
        {
            counter = counter->next;
            total++;
        }
        
        // quotient代表一共有几个组（总共需要翻转几次）。
        int quotient = total / k;
        int remainder = total % k;
        
        // 用于存放需要翻转的子链表端点的数组 --> 必须要使用动态内存分配因为数组的长度是在程序运行时才能被确定。
        int **bound = new int*[quotient];
        for(int i=0 ; i<quotient ; i++){
            bound[i]=new int[2];
        }
 */
        int count = 0;
        // 用itr来遍历链表，保证原头结点不会丢失。
        ListNode *itr = dummy;
        // 事实上这个left_bound是前面链表的结束端点，需要翻转的子链表的头结点是left_bound->next。
        ListNode *left_bound = dummy;
        ListNode *right_bound = NULL; 
        while(itr->next != NULL){
            itr = itr->next;
            // 每次遍历移动更新当前的右端结点。
            right_bound = itr;
            count++;

            // 当前计数到达了需要翻转的子链表表尾。
            if(count == k){
                // 翻转当前子链表。
                reverseBetween(dummy->next, left_bound, right_bound);
                // 重新赋予新的左侧端点并且重置count。
                left_bound = itr;
                count = 0;
            }
        }
        return dummy->next;
    }


    // 将给定区间内的子链表进行翻转的helper函数。
    ListNode *reverseBetween(ListNode *head, ListNode *p1, ListNode *p2)
    {
        // 根据给定的结点，对原链表进行局部翻转。

        // 关键！！！！
        // 创建一个dummy的结点从-1开始，这是为了保证当第一个输入为1的时候程序仍能正常运行。
        // 保证dummy从头到尾没有被赋值，最后直接返回dummy的next（即head）。
        ListNode *dummy_ = new ListNode(-1);
        dummy_->next = head;
        
        // 定位三个子链表的端点，取出三个子链表。
        ListNode *first_list_end = p1;
        ListNode *third_list_begin = p2->next;
        ListNode *second_list_begin = p1->next;
        ListNode *second_list_end = p2;

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
         
        return dummy_->next;
    }


    // // 遍历所有组
    // for (i=0 ; i < quotient ; i++){
    //     // 找到当前组的头结点。
    //     ListNode *current_head = dummy->next;
    //     ListNode *current_head = 
    // }

    // // 找到当前子链表的头结点。
    // ListNode *find_current_header(ListNode *head, int group_number, int k){
    //     for (j = 0 ; j < group_number*k ; j++){
    //         head = head->next;
    //     }   
    //     return head;
    // }

    // ListNode *reverseList(ListNode *head){
    //     ListNode *next = NULL;
    //     ListNode *previous = NULL;
    //     while (head != NULL)
    //     {
    //         next = head->next;
    //         head->next = previous;
    //         previous = head;
    //         head = next;
    //     }
    //     return head;
    // }
};