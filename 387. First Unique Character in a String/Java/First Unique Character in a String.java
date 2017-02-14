public class Solution {
    public int firstUniqChar(String s) {
        Map<Character, Integer> countMap = new HashMap<>();
        for (char item : s.toCharArray()) {
            if (!countMap.containsKey(item)) {
                countMap.put(item, 0);
            }
            countMap.put(item, countMap.get(item) + 1);
        }
        int index = 0;
        for (char item : s.toCharArray()) {
            if (countMap.get(item) == 1) {
                return index;
            }
            index++;
        }
        return -1;
    }
}