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
    int sumNumbers(TreeNode *root) {
        class Utils {
        public:
            int numbers(TreeNode *root, int prevSum) {
                if (root == nullptr) {
                    return 0;
                }
                prevSum = prevSum * 10 + root->val;
                if (root->left == nullptr && root->right == nullptr) {
                    return prevSum;
                }
                return numbers(root->left, prevSum) + numbers(root->right, prevSum);
            }
        };
        Utils utils;
        return utils.numbers(root, 0);
    }
};