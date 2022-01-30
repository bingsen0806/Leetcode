// Definition for a binary tree node.
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

// Validate Binary Search Tree
// Binary Tree, BST, Graph Transversal
class Solution {
    public Integer val = null;
    public boolean isValidBST(TreeNode root) {
        if (root == null) return true;
        if (isValidBST(root.left) != true) return false;
        if (val != null && root.val <= val) return false;
        process(root);
        if (isValidBST(root.right) != true) return false;
        return true;
    }
    
    public void process(TreeNode root) {
        val = root.val;
    }
}
