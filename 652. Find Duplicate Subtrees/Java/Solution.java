/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public List<TreeNode> findDuplicateSubtrees(TreeNode root) {
        class Utils {
            String duplicate(TreeNode root, Map<String, Integer> memory, List<TreeNode> result) {
                if (root == null) {
                    return "#";
                }
                String key = duplicate(root.left, memory, result) + "," + duplicate(root.right, memory, result) + "," + String.valueOf(root.val);
                if (!memory.containsKey(key)) {
                    memory.put(key, 0);
                }
                if (memory.get(key) == 1) {
                    result.add(root);
                }
                memory.put(key, memory.get(key) + 1);
                return key;
            }
        }
        Utils utils = new Utils();
        List<TreeNode> result = new ArrayList<>();
        utils.duplicate(root, new HashMap<>(), result);
        return result;
    }
}