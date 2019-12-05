# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        dummy = ListNode(0)
        result = dummy
        Sum = 0
        
        while l1 or l2:
            if l1:
                Sum += l1.val
                l1 = l1.next
            if l2:
                Sum += l2.val
                l2 = l2.next
            result.next = ListNode(Sum % 10)
            result = result.next
            Sum //= 10
            
        if Sum > 0:
            result.next = ListNode(Sum);
            
        return dummy.next
        
