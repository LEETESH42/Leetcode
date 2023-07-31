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
        if(head->next==NULL && n==1){
            return NULL;
        }
        int num=0;

        ListNode* node=head;
        while(node!=NULL){
            num++;
            node=node->next;
        }
        int l=num-n;
        if(l==0){
            return head->next;
        }
        ListNode* t1=head;

        int pos=1;
        while(pos<l){
            t1=t1->next;
            pos++;
        }
        if(t1!=NULL){
            t1->next=t1->next->next;
        }
        return head;
    }
};