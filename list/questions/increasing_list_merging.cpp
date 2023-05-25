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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        if (pHead1 == NULL){
            return pHead2;
        }   
        if (pHead2 == NULL){
            return pHead1;
        }   

        // 两个链表都不为空的情况
        // 直接选取更有更小数据的链表头作为返回链表头，接下来一次次比较并且移动指针即可。
        ListNode* temp = NULL;
        ListNode* head = NULL;
        if (pHead1->val < pHead2->val ){
            temp = pHead1;
            head = temp;
            pHead1 = pHead1->next;
        }
        else{
            temp = pHead2;
            head = temp;
            pHead2 = pHead2->next;
        }

        while (pHead1 != NULL && pHead2 != NULL)
        {
            if (pHead1->val < pHead2->val ){
            temp->next = pHead1;
            pHead1 = pHead1->next;
            temp = temp->next;
            }
            else{
            temp->next = pHead2;
            pHead2 = pHead2->next;
            temp = temp->next;
            }
        }
        // pHead1或者pHead2之中有一个到头了，直接把另一个表剩下的部分全都接过去。
        if (pHead1 == NULL){
            temp->next = pHead2;
        }
        if (pHead2 == NULL){
            temp->next = pHead1;
        }
        return head;
    }
};
