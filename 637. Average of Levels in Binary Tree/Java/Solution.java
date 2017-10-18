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
    public List<Double> averageOfLevels(TreeNode root) {
        if (root == null) {
            return new ArrayList<>();
        }
        Queue<TreeNode> queue = new ArrayDeque<>();
        List<Double> result = new ArrayList<>();
        queue.add(root);
        while (!queue.isEmpty()) {
            long sumCurrentLevel = 0;
            int countCurrentLevel = queue.size();
            for (int i = 0; i < countCurrentLevel; i++) {
                TreeNode current = queue.poll();
                sumCurrentLevel += current.val;
                if (current.left != null) {
                    queue.add(current.left);
                }
                if (current.right != null) {
                    queue.add(current.right);
                }
            }
            if (countCurrentLevel != 0) {
                result.add((double) sumCurrentLevel / countCurrentLevel);
            }
        }
        return result;
    }
}