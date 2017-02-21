public class Solution {
    public boolean wordPattern(String pattern, String str) {
        String[] words = str.split(" ");
        if (pattern.length() != words.length) {
            return false;
        }
        Map<Character, String> map = new HashMap<>();
        for (int i = 0; i < pattern.length(); i++) {
            char letter = pattern.charAt(i);
            String word = words[i];
            if (map.containsKey(letter)) {
                if (!map.get(letter).equals(word)) {
                    return false;
                }
            } else {
                if (map.containsValue(word)) {
                    return false;
                }
                map.put(letter, word);
            }
        }
        return true;
    }
}