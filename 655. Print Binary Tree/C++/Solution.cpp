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
    vector<vector<string>> printTree(TreeNode *root) {
        class Utils {
        public:
            int depth;
            vector<vector<string>> result;

            int getDepth(TreeNode *root) {
                if (root == nullptr) {
                    return 0;
                }
                return max(getDepth(root->left), getDepth(root->right)) + 1;
            }

            void printTree(TreeNode *root, int row, int col) {
                result[row][col] = to_string(root->val);
                row++;
                if (root->left != nullptr) {
                    printTree(root->left, row, col - (int) pow(2, depth - row - 1));
                }
                if (root->right != nullptr) {
                    printTree(root->right, row, col + (int) pow(2, depth - row - 1));
                }
            }
        };
        Utils utils;
        utils.depth = utils.getDepth(root);
        utils.result = vector<vector<string>>(utils.depth, vector<string>((int) pow(2, utils.depth) - 1, ""));
        utils.printTree(root, 0, (int) pow(2, utils.depth - 1) - 1);
        return utils.result;
    }
};