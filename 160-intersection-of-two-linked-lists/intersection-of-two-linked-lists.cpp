/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        // brute Force Approach
        // if (!headA || !headB)
        //     return NULL;

        // ListNode* tempA = headA;
        // ListNode* tempB = headB;
        // while (tempA != tempB) {
        //     tempA = (tempA == NULL) ? headB : tempA->next;
        //     tempB = (tempB == NULL) ? headA : tempB->next;
        // }
        // return tempA;

        // Hashing Method
        ListNode* temp;
        map<ListNode*, int> mpp;

        temp = headA;
        while (temp != NULL) {
            mpp[temp] = 1;
            temp = temp->next;
        }
        temp = headB;
        while (temp != NULL) {
            if (mpp.find(temp) != mpp.end())
                return temp;
            temp = temp->next;
        }
        return NULL;
    }
};