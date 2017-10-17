public class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> memory = new HashMap<>();
        for (String word : strs) {
            char[] letters = word.toCharArray();
            Arrays.sort(letters);
            String sortedWord = String.valueOf(letters);
            if (!memory.containsKey(sortedWord)) {
                memory.put(sortedWord, new ArrayList<>());
            }
            memory.get(sortedWord).add(word);
        }
        return new ArrayList<>(memory.values());
    }
}