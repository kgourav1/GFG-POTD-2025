class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def solve(node, diameter):
    if node is None:
        return 0  # Base case: If node is None, height is 0
    
    # Recursively find the height of left and right subtrees
    left_height = solve(node.left, diameter)
    right_height = solve(node.right, diameter)
    
    # Update the maximum diameter found so far
    diameter[0] = max(diameter[0], left_height + right_height)
    
    # Return the height of the current node
    return 1 + max(left_height, right_height)

def diameter(root):
    diameter = [0]  # Variable to store the maximum diameter
    solve(root, diameter)  # Call helper function
    return diameter[0]  # Return the final diameter
