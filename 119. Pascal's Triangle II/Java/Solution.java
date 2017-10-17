public class Solution {
    public List<Integer> getRow(int rowIndex) {
        int[] result = new int[rowIndex + 1];
        result[0] = 1;
        for (int row = 1; row <= rowIndex; row++) {
            for (int i = row; i > 0; i--) {
                result[i] += result[i - 1];
            }
        }
        List<Integer> resultList = new ArrayList<>(result.length);
        for (int item : result) {
            resultList.add(item);
        }
        return resultList;
    }
}