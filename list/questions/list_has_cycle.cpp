#include <iostream>
using namespace std;


// Definition for singly-linked list.
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    bool hasCycle(ListNode *head) {
        // 双指针。
        // 小时候微机课生死时速玩过没，如果是在一个环里面的话，只要有一方的速度比另外一方快，那么肯定最后会追上对吧。
        // 而且这里定义的链表每个结点只有一个next，那么只要存在有next为NULL的结点，该链表就不带环。
        ListNode *p1 = head;
        ListNode *p2 = head;
        cout << p1 << endl;
        // 如果为空链表，那么直接返回false。
        if (p1 == NULL || p2 == NULL){
            return false;
        }
        // 还要保证p2不为NULL，这是因为p2的速度为每个循环移动2个结点，当输入的链表不存在环的时候，
        // 有可能下一次进入循环的时候p2处于倒数第二个结点，那么p2->next的确不为NULL，但是p2->next->next为NULL，这会导致循环不结束。
        while(p1->next != NULL && p2->next != NULL && p2 != NULL){
            p1 = p1->next;
            p2 = p2->next->next;
            // 两个指针速度不一样，如果存在环的话，肯定有一方会追上另一方。
            if (p1 == p2){
                return true;
            }
            // 到最后p1或者p2为NULL了跳出循环，而存在NULL说明该链表不存在环。
        }
        return false;
    }
};