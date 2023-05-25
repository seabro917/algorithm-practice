#include <iostream>
#include <map>
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
        // 原给定链表已排序。
        // ListNode *dummy = new ListNode(-1);
        // dummy->next = head;
        ListNode *itr = head;
        ListNode *newHead = new ListNode(-1);
        ListNode *newHead_it = new ListNode(-1);
        newHead->next = newHead_it;
        // 使用Map容器，遍历一遍原链表，将所有结点的数据域存入Map内。
        // 将链表结点的数据存为key，value存为该数据出现的次数，遍历结束之后判断每个key对应的value值是否大于1，若大于1则不放入要返回的链表内。
        std::map<int, int> val_map;

        // 特殊情况单独考虑: 链表为空或者只有一个结点。
        if (head == NULL || head->next == NULL){
            return head;
        }

        // 遍历一遍原链表，将所有结点的数据域存入Map内。
        while(itr != NULL){
            // 将当前结点的val压入Map。
            // 如果当前遍历到的数据在Map中不存在，则创建对应键值对。
            if (val_map.count(itr->val) == 0){
                val_map.insert(pair <int, int> (itr->val, 1));
            }
            // 若当前遍历结点的数据已经存在于Map中，则对应的值+1。
            else{
                std::map<int, int>::iterator itr_find = val_map.find(itr->val);
                // second代表的就是value值，first代表的是key的值。(注意要用迭代器)
                itr_find->second = itr_find->second + 1;
            }
            itr = itr->next;
        }

        // 利用Map的值域判断哪些结点是多次出现的。
        // 利用Map自带的迭代器进行遍历Map。
        for (std::map<int, int>::iterator it = val_map.begin() ; it != val_map.end() ; it++){
            // 如果当前这个元素只出现过一次，那么把它放在新的要返回的链表里面。
            // Map中的键是已经排序好的，所以可以直接遍历构造新的链表结点。
            if(it->second == 1){
                newHead_it->next = new ListNode(it->first);
                newHead_it = newHead_it->next;
            }
        }
        return newHead->next->next;
    }
};