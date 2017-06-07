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
    ListNode* addNode(ListNode* ln, int n) {
       
        ListNode * cur = ln;
        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = new ListNode(n);
        return ln;
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *newList = new ListNode(0);
        ListNode *L1 = l1;
        ListNode *L2 = l2;
        while(L1!=NULL || L2!=NULL){
            if(L1 == NULL) {
                addNode(newList, L2->val);
                L2=L2->next;
            }
            else if(L2 == NULL) {
                addNode(newList, L1->val);
                L1=L1->next;
            }
            else if(L1->val <= L2->val){
                addNode(newList, L1->val);
                L1=L1->next;
            }
            else {
                addNode(newList, L2->val);
                L2=L2->next;
            }
           
            
        }
        return newList->next;
    }
    
};
