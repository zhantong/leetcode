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
    vector<int> findFrequentTreeSum(TreeNode *root) {
        class Utils {
        public:
            int maxFreq = -1;
            unordered_map<int, int> map;

            int treeSum(TreeNode *root) {
                if (root == nullptr) {
                    return 0;
                }
                int leftSum = treeSum(root->left);
                int rightSum = treeSum(root->right);
                int nodeSum = leftSum + rightSum + root->val;
                if (map.find(nodeSum) == map.end()) {
                    map[nodeSum] = 0;
                }
                map[nodeSum]++;
                maxFreq = max(maxFreq, map[nodeSum]);
                return nodeSum;
            }
        };
        Utils utils;
        utils.treeSum(root);
        vector<int> result;
        for (auto &item : utils.map) {
            if (item.second == utils.maxFreq) {
                result.push_back(item.first);
            }
        }
        return result;
    }
};