/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        class Utils {
        public:
            TreeNode *toBST(vector<int> &nums, int start, int end) {
                if (start > end) {
                    return nullptr;
                }
                int mid = (start + end) / 2;
                TreeNode *node = new TreeNode(nums[mid]);
                node->left = toBST(nums, start, mid - 1);
                node->right = toBST(nums, mid + 1, end);
                return node;
            }
        };
        Utils utils;
        return utils.toBST(nums, 0, nums.size() - 1);
    }
};