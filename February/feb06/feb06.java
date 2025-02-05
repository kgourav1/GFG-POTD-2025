import java.util.*;

class Node {
    int data;
    Node left, right;
    Node(int val) {
        data = val;
        left = right = null;
    }
}

class BinaryTree {
    private static Node constructTree(List<Integer> preorder, List<Integer> inorder, Map<Integer, Integer> inorderMap, int[] preIndex, int inStart, int inEnd) {
        if (inStart > inEnd) return null;

        int rootValue = preorder.get(preIndex[0]++);
        Node root = new Node(rootValue);
        int rootIndex = inorderMap.get(rootValue);

        root.left = constructTree(preorder, inorder, inorderMap, preIndex, inStart, rootIndex - 1);
        root.right = constructTree(preorder, inorder, inorderMap, preIndex, rootIndex + 1, inEnd);

        return root;
    }

    public static Node buildTree(List<Integer> inorder, List<Integer> preorder) {
        Map<Integer, Integer> inorderMap = new HashMap<>();
        for (int i = 0; i < inorder.size(); i++) {
            inorderMap.put(inorder.get(i), i);
        }

        int[] preIndex = {0}; // Using an array to simulate pass-by-reference
        return constructTree(preorder, inorder, inorderMap, preIndex, 0, inorder.size() - 1);
    }
}
