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
    int pathSum(TreeNode *root, int sum) {
        class Utils {
        public:
            int path(TreeNode *root, vector<int> checkList, int sum) {
                if (root == nullptr) {
                    return 0;
                }
                int count = 0;
                for (int i = 0; i < checkList.size(); i++) {
                    checkList[i] -= root->val;
                    if (checkList[i] == 0) {
                        count++;
                    }
                }
                vector<int> vec1(checkList);
                vec1.push_back(sum);
                count += path(root->left, vec1, sum);
                vector<int> vec2(checkList);
                vec2.push_back(sum);
                count += path(root->right, vec2, sum);
                return count;
            }
        };
        vector<int> vec;
        vec.push_back(sum);
        Utils utils;
        return utils.path(root, vec, sum);
    }
};