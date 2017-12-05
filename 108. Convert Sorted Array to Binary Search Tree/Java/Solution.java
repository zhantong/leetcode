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
    public TreeNode sortedArrayToBST(int[] nums) {
        class Utils {
            TreeNode toBST(int[] nums, int start, int end) {
                if (start > end) {
                    return null;
                }
                int mid = (start + end) / 2;
                TreeNode node = new TreeNode(nums[mid]);
                node.left = toBST(nums, start, mid - 1);
                node.right = toBST(nums, mid + 1, end);
                return node;
            }
        }
        Utils utils = new Utils();
        return utils.toBST(nums, 0, nums.length - 1);
    }
}