class Node {
    constructor(data) {
        this.data = data;
        this.left = null;
        this.right = null;
    }
}

// Function to find the height of a binary tree
function height(node) {
    // Base case: If the node is null, return -1 (height of an empty tree)
    if (node === null) return -1;

    // Recursively calculate the height of left and right subtrees
    let leftHeight = height(node.left);
    let rightHeight = height(node.right);

    // Return the maximum height of the two subtrees + 1 (for the current node)
    return Math.max(leftHeight, rightHeight) + 1;
}
