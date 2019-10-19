# Definition for singly-linked list.
# # class ListNode
# #     attr_accessor :val, :next
# #     def initialize(val)
# #         @val = val
# #         @next = nil
# #     end
# # end
#
# # @param {ListNode} l1
# # @param {ListNode} l2
# # @return {ListNode}
def add_two_numbers(l1, l2)
    dummyHead = ListNode.new(0)
    current = dummyHead
    carry = 0
    
    while l1 or l2
        val1 = l1 ? l1.val : 0
        val2 = l2 ? l2.val : 0
        sum = carry + val1 + val2
        carry = sum / 10
        current.next = ListNode.new(sum % 10)
        current = current.next
        l1 = l1 ? l1.next : nil
        l2 = l2 ? l2.next : nil
    end
    
    if carry > 0
        current.next = ListNode.new(carry)
    end
    
    return dummyHead.next
end
