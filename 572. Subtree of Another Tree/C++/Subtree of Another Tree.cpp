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
    bool isSubtree(TreeNode *s, TreeNode *t) {
        class Utils {
        public:
            bool isSame(TreeNode *s, TreeNode *t) {
                if (s == nullptr && t == nullptr) {
                    return true;
                }
                if (s == nullptr || t == nullptr || s->val != t->val) {
                    return false;
                }
                return isSame(s->left, t->left) && isSame(s->right, t->right);
            }
        };
        if (s == nullptr) {
            return false;
        }
        Utils utils;
        return utils.isSame(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
    }
};