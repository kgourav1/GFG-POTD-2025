class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def rotate(head, k):
    if not head or k == 0:  # Handle empty list or no rotation
        return head

    # Step 1: Calculate length and connect the list into a circle
    temp = head
    length = 1

    while temp.next:
        temp = temp.next
        length += 1
    temp.next = head  # Make the list circular

    # Step 2: Optimize k
    k = k % length  # If k >= length, take modulo
    if k == 0:      # If no rotation is needed, break the circle and return head
        temp.next = None
        return head

    # Step 3: Find the new tail
    steps_to_new_tail =  k  # Traverse (k) steps to find the new tail
    new_tail = head

    for _ in range(steps_to_new_tail - 1):
        new_tail = new_tail.next

    new_head = new_tail.next  # New head is the next of new tail
    new_tail.next = None      # Break the circle

    return new_head  # Return the new head of the rotated list
