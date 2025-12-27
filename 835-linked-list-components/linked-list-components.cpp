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
    int numComponents(ListNode* head, vector<int>& nums) 
    {
        set<int>st;
        for(auto it:nums)
        st.insert(it);

        int total=0;
        bool flag=false;
        while(head != NULL)
        {
            int val=head->val;
            if(st.count(val) && flag==false)
            {
                flag=true;
                total++;
            }
            else if(st.count(val)==0 && flag==true)  flag=false;

            head=head->next;
        }
        return total;
    }
};