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
    ListNode* mergeNodes(ListNode* head) 
    {
        ListNode* change=head->next;
        ListNode* nextnode=change;
        int sum=0;
        while(nextnode!=NULL)
        {
            sum=0;
            while(nextnode->val != 0)
            {   // find sum until 0
                sum+=nextnode->val;
                nextnode=nextnode->next;
            }
            // Assign sum to node value
            change->val=sum;
            // Move nextnode to first non zero value
            nextnode=nextnode->next;
            change->next=nextnode;  // move change forward
            change=change->next;
        }
        return head->next;  // skip first 0
    }
};