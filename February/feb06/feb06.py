class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None

def construct_tree(preorder, inorder, inorder_map, pre_index, in_start, in_end):
    if in_start > in_end:
        return None

    root_value = preorder[pre_index[0]]
    pre_index[0] += 1
    root = Node(root_value)
    root_index = inorder_map[root_value]

    root.left = construct_tree(preorder, inorder, inorder_map, pre_index, in_start, root_index - 1)
    root.right = construct_tree(preorder, inorder, inorder_map, pre_index, root_index + 1, in_end)

    return root

def build_tree(inorder, preorder):
    inorder_map = {val: idx for idx, val in enumerate(inorder)}
    pre_index = [0]  # Using a list to act as a reference
    return construct_tree(preorder, inorder, inorder_map, pre_index, 0, len(inorder) - 1)
