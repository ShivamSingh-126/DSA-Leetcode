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
    ListNode* removeElements(ListNode* head, int val) 
    {
        
        if(head==NULL) return NULL;
        ListNode* dummy=new ListNode(0);
        dummy->next=head;

        ListNode* temp=dummy;
        while(temp->next!=NULL)
        {
            if(temp->next->val==val )
            {
                ListNode* curr=temp->next;
                temp->next=curr->next;
                delete curr;
            }
            else
            {
                temp=temp->next;
            }
        }
        return dummy->next;
        
        // Recursive Approach

        // if(head==NULL) return NULL;

        // head->next=removeElements(head->next,val);
        // if(head->val==val )
        // {
        //     ListNode* curr=head->next;
        //     delete head;
        //     return curr;
        // }
        // return head;
    }
    
};