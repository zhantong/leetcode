/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public List<List<String>> printTree(TreeNode root) {
        class Utils {
            int depth;
            String[][] result;

            int getDepth(TreeNode root) {
                if (root == null) {
                    return 0;
                }
                return Math.max(getDepth(root.left), getDepth(root.right)) + 1;
            }

            void printTree(TreeNode root, int row, int col) {
                result[row][col] = String.valueOf(root.val);
                row++;
                if (root.left != null) {
                    printTree(root.left, row, col - (int) Math.pow(2, depth - row - 1));
                }
                if (root.right != null) {
                    printTree(root.right, row, col + (int) Math.pow(2, depth - row - 1));
                }
            }
        }
        Utils utils = new Utils();
        utils.depth = utils.getDepth(root);
        utils.result = new String[utils.depth][(int) Math.pow(2, utils.depth) - 1];
        utils.printTree(root, 0, (int) Math.pow(2, utils.depth - 1) - 1);
        List<List<String>> result = new ArrayList<>();
        for (int row = 0; row < utils.result.length; row++) {
            result.add(new ArrayList<>());
            for (int col = 0; col < utils.result[0].length; col++) {
                result.get(row).add(utils.result[row][col] == null ? "" : utils.result[row][col]);
            }
        }
        return result;
    }
}