#include <iostream>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};


class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        // 看一下评论区的题解吧，主要思想就是找到两个速度不同的指针在环内相遇的结点。
        // 之后把两个指针的速度设为相同为1,一个从链表头结点出发,一个从相遇结点出发,他们再次相遇的结点即为环入口结点.
        // 评论区可以找到证明。
        
        // 先判断原链表是否存在环,用上一题的逻辑直接判断-->生死时速!两个速度不同的指针追着跑!
        ListNode *p1 = pHead;
        ListNode *p2 = pHead;

        // 原输入链表为空或者只有一个结点,直接返回NULL.
        if (pHead == NULL || pHead->next == NULL){
            return NULL;
        }

        // 调用辅助函数判断原链表是否存在环，若不存在，直接返回NULL，若存在则辅助函数返回相遇结点。
        ListNode *NodeMeet = ListExistLoop(pHead);

        // 如果原输入链表不存在环，直接返回NULL。
        if (NodeMeet == NULL){
            return NULL;
        } 

        // 头结点即为环入口的情况。
        if (NodeMeet == pHead) {
            return pHead;
        }

        // p2指针从相遇结点开始走，p1从头结点开始走。
        p2 = NodeMeet;
        while(p1){
            p1 = p1->next;
            p2 = p2->next;
            if(p1 == p2){
                return p1;
            }
        }
    }

    ListNode* ListExistLoop(ListNode* pHead) {
        // p2_速度快一点，所以之后的while循环里面要注意p2_的条件判断。
        ListNode *p1_ = pHead;
        ListNode *p2_ = pHead;

        while(p2_ != NULL && p2_->next != NULL){
            // p2_速度为p1_的两倍。
            p1_ = p1_->next;
            p2_ = p2_->next->next;
            if(p1_ == p2_){
                return p1_;
            }
        }
        // 到最后都没有找到p1_和p2_相同的结点，说明原链表不存在环，直接返回NULL。
        return NULL;
    }

};