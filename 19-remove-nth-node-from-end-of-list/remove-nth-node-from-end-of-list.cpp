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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        if(head==NULL ||head->next==NULL)
        {
            return NULL;
        }
        int count=0,rem=0;
        ListNode *temp=head;
        while(temp!=NULL)
        {
            count++;
            temp=temp->next;
        }
        ListNode* pre=NULL;
        ListNode* curr=head;
        if(count-n==0) return head->next;
        while(rem!=count-n)
        {
            rem++;
            pre=curr;
            curr=curr->next;
        }
        pre->next=curr->next;
        delete curr;
        return head;
    }
};