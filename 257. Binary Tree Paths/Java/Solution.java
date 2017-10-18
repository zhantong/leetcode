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
    public List<String> binaryTreePaths(TreeNode root) {
        class Utils {
            public void paths(TreeNode root, String path, List<String> result) {
                if (root.left == null && root.right == null) {
                    result.add(path + root.val);
                }
                if (root.left != null) {
                    paths(root.left, path + root.val + "->", result);
                }
                if (root.right != null) {
                    paths(root.right, path + root.val + "->", result);
                }
            }
        }
        Utils utils = new Utils();
        List<String> result = new ArrayList<>();
        if (root != null) {
            utils.paths(root, "", result);
        }
        return result;
    }
}