#include <iostream>
using namespace std;

struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param pHead ListNode类 
     * @param k int整型 
     * @return ListNode类
     */
    ListNode* FindKthToTail(ListNode* pHead, int k) {
        // 先遍历一遍链表确定链表一共有几个结点，直接拿总结点树减去k即可以计算出正向需要遍历的次数。
        int count = 0;
        ListNode *itr = pHead; 
        ListNode *newHead = pHead;
        while(itr != NULL){
            count++;
            itr = itr->next;
        }

        // 如果当前链表总结点数小于k，则直接返回一个长度为0的链表（NULL）。
        if (count < k){
            return NULL;
        }

        // 开始遍历。
        for (int i= 0 ; i<count-k ; i++){
            newHead = newHead->next;
        }
        return newHead;
    }
};