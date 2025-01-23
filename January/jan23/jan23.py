class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.random = None

def clone_linked_list(head):
    if head is None:
        return None

    # Step 1: Create new nodes and insert them next to the original nodes
    curr = head
    while curr:
        new_node = Node(curr.data)  # Create a new node with the same data
        new_node.next = curr.next  # Link new node to the next of current node
        curr.next = new_node  # Insert the new node next to the current node
        curr = new_node.next  # Move to the next original node

    # Step 2: Set the random pointers of the new nodes
    curr = head
    while curr:
        if curr.random:
            curr.next.random = curr.random.next  # Set the random of new node to the clone of the random node
        curr = curr.next.next  # Move to the next original node

    # Step 3: Separate the new nodes from the original nodes
    curr = head
    cloned_head = head.next  # Save the head of the cloned list
    clone = cloned_head
    while clone.next:
        curr.next = curr.next.next  # Restore the next pointer of the original list
        clone.next = clone.next.next  # Restore the next pointer of the cloned list
        curr = curr.next  # Move to the next original node
        clone = clone.next  # Move to the next cloned node
    curr.next = None  # Terminate the original list
    clone.next = None  # Terminate the cloned list

    return cloned_head  # Return the head of the cloned list
