
// Definition for singly-linked list.
 class ListNode {
     int val;
     ListNode next;
     ListNode() {}
     ListNode(int val) { this.val = val; }
     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 }
 

// Remove Nth Node From End of List
// LinkedList, Fast Slow Pointer, Two Pointers
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode front = head;
        ListNode curr = null;
        for (int i = 0; i < n; i++) {
            front = front.next;
        }
        while (front != null) {
            front = front.next;
            if (curr == null) curr = head;
            else curr = curr.next;
        }
        if (curr == null) {  //to prevent edge case where n == size of list
            return head.next;
        }
        curr.next = curr.next.next;
        return head;
    }
    
}
