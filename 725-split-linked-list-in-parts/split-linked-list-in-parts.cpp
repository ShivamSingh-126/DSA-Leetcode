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
    vector<ListNode*> splitListToParts(ListNode* head, int k) 
    {
        ListNode* temp=head;
        int size=0;
        while(temp != NULL)
        {
            size++;
            temp=temp->next;
        }
        temp=head;
        vector<ListNode*> res(k, nullptr);
        int big=size/k;
        int atleast=size % k;
        for(int i=0;i<k;i++)
        {
            if(temp==NULL) break;
            ListNode* cur=temp;
            ListNode* prev=NULL;
            int len=0;
            while(temp != NULL && len < big)
            {
                prev=temp;
                temp=temp->next;
                len++;
            }
            if(atleast > 0)
            {
                prev=temp;
                temp=temp->next;
                atleast--;
            }
           if (prev != NULL)
            prev->next = NULL;
            
            res[i]=cur;
        }
        return res;
    }
};