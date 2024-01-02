
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

        // 主循环遍历链表的前半段。
        for (int i = 0 ; i < count/2; i++) {

            ListNode *p2 = head;
            // 将p2指针移动链表中当前结点的对称结点。
            for(int j = 0 ; j < count-i ; j++){
                p2 = p2->next;
            }
            // 一旦对称结点的值域不相等，直接返回false。
            if(p1->val != p2->val){
                return false;
            }
            // 移动p1指针到下一个结点。
            p1 = p1->next;
        }
        // 如果到最后循环完毕都没有返回false，则说明所有对应对称结点值域相等，原链表为回文链表。
        return true;
    }
};



// 测尼玛超时了...