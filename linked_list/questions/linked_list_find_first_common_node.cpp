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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        // 如果输入的两个链表存在图示的第一个公共节点，那么就让长的链表先走两个链表结点数目差值的步数，之后两个链表再一起走，肯定会一起走到第一个公共结点。
        ListNode *p1 = pHead1;
        ListNode *p2 = pHead2;
        ListNode *itr_1 = pHead1;
        ListNode *itr_2 = pHead2;

        if(p1 == NULL || p2 == NULL){
            return NULL;
        }

        // 先分别遍历一次两个链表，计算两个链表的结点数目。
        int count_1 = 0;
        int count_2 = 0;
        while(p1 != NULL){
            p1 = p1->next;
            count_1++;
        }
        while(p2 != NULL){
            p2 = p2->next;
            count_2++;
        }

        // 长度长的链表先走两个链表结点数目差值的步数。
        // 两个链表要是长度相等则不进入该判断，直接开始走。
        if(count_1 > count_2){
            for (int i = 0 ; i < count_1-count_2 ; i++){
                itr_1 = itr_1->next;
            }
        }
        else if(count_1 < count_2){
            for (int i = 0 ; i < count_2-count_1 ; i++){
                itr_2 = itr_2->next;
            }
        }

        // 长的链表先走完差值之后，两个链表一起走，看是否能找到相同的结点，第一个相同的结点就是要返回的结点。
        // 如果到最后都没找到，则返回NULL。
        while(itr_1 != NULL && itr_2 != NULL){
            if(itr_1 == itr_2){
                return itr_1;
            }
            itr_1 = itr_1->next;
			itr_2 = itr_2->next;
        }
        return NULL;
    }
};
