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
    vector<vector<int>> pathSum(TreeNode *root, int sum) {
        class Utils {
        public:
            void dfs(TreeNode *root, int sum, vector<vector<int>> &result, vector<int> &current) {
                current.push_back(root->val);
                sum -= root->val;
                if (sum == 0) {
                    if (root->left == nullptr && root->right == nullptr) {
                        result.push_back(current);
                    }
                }
                if (root->left != nullptr) {
                    dfs(root->left, sum, result, current);
                }
                if (root->right != nullptr) {
                    dfs(root->right, sum, result, current);
                }
                current.pop_back();
            }
        };
        vector<vector<int>> result;
        if (root == nullptr) {
            return result;
        }
        Utils utils;
        vector<int> temp;
        utils.dfs(root, sum, result, temp);
        return result;
    }
};