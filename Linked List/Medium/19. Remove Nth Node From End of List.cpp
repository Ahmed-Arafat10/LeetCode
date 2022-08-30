/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    int count(ListNode* head)
    {
        int cnt = 0;
        while(head)
        {
            cnt++;
            head = head->next;
        }
        return cnt;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        int sz = count(head);
        ListNode *new_head = NULL;
        new_head = head;
        int dis = sz - n, cnt =0;
        //cout<<sz;
        while(head)
        {
            cnt++;
            if(!dis)
            {
                ListNode *temp =  new_head;
                new_head = new_head->next;
                delete temp;
                break;
            }
            if(cnt == dis)
            {
                ListNode *temp =  head->next;
                head->next =temp->next;
                delete temp;
                break;
            }
            head = head->next;
        }
        return new_head;
    }
};
