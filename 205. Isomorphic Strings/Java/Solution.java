public class Solution {
    public boolean isIsomorphic(String s, String t) {
        if (s.length() != t.length()) {
            return false;
        }
        Map<Character, Integer> pattern = new HashMap<>();
        Set<Character> exist = new HashSet<>();
        for (int i = 0; i < s.length(); i++) {
            boolean sExist = exist.contains(s.charAt(i));
            boolean tExist = pattern.containsKey(t.charAt(i));
            if (sExist && tExist) {
                if (pattern.get(t.charAt(i)) + t.charAt(i) != s.charAt(i)) {
                    return false;
                }
            } else if (!sExist && !tExist) {
                exist.add(s.charAt(i));
                pattern.put(t.charAt(i), s.charAt(i) - t.charAt(i));
            } else {
                return false;
            }
        }
        return true;
    }
}