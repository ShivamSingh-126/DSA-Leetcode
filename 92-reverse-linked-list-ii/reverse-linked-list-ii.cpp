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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* leftpre = &dummy;
        ListNode* curr = head;
        for (int i = 0; i < left - 1; i++) {
            leftpre = leftpre->next;
            curr = curr->next;
        }

        ListNode* slh = curr;
        ListNode* prev = NULL;
        for (int i = 0; i <= right - left; i++) {
            ListNode* nextnode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextnode;
        }
        leftpre->next = prev;
        slh->next = curr;

        return dummy.next;
    }
};