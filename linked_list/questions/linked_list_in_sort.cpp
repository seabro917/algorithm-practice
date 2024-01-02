#include <iostream>
#include <vector>
#include <sort>
using namespace std;

struct ListNode{
    int val;
    struct ListNode *next;
};

class Solution{
public:
    /**
     *
     * @param head ListNode类 the head node
     * @return ListNode类
     */
    ListNode *sortInList(ListNode *head){
        // 先遍历一遍链表，把所有结点的数据放入一个vector容器内，在容器内进行排序，最后构造新链表。
        
        // 先遍历一遍链表找到总共的结点数。
        int count = 0;
        ListNode *itr = head;
        while(itr != NULL){
            itr = itr->next;
            count++;
        }
        
        // 将链表的所有结点数据放入容器内.
        std::vector<int> vec_list;
        ListNode *ptr = head;
        while(ptr != NULL){
            vec_list.push_back(ptr->val);
            ptr = ptr->next;
        }

        // 对容器内元素进行排序。
        std::sort(vec_list.begin(),vec_list.end());

        // 遍历vector，依次取出数据，构造新链表。
        ListNode *nHead = new ListNode(0);
        ListNode *itr_2 = nHead;
        for (int j = 0 ; j < count ; j++){
            itr_2->next = new ListNode(vec_list[j]);
            itr_2 = itr_2->next;
        }
        return nHead->next;
    }
};