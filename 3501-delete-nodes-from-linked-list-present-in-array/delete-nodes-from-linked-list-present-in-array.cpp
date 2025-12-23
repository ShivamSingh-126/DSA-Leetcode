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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) 
    {
        unordered_set<int> st(nums.begin(), nums.end());

        ListNode dup(0);
        dup.next =head;

        ListNode* left = &dup;
        ListNode* temp = head;
        while(temp != NULL)
        {
            if(st.count(temp->val))
            {
                left->next=temp->next;
                temp=left->next;
            }
            else
            {
                left=temp;
                temp=temp->next;
            }
        }
        return dup.next;
    }
};