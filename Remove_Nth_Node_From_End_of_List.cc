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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode * cur = head;
        while(cur != NULL) {
            cur = cur->next;
            count++;
        }
        int nth = count - n;
        if(nth == 0) {
            return head->next;
        }
        cur = head;
        for(int i = 1; i < nth; i++) {
            cur = cur->next;
        }
        if(cur == NULL || cur->next == NULL) {
            return head;
        }
        ListNode * nexto = cur->next->next;
    
        free(cur->next);
        cur->next = nexto;
        return head;
    }
};
