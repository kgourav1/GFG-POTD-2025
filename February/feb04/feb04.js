class Node {
    constructor(data) {
        this.data = data;
        this.left = null;
        this.right = null;
    }
}

// Helper function to calculate height and update diameter
function solve(node, diameter) {
    if (node === null) return 0; // Base case: If node is NULL, height is 0

    // Recursively find the height of left and right subtrees
    let leftHeight = solve(node.left, diameter);
    let rightHeight = solve(node.right, diameter);

    // Update the maximum diameter found so far
    diameter[0] = Math.max(diameter[0], leftHeight + rightHeight);

    // Return the height of the current node
    return 1 + Math.max(leftHeight, rightHeight);
}

function diameter(root) {
    let diameter = [0]; // Variable to store the maximum diameter
    solve(root, diameter); // Call helper function
    return diameter[0]; // Return the final diameter
}
