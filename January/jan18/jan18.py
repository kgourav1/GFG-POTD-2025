class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def reverseList(head):
    prev = None  # Initialize previous pointer
    curr = head  # Start with the head of the list

    while curr is not None:
        next_node = curr.next  # Store the next node
        curr.next = prev       # Reverse the current node's pointer
        prev = curr            # Move the previous pointer forward
        curr = next_node       # Move the current pointer forward

    return prev  # New head of the reversed list
