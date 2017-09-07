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
    int findTilt(TreeNode *root) {
        class Util {
        public:
            int tilt = 0;

            int sum(TreeNode *root) {
                if (root == nullptr) {
                    return 0;
                }
                int sumLeft = sum(root->left);
                int sumRight = sum(root->right);
                tilt += abs(sumLeft - sumRight);
                return sumLeft + sumRight + root->val;
            }
        };
        Util util;
        util.sum(root);
        return util.tilt;
    }
};