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
    int kthSmallest(TreeNode *root, int k) {
        class Utils {
        public:
            int k;
            int result;

            Utils(int k) {
                this->k = k;
            }

            void smallest(TreeNode *root) {
                if (root == nullptr) {
                    return;
                }
                smallest(root->left);
                k--;
                if (k == 0) {
                    result = root->val;
                    return;
                }
                smallest(root->right);
            }
        };
        Utils utils(k);
        utils.smallest(root);
        return utils.result;
    }
};