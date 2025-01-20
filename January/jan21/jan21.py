class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def reverse_k_group(head, k):
    if not head:
        return None  # If the list is empty, return None

    prev = None      # Initialize previous pointer for reversal
    curr = head      # Start with the head of the list
    next_node = None # Pointer to store the next node
    count = 0        # Counter to track the number of nodes reversed

    # Reverse `k` nodes in the group
    while curr and count < k:
        next_node = curr.next # Store the next node
        curr.next = prev      # Reverse the current node's pointer
        prev = curr           # Move the previous pointer forward
        curr = next_node      # Move the current pointer forward
        count += 1            # Increment the counter

    # Recursive call to process the remaining nodes
    if next_node:
        head.next = reverse_k_group(next_node, k) # Connect the end of the reversed group to the next reversed group

    return prev # Return the new head of the reversed group
