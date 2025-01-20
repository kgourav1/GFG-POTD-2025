class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def sorted_merge(head1, head2):
    # Determine the head of the merged list
    if head1.data < head2.data:
        head = head1
        head1 = head1.next
    else:
        head = head2
        head2 = head2.next

    # Pointer to track the current end of the merged list
    tail = head

    # Traverse both lists and merge nodes
    while head1 and head2:
        if head1.data < head2.data:
            tail.next = head1
            head1 = head1.next
        else:
            tail.next = head2
            head2 = head2.next
        tail = tail.next

    # Append the remaining nodes of the non-empty list
    if head1:
        tail.next = head1
    else:
        tail.next = head2

    return head
