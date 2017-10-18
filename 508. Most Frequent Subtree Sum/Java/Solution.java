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
    public int[] findFrequentTreeSum(TreeNode root) {
        class Utils {
            int maxFreq = -1;
            Map<Integer, Integer> map;

            public Utils() {
                map = new HashMap<>();
            }

            public int treeSum(TreeNode root) {
                if (root == null) {
                    return 0;
                }
                int leftSum = treeSum(root.left);
                int rightSum = treeSum(root.right);
                int nodeSum = leftSum + rightSum + root.val;
                if (!map.containsKey(nodeSum)) {
                    map.put(nodeSum, 0);
                }
                int freq = map.get(nodeSum) + 1;
                map.put(nodeSum, freq);
                if (freq > maxFreq) {
                    maxFreq = freq;
                }
                return nodeSum;
            }
        }
        Utils utils = new Utils();
        utils.treeSum(root);
        List<Integer> resultList = new ArrayList<>();
        for (Map.Entry<Integer, Integer> entry : utils.map.entrySet()) {
            if (entry.getValue() == utils.maxFreq) {
                resultList.add(entry.getKey());
            }
        }
        int[] result = new int[resultList.size()];
        for (int i = 0; i < result.length; i++) {
            result[i] = resultList.get(i);
        }
        return result;
    }
}