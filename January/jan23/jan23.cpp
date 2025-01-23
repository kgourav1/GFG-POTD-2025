Node* cloneLinkedList(Node* head) {
    if (head == NULL) {
        return NULL;
    }
    
    // Create new nodes and insert them next to 
  	// the original nodes
    Node* curr = head;
    while (curr != NULL) {
        Node* newNode = new Node(curr->data);
        newNode->next = curr->next;
        curr->next = newNode;
        curr = newNode->next;
    }
    
    // Set the random pointers of the new nodes
    curr = head;
    while (curr != NULL) {
        if (curr->random != NULL)
            curr->next->random = curr->random->next;
        curr = curr->next->next;
    }
    
    // Separate the new nodes from the original nodes
    curr = head;
    Node* clonedHead = head->next;
    Node* clone = clonedHead;
    while (clone->next != NULL) {
      	
      	// Update the next nodes of original node 
      	// and cloned node
        curr->next = curr->next->next;
        clone->next = clone->next->next;
      	
      	// Move pointers of original as well as  
      	// cloned linked list to their next nodes
        curr = curr->next;
        clone = clone->next;
    }
    curr->next = NULL;
    clone->next = NULL;
    
    return clonedHead;
}
