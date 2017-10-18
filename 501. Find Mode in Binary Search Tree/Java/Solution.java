/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public int[] findMode(TreeNode root) {
        class Utils {
            Integer prev = null;
            int currentCount = 0;
            int maxCount = 0;

            public void mode(TreeNode root, List<Integer> resultList) {
                if (root == null) {
                    return;
                }
                mode(root.left, resultList);
                if (prev != null && prev == root.val) {
                    currentCount++;
                } else {
                    currentCount = 1;
                }
                prev = root.val;
                if (currentCount > maxCount) {
                    maxCount = currentCount;
                    resultList.clear();
                    resultList.add(root.val);
                } else if (currentCount == maxCount) {
                    resultList.add(root.val);
                }
                mode(root.right, resultList);
            }
        }
        Utils utils = new Utils();
        List<Integer> resultList = new ArrayList<>();
        utils.mode(root, resultList);
        int[] result = new int[resultList.size()];
        for (int i = 0; i < resultList.size(); i++) {
            result[i] = resultList.get(i);
        }
        return result;
    }
}