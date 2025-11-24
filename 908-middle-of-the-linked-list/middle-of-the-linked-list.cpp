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
    ListNode* middleNode(ListNode* head) {
        ListNode* temp = head;
        int count = 0;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        ListNode* pre = NULL;
        ListNode* curr = head;
        int i = 1;
        if (count % 2 != 0) {
            while (i != count / 2 + 1) {
                pre = curr;
                curr = curr->next;
                i++;
            }
            return curr;
        } else {
            while (i != count / 2 + 1) {
                pre = curr;
                curr = curr->next;
                i++;
            }
            return curr;
        }
    }
};