struct ListNode
{
    int val;
    struct ListNode *next;
};

class Solution
{
public:
    /**
     *
     * @param head ListNode类
     * @param n int整型
     * @return ListNode类
     */
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        // 和返回倒数第n个链表结点的思维方式一样，先定位，再删除。
        // 题干已经保证n是有效的，即不存在n大于链表总结点数的情况。

        int count = 0;
        ListNode *itr = head;
        ListNode *newHead = head;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;

        // 遍历一遍链表，确定该链表的总结点数目。
        while (itr != NULL)
        {
            count++;
            itr = itr->next;
        }

        // 如果count=n直接删掉头结点。
        if (count == n){
            return dummy->next->next;
        }   

        // 定位到要被删除的结点前一个结点，保存一下。
        ListNode *pre = head;
        for (int i = 0 ; i < count-n-1 ; i++){
            pre = pre->next;
        }

        // 被删除结点的后一个结点。
        ListNode *next_next = pre->next->next;
        pre->next = next_next;
        return dummy->next;
    }
};