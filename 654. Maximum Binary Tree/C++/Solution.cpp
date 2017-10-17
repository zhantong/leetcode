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
    TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
        class Utils {
        public:
            TreeNode *construct(vector<int> &nums, int start, int end) {
                if (start == end) {
                    return nullptr;
                }
                int max = INT_MIN;
                int maxIndex = -1;
                for (int i = start; i < end; i++) {
                    if (nums[i] > max) {
                        max = nums[i];
                        maxIndex = i;
                    }
                }
                TreeNode *root = new TreeNode(max);
                root->left = construct(nums, start, maxIndex);
                root->right = construct(nums, maxIndex + 1, end);
                return root;
            }
        };
        Utils utils;
        return utils.construct(nums, 0, nums.size());
    }
};