#include <iostream>
using namespace std;

struct ListNode {
 	int val;
 	struct ListNode *next;
};


class Solution {
public:
    /**
     * 
     * @param head ListNode类 
     * @return ListNode类
     */
    ListNode* deleteDuplicates(ListNode* head) {
        // 原输入链表已经保证是一个已排序的链表。
        
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *itr = head;
        ListNode *next = head;
        
        // 链表结尾有两种可能。
        while(itr->next != NULL && itr != NULL){
            next = itr->next;
            
            // 如果当前结点和下一个结点的数据值一样，删除当前结点。
            if (itr->val == next->val){
                itr->next = next->next;
                // 这里的continue是为了处理三个或者三个以上具有相同数据的结点。
                // 如果没有的这句的话，下面itr = itr->next语句会导致连续的第三个相同数据被跳过处理。
                continue;
            }
            itr = itr->next;
        }
        cout << head << endl;
        return head;
    }
};