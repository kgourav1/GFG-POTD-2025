class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def height(node):
    # Base case: If the node is None, return -1 (height of an empty tree)
    if node is None:
        return -1
    
    # Recursively calculate the height of left and right subtrees
    left_height = height(node.left)
    right_height = height(node.right)
    
    # Return the maximum height of the two subtrees + 1 (for the current node)
    return max(left_height, right_height) + 1
