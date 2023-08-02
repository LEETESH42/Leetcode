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

    ListNode* reve(ListNode* head){
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* Next=head;

        while(curr){
            Next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=Next;
        }
        return prev;
    }

    ListNode* reverseBetween(ListNode* head, int l, int r) {
        ListNode* a=NULL;
        ListNode* b=NULL;
        ListNode* c=NULL;
        ListNode* d=NULL;
        ListNode* temp=head;
        int n=1;

        while(temp){
            if(n==l-1){
                a=temp;
            }
            if(n==l){
                b=temp;
            }
            if(n==r){
                c=temp;
            }
            if(n==r+1){
                d=temp;
            }
            temp=temp->next;
            n++;
        }

        if(a){
            a->next=NULL;
        }
        c->next=NULL;
        c=reve(b);
        if(a){
            a->next=c;
        }
        b->next=d;
        if(a){
            return head;
        }
        return c;
    }
};