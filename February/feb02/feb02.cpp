vector<vector<int>> levelOrder(Node* root) {
    // Resultant vector to store the level order traversal
    vector<vector<int>> result;

    // If the tree is empty, return an empty result
    if (!root) return result;

    // Queue to facilitate BFS traversal
    queue<Node*> q;
    q.push(root); // Start with the root node

    while (!q.empty()) {
        int levelSize = q.size(); // Number of nodes at the current level
        vector<int> currentLevel; // Vector to store nodes at the current level

        // Process all nodes at the current level
        for (int i = 0; i < levelSize; ++i) {
            Node* currentNode = q.front(); // Get the front node from the queue
            q.pop(); // Remove the front node from the queue

            currentLevel.push_back(currentNode->data); // Add the node's value to the current level

            // Add the left child to the queue if it exists
            if (currentNode->left) q.push(currentNode->left);

            // Add the right child to the queue if it exists
            if (currentNode->right) q.push(currentNode->right);
        }

        // Add the current level's nodes to the result
        result.push_back(currentLevel);
    }

    return result;
}
