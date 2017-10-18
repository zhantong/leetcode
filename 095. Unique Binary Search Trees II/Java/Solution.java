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
    public List<TreeNode> generateTrees(int n) {
        class Utils {
            List<TreeNode> generate(int start, int end) {
                List<TreeNode> result = new ArrayList<>();
                if (start > end) {
                    result.add(null);
                    return result;
                }
                for (int i = start; i <= end; i++) {
                    List<TreeNode> lefts = generate(start, i - 1);
                    List<TreeNode> rights = generate(i + 1, end);
                    for (TreeNode left : lefts) {
                        for (TreeNode right : rights) {
                            TreeNode root = new TreeNode(i);
                            root.left = left;
                            root.right = right;
                            result.add(root);
                        }
                    }
                }
                return result;
            }
        }
        if (n == 0) {
            return new ArrayList<>();
        }
        Utils utils = new Utils();
        return utils.generate(1, n);
    }
}