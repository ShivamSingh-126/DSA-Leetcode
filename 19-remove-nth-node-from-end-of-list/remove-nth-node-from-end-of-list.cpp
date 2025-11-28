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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        /*
        // Brute Force Approach
        if (head == NULL || head->next == NULL) {
            return NULL;
        }
        int count = 0, rem = 0;
        ListNode* temp = head;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        ListNode* pre = NULL;
        ListNode* curr = head;
        if (count - n == 0)
            return head->next;
        while (rem != count - n) {
            rem++;
            pre = curr;
            curr = curr->next;
        }
        pre->next = curr->next;
        delete curr;
        return head;
        */
        // Optimal Approach

        ListNode* fast = head;
        ListNode* slow = head;

        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }
        if (fast == NULL)
            return head->next;
        while (fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* delnode = slow->next;
        slow->next = slow->next->next;
        delete delnode;
        return head;
    }
};