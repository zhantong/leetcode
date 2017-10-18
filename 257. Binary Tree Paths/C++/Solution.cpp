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
    vector<string> binaryTreePaths(TreeNode *root) {
        class Utils {
        public:
            void paths(TreeNode *root, string path, vector<string> &result) {
                if (root->left == nullptr && root->right == nullptr) {
                    result.push_back(path + to_string(root->val));
                }
                if (root->left) {
                    paths(root->left, path + to_string(root->val) + "->", result);
                }
                if (root->right) {
                    paths(root->right, path + to_string(root->val) + "->", result);
                }
            }
        };
        vector<string> result;
        if (root) {
            Utils utils;
            utils.paths(root, "", result);
        }
        return result;
    }
};