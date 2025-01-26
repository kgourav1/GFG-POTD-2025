class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def remove_loop(head):
    if not head or not head.next:
        return  # If the list is empty or has only one node, no loop can exist.

    slow = head
    fast = head

    # Step 1: Detect the loop using Floyd's Cycle Detection Algorithm
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next

        # If slow and fast meet, loop is detected
        if slow == fast:
            break

    # If no loop is found
    if slow != fast:
        return

    # Step 2: Find the start of the loop
    slow = head
    if slow == fast:
        # Special case when the loop starts at the head
        while fast.next != slow:
            fast = fast.next
    else:
        while slow.next != fast.next:
            slow = slow.next
            fast = fast.next

    # Step 3: Remove the loop
    fast.next = None
