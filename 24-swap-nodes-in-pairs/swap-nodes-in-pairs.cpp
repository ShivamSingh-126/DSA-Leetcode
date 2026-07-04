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

    ListNode* swapPairs(ListNode* head) 
    {
        /*
        if(head==NULL || head->next == NULL)  return head;

        ListNode* temp=head->next;
        head->next=swapPairs(head->next->next);
        temp->next=head;

        return temp;
        */

        if(head == null)
        return null;

        node* left=head;
        node* right;
        node* res=null;
        node* prevleft=null;
        int size=2;
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