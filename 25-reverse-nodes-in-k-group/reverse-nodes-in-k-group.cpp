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

#define null NULL
#define node ListNode
#define data val

void reverse(node* head,int times)
{
    node* curr=head;
    node*prev=null;

    while(times--)
    {
        node* nex=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nex;
    }
    return;
}
/*
    ListNode* reverselinkedlist(ListNode* temp) {
        
        ListNode* pre = NULL;
        ListNode* curr = temp;
        while (curr != NULL) {
            ListNode* newnode = curr->next;
            curr->next = pre;
            pre = curr;
            curr = newnode;
        }
        return pre;
    }
    ListNode* getknode(ListNode* temp, int k) {
        k -= 1;
        while (temp != NULL && k > 0) {
            k--;
            temp = temp->next;
        }
        return temp;
    }
    */
    ListNode* reverseKGroup(ListNode* head, int k) {
    /*
        if (k == 1 || head == NULL)
            return head;
        ListNode* temp = head;
        ListNode* prenode = NULL;
        while (temp != NULL) {
            ListNode* knode = getknode(temp, k);
            if (knode == NULL) {
                if (prenode)
                    prenode->next = temp;
                break;
            }
            ListNode* nextnode = knode->next;
            knode->next = NULL;
            ListNode* newHead = reverselinkedlist(temp);

            if (temp == head) {
                head = newHead;
            } else {
                prenode->next = newHead;
            }
            prenode = temp;
            temp = nextnode;
        }
        return head;
        */

        if(head == null)
        return null;

        node* left=head;
        node* right;
        node* res=null;
        node* prevleft=null;
        int size=k;
        while(true)
        {
            right=left;
            for(int i=0;i<size-1;i++)
            {
                if(right==null)
                break;
                right=right->next;
            }
            if(right)
            {
                node* nexleft=right->next;
                reverse(left,size);
                if(prevleft)
                {
                    prevleft->next=right;
                }
                prevleft=left;
                if(res==null)
                res=right;

                left=nexleft;
            }
            else
            {
                if(prevleft)
                prevleft->next=left;
                if(res==null)
                res=left;

                break;
            }
        }
        return res;
    }
};