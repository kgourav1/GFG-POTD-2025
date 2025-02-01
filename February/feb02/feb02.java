import java.util.*;

class Node {
    int data;
    Node left, right;

    Node(int val) {
        data = val;
        left = right = null;
    }
}

public class LevelOrderTraversal {
    public List<List<Integer>> levelOrder(Node root) {
        // Resultant list to store the level order traversal
        List<List<Integer>> result = new ArrayList<>();

        // If the tree is empty, return an empty result
        if (root == null) return result;

        // Queue to facilitate BFS traversal
        Queue<Node> q = new LinkedList<>();
        q.add(root); // Start with the root node

        while (!q.isEmpty()) {
            int levelSize = q.size(); // Number of nodes at the current level
            List<Integer> currentLevel = new ArrayList<>(); // List to store nodes at the current level

            // Process all nodes at the current level
            for (int i = 0; i < levelSize; i++) {
                Node currentNode = q.poll(); // Get and remove the front node from the queue
                currentLevel.add(currentNode.data); // Add the node's value to the current level

                // Add the left child to the queue if it exists
                if (currentNode.left != null) q.add(currentNode.left);

                // Add the right child to the queue if it exists
                if (currentNode.right != null) q.add(currentNode.right);
            }

            // Add the current level's nodes to the result
            result.add(currentLevel);
        }

        return result;
    }
}
