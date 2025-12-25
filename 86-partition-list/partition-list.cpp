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
    ListNode* partition(ListNode* head, int x) 
    {
        ListNode* small=new ListNode(0);
        ListNode* large=new ListNode(0);
        ListNode* smallp=small;
        ListNode* largep=large;
        ListNode* temp=head;
        while(temp != NULL)
        {
            if(temp->val < x)
            {
                smallp->next=temp;
                smallp=smallp->next;
                temp=temp->next;
            }
            else
            {
                largep->next=temp;
                largep=largep->next;
                temp=temp->next;
            }
        }
        smallp->next=large->next;
        largep->next=NULL;
        ListNode* result = small->next;
        delete small;
        delete large;
        return result;
    }
};