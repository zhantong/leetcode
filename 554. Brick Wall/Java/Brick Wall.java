public class Solution {
    public int leastBricks(List<List<Integer>> wall) {
        Map<Integer, Integer> count = new HashMap<>();
        for (List<Integer> row : wall) {
            int current = 0;
            for (int i = 0; i < row.size() - 1; i++) {
                current += row.get(i);
                if (!count.containsKey(current)) {
                    count.put(current, 0);
                }
                count.put(current, count.get(current) + 1);
            }
        }
        int maxValue = 0;
        for (int value : count.values()) {
            maxValue = Math.max(maxValue, value);
        }
        return wall.size() - maxValue;
    }
}