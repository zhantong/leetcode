public class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> result = new ArrayList<>(numRows);
        if (numRows >= 1) {
            List<Integer> one = new ArrayList<>(1);
            one.add(1);
            result.add(one);
        }
        if (numRows >= 2) {
            List<Integer> two = new ArrayList<>(2);
            two.add(1);
            two.add(1);
            result.add(two);
        }
        for (int row = 3; row <= numRows; row++) {
            List<Integer> current = new ArrayList<>(row);
            current.add(1);
            for (int i = 1; i < row - 1; i++) {
                current.add(i, result.get(row - 2).get(i - 1) + result.get(row - 2).get(i));
            }
            current.add(1);
            result.add(current);
        }
        return result;
    }
}