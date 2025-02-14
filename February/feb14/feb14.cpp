class Solution {
private:
    Node *first = nullptr, *second = nullptr, *prev = nullptr;

    // Inorder traversal to find the misplaced nodes
    void inorder(Node* root) {
        if (!root) return; // Base case: If node is null, return

        inorder(root->left); // Traverse the left subtree

        // Identify swapped nodes
        if (prev && root->data < prev->data) {  
            if (!first) first = prev; // First incorrect node (first occurrence)
            second = root;  // Second incorrect node (could be updated)
        }
        
        prev = root; // Move to the next node
        
        inorder(root->right); // Traverse the right subtree
    }

public:
    // Function to correct the swapped nodes in BST
    void correctBST(Node* root) {
        inorder(root); // Perform inorder traversal to detect misplaced nodes
        if (first && second) std::swap(first->data, second->data); // Swap their values to restore BST property
    }
};
