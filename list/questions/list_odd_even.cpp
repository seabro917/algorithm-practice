
#include <iostream>
using namespace std;

struct ListNode{
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
     * @param head ListNode类
     * @return ListNode类
     */
    ListNode* oddEvenList(ListNode* head) {
        ListNode* itr_1 = new ListNode(-1);
        ListNode* itr_2 = new ListNode(-1);
        ListNode* itr_count = head;
        ListNode* itr_main = head;
        ListNode* head_1 = itr_1;
        ListNode* head_2 = itr_2;

        if (head== NULL) {
            return NULL;
        }

        if (head->next == NULL) {
            return head;
        }

        // 找到原链表总共结点数目。
        int count = 0;
        while (itr_count != NULL) {
            itr_count = itr_count->next;
            count++;
        }

        // 创建两个子链表，一个存放奇数位置结点，一个存放偶数位置结点，最后将两个子链表连接合并。
        for (int i = 0 ; i < count ; i++) {
            // 奇数位置结点。
            if ( (i % 2) == 0) {
                itr_1->next = new ListNode(itr_main->val);
                itr_1 = itr_1->next;
            } else {
                itr_2->next = new ListNode(itr_main->val);
                itr_2 = itr_2->next;
            }
            itr_main = itr_main->next;
        }

        // 遍历结束后连接两个子链表。
        itr_1->next = head_2->next;

        return head_1->next;
    }
};