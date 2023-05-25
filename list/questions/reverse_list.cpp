#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL)
    {
    }
};
class Solution
{
public:
    ListNode *ReverseList(ListNode *pHead)
    {
        if (pHead == NULL || pHead->next == NULL)
        {
            return pHead;
        }
        ListNode *previous = NULL;
        ListNode *next = NULL;
        while (pHead != NULL)
        {
            next = pHead->next;
            pHead->next = previous;
            previous = pHead;
            pHead = next;
        }
        return previous;
    }
};
