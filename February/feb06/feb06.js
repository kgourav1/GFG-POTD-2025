class Node {
    constructor(val) {
        this.data = val;
        this.left = null;
        this.right = null;
    }
}

function constructTree(preorder, inorder, inorderMap, preIndex, inStart, inEnd) {
    if (inStart > inEnd) return null;

    let rootValue = preorder[preIndex.index++];
    let root = new Node(rootValue);
    let rootIndex = inorderMap[rootValue];

    root.left = constructTree(preorder, inorder, inorderMap, preIndex, inStart, rootIndex - 1);
    root.right = constructTree(preorder, inorder, inorderMap, preIndex, rootIndex + 1, inEnd);

    return root;
}

function buildTree(inorder, preorder) {
    let inorderMap = {};
    for (let i = 0; i < inorder.length; i++) {
        inorderMap[inorder[i]] = i;
    }

    let preIndex = { index: 0 }; // Using an object to simulate pass-by-reference
    return constructTree(preorder, inorder, inorderMap, preIndex, 0, inorder.length - 1);
}
