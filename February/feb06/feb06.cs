using System;
using System.Collections.Generic;

class Node {
    public int data;
    public Node left, right;
    public Node(int val) {
        data = val;
        left = right = null;
    }
}

class BinaryTree {
    private static Node ConstructTree(List<int> preorder, List<int> inorder, Dictionary<int, int> inorderMap, ref int preIndex, int inStart, int inEnd) {
        if (inStart > inEnd) return null;

        int rootValue = preorder[preIndex++];
        Node root = new Node(rootValue);
        int rootIndex = inorderMap[rootValue];

        root.left = ConstructTree(preorder, inorder, inorderMap, ref preIndex, inStart, rootIndex - 1);
        root.right = ConstructTree(preorder, inorder, inorderMap, ref preIndex, rootIndex + 1, inEnd);

        return root;
    }

    public static Node BuildTree(List<int> inorder, List<int> preorder) {
        Dictionary<int, int> inorderMap = new Dictionary<int, int>();
        for (int i = 0; i < inorder.Count; i++) {
            inorderMap[inorder[i]] = i;
        }

        int preIndex = 0;
        return ConstructTree(preorder, inorder, inorderMap, ref preIndex, 0, inorder.Count - 1);
    }
}
