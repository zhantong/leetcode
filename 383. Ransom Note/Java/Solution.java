public class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        Map<Character, Integer> has = new HashMap<>();
        for (char item : magazine.toCharArray()) {
            if (!has.containsKey(item)) {
                has.put(item, 0);
            }
            has.put(item, has.get(item) + 1);
        }
        for (char item : ransomNote.toCharArray()) {
            if (!has.containsKey(item) || has.get(item) == 0) {
                return false;
            }
            has.put(item, has.get(item) - 1);
        }
        return true;
    }
}