class Node {
    constructor(val) {
        this.data = val;
        this.left = null;
        this.right = null;
    }
}

function levelOrder(root) {
    // Resultant array to store the level order traversal
    let result = [];

    // If the tree is empty, return an empty result
    if (!root) return result;

    // Queue to facilitate BFS traversal
    let q = [];
    q.push(root); // Start with the root node

    while (q.length > 0) {
        let levelSize = q.length; // Number of nodes at the current level
        let currentLevel = []; // Array to store nodes at the current level

        // Process all nodes at the current level
        for (let i = 0; i < levelSize; i++) {
            let currentNode = q.shift(); // Get and remove the front node from the queue
            currentLevel.push(currentNode.data); // Add the node's value to the current level

            // Add the left child to the queue if it exists
            if (currentNode.left) q.push(currentNode.left);

            // Add the right child to the queue if it exists
            if (currentNode.right) q.push(currentNode.right);
        }

        // Add the current level's nodes to the result
        result.push(currentLevel);
    }

    return result;
}
