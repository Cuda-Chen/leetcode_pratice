# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        if not head:
            return None
        n, counterPtr = 0, head
        while counterPtr:
            n += 1
            counterPtr = counterPtr.next
            
        k %= n
        fast = slow = head
        for i in range(k):
            if fast:
                fast = fast.next
        if not fast:
            return head
        while fast.next:
            fast, slow = fast.next, slow.next
        
        fast.next = head
        fast = slow.next
        slow.next = None
        
        return fast
