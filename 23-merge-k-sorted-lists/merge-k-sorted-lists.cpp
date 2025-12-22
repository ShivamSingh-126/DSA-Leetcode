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
ListNode* mergetwosortedlist(ListNode* l1,ListNode* l2)
    {
        if(l1==NULL)  return l2;
        if(l2==NULL)  return l1;

        if(l1->val <= l2->val)
        {
            l1->next= mergetwosortedlist(l1->next,l2);
            return l1;
        }
        if(l1->val >= l2->val)
        {
            l2->next= mergetwosortedlist(l2->next,l1);
            return l2;
        }
        return NULL;
    }

    ListNode* partitionmerge(int start,int end,vector<ListNode*>&list) 
    {
        if(start > end)  return NULL;
        if(start==end)  return list[start];

        int mid=start+(end-start)/2;

        ListNode* Ln1=partitionmerge(start,mid,list);
        ListNode* Ln2=partitionmerge(mid+1,end,list);

        return mergetwosortedlist(Ln1,Ln2);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        int count=lists.size();

        if(count==0) return NULL;

        return partitionmerge(0,count-1,lists);
    }
};