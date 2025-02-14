class Solution:
    def __init__(self):
        self.first = self.second = self.prev = None

    def inorder(self, root):
        if not root:
            return

        self.inorder(root.left)  # Traverse left subtree

        # Identify swapped nodes
        if self.prev and root.val < self.prev.val:
            if not self.first:
                self.first = self.prev  # First incorrect node
            self.second = root  # Second incorrect node (updated if needed)

        self.prev = root  # Move to the next node

        self.inorder(root.right)  # Traverse right subtree

    def correctBST(self, root):
        self.inorder(root)  # Identify misplaced nodes
        if self.first and self.second:
            self.first.val, self.second.val = self.second.val, self.first.val  # Swap values to restore BST
