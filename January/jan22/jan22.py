class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

# Helper function to reverse a linked list
def reverse_list(head):
    prev = None
    current = head
    while current:
        next_node = current.next
        current.next = prev
        prev = current
        current = next_node
    return prev

# Function to remove leading zeros from a linked list
def remove_leading_zeros(head):
    while head and head.data == 0:
        head = head.next  # Skip the leading zero nodes
    return head

# Function to add two linked lists
def add_two_lists(num1, num2):
    # Step 1: Reverse both input lists
    num1 = reverse_list(num1)
    num2 = reverse_list(num2)

    dummy = Node(0)  # Dummy node to build the result list
    current = dummy
    carry = 0

    # Step 2: Add the reversed lists
    while num1 or num2 or carry:
        sum_val = carry

        if num1:
            sum_val += num1.data
            num1 = num1.next

        if num2:
            sum_val += num2.data
            num2 = num2.next

        carry = sum_val // 10
        digit = sum_val % 10

        # Append the digit to the result list
        current.next = Node(digit)
        current = current.next

    # Step 3: Reverse the result list to get the final answer
    result = reverse_list(dummy.next)

    # Step 4: Remove leading zeros if present in the result
    return remove_leading_zeros(result)
