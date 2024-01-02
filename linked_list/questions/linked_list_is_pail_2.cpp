
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
     * @param head ListNode类 the head
     * @return bool布尔型
     */
    bool isPail(ListNode *head){
        // 两个while循环依次比较对应对折结点的数据是否相等。
        ListNode *p1 = head;
        ListNode *p2 = head;
        ListNode *itr = head;
        // 单结点链表，直接返回true。
        if (head->next == NULL){
            return true;
        }
        
        // 找到该链表一共多少个结点。
        int count = 0;
        while (itr->next != NULL) {
            itr = itr->next;
            count++;
        }

        // 判断奇数个还是偶数个结点。
        int k = 0;
        // 偶数个结点。
        if ( (count % 2) == 0){
            k = 0;
        }
        else{
            k = 1;
        }

        // 将后半段链表翻转，之后与前半段链表的结点依次比较。
        // 找到后半段链表的表头。
        for (int i = 0 ; i < count/2; i++) {
            p2 = p2->next;
        }
        if(k == 0){
            p2 = p2->next;
        }else{
            p2 = p2->next->next;
        }

        // 反转后半段链表。
        ListNode *pre = NULL;
        ListNode *next = NULL;
        while(p2 != NULL){
            next = p2->next;
            p2->next = pre;
            pre = p2;
            p2 = next;
        } // 注意到这里为止pre为新的表头，因为p2在循环结束之后已经变成NULL了。
        
        // 开始比较两个子链表，一旦发现对应结点值域不同，直接返回false，若到循环结束还没找到值不相等的对应结点，则返回true。
        for (int j = 0 ; j < count/2; j++) {
            if(p1->val != pre->val){
                return false;
            }
            p1 = p1->next;
            pre = pre->next;
        }
        return true;
    }
};