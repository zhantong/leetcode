class Solution {
    public boolean isPossible(int[] nums) {
        Map<Integer, Integer> counts = new HashMap<>();
        for (int num : nums) {
            if (!counts.containsKey(num)) {
                counts.put(num, 0);
            }
            counts.put(num, counts.get(num) + 1);
        }
        Map<Integer, Integer> needs = new HashMap<>();
        for (int num : nums) {
            if (counts.get(num) == 0) {
                continue;
            }
            if (needs.containsKey(num) && needs.get(num) > 0) {
                needs.put(num, needs.get(num) - 1);
                if (!needs.containsKey(num + 1)) {
                    needs.put(num + 1, 0);
                }
                needs.put(num + 1, needs.get(num + 1) + 1);
            } else if (counts.containsKey(num + 1) && counts.get(num + 1) > 0 && counts.containsKey(num + 2) && counts.get(num + 2) > 0) {
                counts.put(num + 1, counts.get(num + 1) - 1);
                counts.put(num + 2, counts.get(num + 2) - 1);
                if (!needs.containsKey(num + 3)) {
                    needs.put(num + 3, 0);
                }
                needs.put(num + 3, needs.get(num + 3) + 1);
            } else {
                return false;
            }
            counts.put(num, counts.get(num) - 1);
        }
        return true;
    }
}