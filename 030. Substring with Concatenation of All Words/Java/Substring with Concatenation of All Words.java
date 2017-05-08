public class Solution {
    public List<Integer> findSubstring(String s, String[] words) {
        List<Integer> result = new ArrayList<>();
        Map<String, Integer> counts = new HashMap<>();
        int wordsLength = words.length;
        int wordLength = words[0].length();
        for (String word : words) {
            if (!counts.containsKey(word)) {
                counts.put(word, 0);
            }
            counts.put(word, counts.get(word) + 1);
        }
        for (int i = 0; i <= s.length() - wordsLength * wordLength; i++) {
            Map<String, Integer> currentCounts = new HashMap<>();
            int j = 0;
            while (j < wordsLength) {
                int index = i + j * wordLength;
                String current = s.substring(index, index + wordLength);
                if (counts.containsKey(current)) {
                    if (!currentCounts.containsKey(current)) {
                        currentCounts.put(current, 0);
                    }
                    currentCounts.put(current, currentCounts.get(current) + 1);
                    if (currentCounts.get(current) > counts.get(current)) {
                        break;
                    }
                } else {
                    break;
                }
                j++;
            }
            if (j == wordsLength) {
                result.add(i);
            }
        }
        return result;
    }
}