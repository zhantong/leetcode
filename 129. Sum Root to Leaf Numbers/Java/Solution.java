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
    public int sumNumbers(TreeNode root) {
        class Utils {
            int numbers(TreeNode root, int prevSum) {
                if (root == null) {
                    return 0;
                }
                prevSum = prevSum * 10 + root.val;
                if (root.left == null && root.right == null) {
                    return prevSum;
                }
                return numbers(root.left, prevSum) + numbers(root.right, prevSum);
            }
        }
        Utils utils = new Utils();
        return utils.numbers(root, 0);
    }
}