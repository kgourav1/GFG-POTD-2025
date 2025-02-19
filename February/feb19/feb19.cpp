// Function to merge two sorted linked lists into one sorted list
Node* merge(Node* a, Node* b) {
    // If list 'a' is empty, return list 'b'
    if (!a) return b;
    
    // If list 'b' is empty, return list 'a'
    if (!b) return a;
    
    // Compare data of nodes 'a' and 'b'
    if (a->data < b->data) {
        // 'a' has a smaller element, so set its next to the result of merging the rest of 'a' with list 'b'
        a->next = merge(a->next, b);
        // Return 'a' as the head of the merged list
        return a;
    } else {
        // 'b' has a smaller element, so set its next to the result of merging list 'a' with the rest of 'b'
        b->next = merge(a, b->next);
        // Return 'b' as the head of the merged list
        return b;
    }
}

// Function to merge k sorted linked lists into one sorted list
Node* mergeKLists(vector<Node*>& arr) {
    // Initialize the result list as empty
    Node* res = nullptr;
    
    // Iterate over each linked list in the vector 'arr'
    for (int i = 0; i < arr.size(); i++) {
        // Merge the current result with the current list from 'arr'
        res = merge(res, arr[i]);
    }
    
    // Return the final merged linked list
    return res;
}
