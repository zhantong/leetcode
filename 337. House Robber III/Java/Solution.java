/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    Map<TreeNode, Integer> memory;

    public Solution() {
        memory = new HashMap<>();
    }

    public int rob(TreeNode root) {
        if (root == null) {
            return 0;
        }
        if (memory.containsKey(root)) {
            return memory.get(root);
        }
        int subSum = 0;
        if (root.left != null) {
            subSum += rob(root.left.left) + rob(root.left.right);
        }
        if (root.right != null) {
            subSum += rob(root.right.left) + rob(root.right.right);
        }
        int result = Math.max(root.val + subSum, rob(root.left) + rob(root.right));
        memory.put(root, result);
        return result;
    }
}