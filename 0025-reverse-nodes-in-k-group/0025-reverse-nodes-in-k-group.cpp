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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL){
            return NULL;
        }

        ListNode* nx=NULL;
        ListNode* curr=head;
        ListNode* prev=NULL;

        int pos=1;
        ListNode* t1=head;
        while(pos<k && t1!=NULL){
            t1=t1->next;
            pos++;
        }
        if(t1==NULL){
            return head;
        }
        pos=0;
        while(curr!=NULL && pos<k){
            nx=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nx;
            pos++;
        }
        if(nx!=NULL){
            head->next=reverseKGroup(nx,k);
        }
        return prev;
    }
};