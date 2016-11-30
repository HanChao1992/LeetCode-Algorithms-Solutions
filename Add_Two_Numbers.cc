class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        struct ListNode* head = new ListNode(0);
        struct ListNode* cur = head;
        int next = 0;

        while (l1 != NULL || l2 != NULL) {
            int num1, num2;
            if (l1 == NULL) {
                num1 = 0;
            }
            else {
                num1 = l1->val;
            }
            if (l2 == NULL) {
                num2 = 0;
            }
            else {
                num2 = l2->val;
            }
            int curr = num1 + num2 + next;
            next = 0;
            if (curr >= 10) {
                next = 1;
                curr = curr - 10;
            }
            cur->next = new ListNode(curr);
            cur = cur->next;
            if (l1 != NULL) {
                l1 = l1->next;
            }
            if (l2 != NULL) {
                l2 = l2->next;
            }
        }
        if (next == 1) {
            cur->next = new ListNode(1);
            cur = cur->next;
        }
        return head->next;
    }
};
