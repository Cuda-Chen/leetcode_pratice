/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if(head == null) {
            return null;
        }
        int n = 0;
        ListNode counterPtr = head;
        while(counterPtr != null) {
            n++;
            counterPtr = counterPtr.next;
        }
        
        k %= n;
        ListNode fast = head, slow = head;
        for(int i = 0; i < k; i++) {
            if(fast != null) {
                fast = fast.next;
            }
        }
        if(fast == null) {
            return head;
        }
        while(fast.next != null) {
            fast = fast.next;
            slow = slow.next;
        }
        
        fast.next = head;
        fast = slow.next;
        slow.next = null;
        
        return fast;
    }
}
