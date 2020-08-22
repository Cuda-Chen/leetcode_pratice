class MyLinkedList
    class Node
        attr_accessor :next
        attr_reader :val
        
        def initialize(value)
            @val = value
            @next = nil
        end
    end
=begin
    Initialize your data structure here.
=end
    def initialize()
        @head = nil
        @tail = nil
        @size = 0
    end


=begin
    Get the value of the index-th node in the linked list. If the index is invalid, return -1.
    :type index: Integer
    :rtype: Integer
=end
    def get(index)
        return -1 if index >= @size
        
        iter = @head
        while index > 0
            iter = iter.next
            index -= 1
        end
        
        iter.val
    end


=begin
    Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
    :type val: Integer
    :rtype: Void
=end
    def add_at_head(val)
        temp = Node.new(val)
        if @size == 0
            @head = @tail = temp
        else
            temp.next = @head
            @head = temp
        end
        @size += 1
    end


=begin
    Append a node of value val to the last element of the linked list.
    :type val: Integer
    :rtype: Void
=end
    def add_at_tail(val)
        temp = Node.new(val)
        if @size == 0
            @head = @tail = temp
        else
            @tail.next = temp
            @tail = temp
        end
        @size += 1
    end


=begin
    Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted.
    :type index: Integer
    :type val: Integer
    :rtype: Void
=end
    def add_at_index(index, val)
        if index > @size 
            return
        elsif index == 0
            add_at_head(val)
            return
        elsif index == @size
            add_at_tail(val)
            return
        end
        
        iter = @head
        while index > 1
            iter = iter.next
            index -= 1
        end
        temp = iter.next
        iter.next = Node.new(val)
        iter.next.next = temp
        @size += 1
    end


=begin
    Delete the index-th node in the linked list, if the index is valid.
    :type index: Integer
    :rtype: Void
=end
    def delete_at_index(index)
        if index < @size
            iter = @head
            if index == 0
                @head = @head.next
            else
                while index > 1
                    iter = iter.next
                    index -= 1
                end
                temp = iter.next
                iter.next = iter.next.next
                if iter.next == nil
                    @tail = iter
                end
            end
            @size -= 1
        end
    end


end

# Your MyLinkedList object will be instantiated and called as such:
# obj = MyLinkedList.new()
# param_1 = obj.get(index)
# obj.add_at_head(val)
# obj.add_at_tail(val)
# obj.add_at_index(index, val)
# obj.delete_at_index(index)
