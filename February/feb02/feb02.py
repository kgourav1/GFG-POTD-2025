from collections import deque

class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None

def levelOrder(root):
    # Resultant list to store the level order traversal
    result = []

    # If the tree is empty, return an empty result
    if not root:
        return result

    # Queue to facilitate BFS traversal
    q = deque()
    q.append(root)  # Start with the root node

    while q:
        levelSize = len(q)  # Number of nodes at the current level
        currentLevel = []  # List to store nodes at the current level

        # Process all nodes at the current level
        for _ in range(levelSize):
            currentNode = q.popleft()  # Get and remove the front node from the queue
            currentLevel.append(currentNode.data)  # Add the node's value to the current level

            # Add the left child to the queue if it exists
            if currentNode.left:
                q.append(currentNode.left)

            # Add the right child to the queue if it exists
            if currentNode.right:
                q.append(currentNode.right)

        # Add the current level's nodes to the result
        result.append(currentLevel)

    return result
