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
    ListNode* deleteDuplicates(ListNode* head) 
    {
        // if (!head || !head->next) return head;
        ListNode temp(0);
        temp.next = head;
        ListNode* pre=&temp;
        ListNode* curr=head;
        int count=0;
        while(curr!=NULL)
        {
            count=0;
            while(curr->next !=NULL && curr->val == curr->next->val)
            {
                count=1;
                ListNode* dummy=curr;
                curr=curr->next;
                delete dummy;
            }
            if(count==1)
            {
                ListNode* dummy=curr;
                curr=curr->next;
                delete dummy;
                pre->next=curr;
            }
            else
            {
               pre=curr;
               curr=curr->next;
            }
        }
        return temp.next;
    }
};