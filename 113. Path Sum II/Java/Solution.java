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
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        class Utils {
            void dfs(TreeNode root, int sum, List<List<Integer>> result, List<Integer> current) {
                current.add(root.val);
                sum -= root.val;
                if (sum == 0) {
                    if (root.left == null && root.right == null) {
                        result.add(new ArrayList<>(current));
                    }
                }
                if (root.left != null) {
                    dfs(root.left, sum, result, current);
                }
                if (root.right != null) {
                    dfs(root.right, sum, result, current);
                }
                current.remove(current.size() - 1);
            }
        }
        List<List<Integer>> result = new ArrayList<>();
        if (root == null) {
            return result;
        }
        Utils utils = new Utils();
        utils.dfs(root, sum, result, new ArrayList<>());
        return result;
    }
}