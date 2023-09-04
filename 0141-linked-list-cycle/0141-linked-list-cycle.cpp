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
    bool hasCycle(ListNode *head) {
        ListNode* quick = head;
        ListNode* slo = head;

        while (quick != nullptr && quick->next != nullptr) {
            quick = quick->next->next;
            slo = slo->next;

            if (quick == slo) {
                return true;
            }
        }

        return false;        
    }
};