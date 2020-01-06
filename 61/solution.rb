# Definition for singly-linked list.
# class ListNode
#     attr_accessor :val, :next
#     def initialize(val)
#         @val = val
#         @next = nil
#     end
# end

# @param {ListNode} head
# @param {Integer} k
# @return {ListNode}
def rotate_right(head, k)
    return nil if head.nil?
    n, counter_ptr = 0, head
    until counter_ptr.nil?
        n += 1
        counter_ptr = counter_ptr.next
    end
    
    k %= n
    fast = slow = head
    k.times { fast = fast.next unless fast.nil? }
    return head if fast.nil?
    until fast.next.nil?
        fast, slow = fast.next, slow.next
    end
    
    fast.next = head
    fast = slow.next
    slow.next = nil
    
    fast
end
