struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return head;
        ListNode* prev = nullptr, *curr = head, *nextNode = head->next;
        ListNode* temp;
        while (nextNode != nullptr) {
            temp = nextNode;
            curr->next = prev;
            nextNode = temp->next;
            temp->next = curr;
            prev = curr;
            curr = temp;
        }
        return curr;
    }
};