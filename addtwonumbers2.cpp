
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = nullptr;
        ListNode *curr = nullptr;
        int carry = 0;
        while (l1 || l2) {
            int a = l1 ? l1->val : 0;
            int b = l2 ? l2->val : 0;
            int v = a + b + carry;
            if (v >= 10) {
                carry = 1; v -= 10;
            } else carry = 0;
            ListNode *n = new ListNode(v);
            if (curr) {
                curr->next = n;
                curr = n;
            } else {
                head = curr = n; //first time
            }
            if (l1) l1 = l1 -> next;
            if (l2) l2 = l2 -> next;
        }
        if (carry) {
            ListNode *n = new ListNode(1);
            curr->next = n;
        }
        
        return head;
    }
};
