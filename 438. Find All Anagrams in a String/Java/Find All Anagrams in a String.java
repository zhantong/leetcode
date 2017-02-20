public class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        List<Integer> result = new ArrayList<>();
        Map<Character, Integer> patternDict = new HashMap<>();
        for (char item : p.toCharArray()) {
            if (!patternDict.containsKey(item)) {
                patternDict.put(item, 0);
            }
            patternDict.put(item, patternDict.get(item) + 1);
        }
        int pLength = p.length();
        int falseAlarm = 0;
        int matchCount = p.length();
        for (int right = 0; right < s.length(); right++) {
            int left = right - pLength;
            if (left >= 0 && patternDict.containsKey(s.charAt(left))) {
                if (patternDict.get(s.charAt(left)) == -1) {
                    falseAlarm--;
                }
                patternDict.put(s.charAt(left), patternDict.get(s.charAt(left)) + 1);
                matchCount++;
            }
            if (patternDict.containsKey(s.charAt(right))) {
                if (patternDict.get(s.charAt(right)) == 0) {
                    falseAlarm++;
                }
                patternDict.put(s.charAt(right), patternDict.get(s.charAt(right)) - 1);
                matchCount -= 1;
                if (matchCount == 0 && falseAlarm == 0) {
                    result.add(left + 1);
                }
            }
        }
        return result;
    }
}