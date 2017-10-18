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
    public int pathSum(TreeNode root, int sum) {
        class Utils {
            int path(TreeNode root, ArrayList<Integer> checkList, int sum) {
                if (root == null) {
                    return 0;
                }
                int count = 0;
                for (int i = 0; i < checkList.size(); i++) {
                    checkList.set(i, checkList.get(i) - root.val);
                    if (checkList.get(i) == 0) {
                        count++;
                    }
                }
                ArrayList<Integer> list1 = (ArrayList<Integer>) checkList.clone();
                list1.add(sum);
                count += path(root.left, list1, sum);
                ArrayList<Integer> list2 = (ArrayList<Integer>) checkList.clone();
                list2.add(sum);
                count += path(root.right, list2, sum);
                return count;
            }
        }
        Utils utils = new Utils();
        ArrayList<Integer> list = new ArrayList<>();
        list.add(sum);
        return utils.path(root, list, sum);
    }
}