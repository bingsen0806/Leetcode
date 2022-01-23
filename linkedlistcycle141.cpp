
//Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr) return false;
        ListNode *tortoise = head, *rabbit = head;
        while (tortoise != nullptr) {
            tortoise = tortoise -> next;
            if (rabbit == nullptr || rabbit->next == nullptr) return false;
            rabbit = rabbit -> next -> next;
            if (tortoise == rabbit) {
                return true;
            }
        }
        return false;
        
    }
};