// Definition for the binary tree node.
struct Node {
    int data;
    Node* left;
    Node* right;
    
    // Constructor to create a new node with given data.
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Helper function to perform preorder traversal and serialize the tree.
void serializeHelper(Node* root, std::vector<int>& arr) {
    // If the current node is NULL, add the marker and return.
    if (root == nullptr) {
        arr.push_back(-1); // Marker for null node.
        return;
    }
    
    // Add the current node's data to the vector.
    arr.push_back(root->data);
    
    // Recursively serialize the left subtree.
    serializeHelper(root->left, arr);
    
    // Recursively serialize the right subtree.
    serializeHelper(root->right, arr);
}

// Function to serialize a tree and return a vector containing its nodes.
std::vector<int> serialize(Node* root) {
    std::vector<int> arr;   // Vector to store serialized tree.
    serializeHelper(root, arr);  // Fill the vector using helper function.
    return arr;  // Return the serialized vector.
}

// Helper function to deserialize the vector and construct the tree.
// 'index' is passed by reference so that we keep track of the current position in the vector.
Node* deSerializeHelper(const std::vector<int>& arr, int& index) {
    // If the current index is out of bounds or the marker is found, return NULL.
    if (index >= arr.size() || arr[index] == -1) {
        index++;  // Move to the next element.
        return nullptr;
    }
    
    // Create a new node with the current data.
    Node* root = new Node(arr[index++]);
    
    // Recursively build the left subtree.
    root->left = deSerializeHelper(arr, index);
    
    // Recursively build the right subtree.
    root->right = deSerializeHelper(arr, index);
    
    // Return the current constructed subtree.
    return root;
}

// Function to deserialize a vector back to a binary tree and return the root.
Node* deSerialize(std::vector<int>& arr) {
    int index = 0;  // Initialize index to start from the beginning of the vector.
    return deSerializeHelper(arr, index);  // Return the reconstructed tree.
}
