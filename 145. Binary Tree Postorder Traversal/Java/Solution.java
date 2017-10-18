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
    public List<Integer> postorderTraversal(TreeNode root) {
        Stack<TreeNode> stack = new Stack<>();
        LinkedList<Integer> result = new LinkedList<>();
        TreeNode node = root;
        while (node != null || !stack.empty()) {
            if (node != null) {
                stack.push(node);
                result.addFirst(node.val);
                node = node.right;
            } else {
                node = stack.pop();
                node = node.left;
            }
        }
        return result;
    }
}