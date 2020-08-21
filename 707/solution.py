class Node:
    def __init__(self, value):
        self.val = value
        self.next = None

class MyLinkedList:
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.head = None
        self.tail = None
        self.size = 0

    def get(self, index: int) -> int:
        """
        Get the value of the index-th node in the linked list. If the index is invalid, return -1.
        """
        if index >= self.size:
            return -1
        
        iterator = self.head
        while index > 0:
            iterator = iterator.next
            index -= 1
        return iterator.val

    def addAtHead(self, val: int) -> None:
        """
        Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
        """
        temp = Node(val)
        if self.size == 0:
            self.head = self.tail = temp
        else:
            temp.next = self.head
            self.head = temp
        self.size += 1

    def addAtTail(self, val: int) -> None:
        """
        Append a node of value val to the last element of the linked list.
        """
        temp = Node(val)
        if self.size == 0:
            self.head = self.tail = temp
        else:
            self.tail.next = temp
            self.tail = temp
        self.size += 1

    def addAtIndex(self, index: int, val: int) -> None:
        """
        Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted.
        """
        if index > self.size:
            return
        elif index == 0:
            self.addAtHead(val)
            return
        elif index == self.size:
            self.addAtTail(val)
            return
        
        iterator = self.head
        while index > 1:
            iterator = iterator.next
            index -= 1
        temp = iterator.next
        iterator.next = Node(val)
        iterator.next.next = temp
        self.size += 1

    def deleteAtIndex(self, index: int) -> None:
        """
        Delete the index-th node in the linked list, if the index is valid.
        """
        if index < self.size:
            iterator = self.head
            if index == 0:
                self.head = self.head.next
                del iterator
            else:
                while index > 1:
                    iterator = iterator.next
                    index -= 1
                temp = iterator.next
                iterator.next = iterator.next.next
                del temp
                if not iterator.next:
                    self.tail = iterator
            self.size -= 1


# Your MyLinkedList object will be instantiated and called as such:
# obj = MyLinkedList()
# param_1 = obj.get(index)
# obj.addAtHead(val)
# obj.addAtTail(val)
# obj.addAtIndex(index,val)
# obj.deleteAtIndex(index)
