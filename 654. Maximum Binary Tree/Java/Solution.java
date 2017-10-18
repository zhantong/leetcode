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
    public TreeNode constructMaximumBinaryTree(int[] nums) {
        class Utils {
            TreeNode construct(int[] nums, int start, int end) {
                if (start == end) {
                    return null;
                }
                int max = Integer.MIN_VALUE;
                int maxIndex = -1;
                for (int i = start; i < end; i++) {
                    if (nums[i] > max) {
                        max = nums[i];
                        maxIndex = i;
                    }
                }
                TreeNode root = new TreeNode(max);
                root.left = construct(nums, start, maxIndex);
                root.right = construct(nums, maxIndex + 1, end);
                return root;
            }
        }
        Utils utils = new Utils();
        return utils.construct(nums, 0, nums.length);
    }
}