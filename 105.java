import java.util.HashMap;
import java.util.LinkedList;

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

 // Construct Binary Tree from Preorder and Inorder Transversal
 // Binary Tree, Graph Transversal
class Solution {
    
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        HashMap<Integer, Integer> index = new HashMap<Integer, Integer>();
        for (int i=0; i < inorder.length; i++) {
            index.put(inorder[i], i);
        }
        LinkedList<TreeNode> stack = new LinkedList<TreeNode>();
        TreeNode root = new TreeNode(preorder[0], null, null);
        stack.push(root);
        for (int i=1; i < preorder.length; i++) {
            TreeNode positionRightMe = null;
            TreeNode nodeToInsert = new TreeNode(preorder[i], null, null);
            while (!stack.isEmpty() && index.get(stack.peekFirst().val) < index.get(preorder[i])) {
                positionRightMe = stack.pop();
            }
            if (positionRightMe == null) {
                stack.peekFirst().left = nodeToInsert;
            } else {
                positionRightMe.right = nodeToInsert;
            }
            stack.push(nodeToInsert);
        }
        return root;
        
    }
}
