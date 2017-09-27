class Solution {
    public boolean checkInclusion(String s1, String s2) {
        int s1Length = s1.length();
        int count = s1.length();
        int[] memory = new int[26];
        for (char letter : s1.toCharArray()) {
            memory[letter - 'a']++;
        }
        for (int i = 0; i < s2.length(); i++) {
            char letter = s2.charAt(i);
            if (memory[letter - 'a'] > 0) {
                count--;
                if (count == 0) {
                    return true;
                }
            }
            memory[letter - 'a']--;
            if (i >= s1Length - 1) {
                int leftIndex = i - s1Length + 1;
                if (memory[s2.charAt(leftIndex) - 'a'] >= 0) {
                    count++;
                }
                memory[s2.charAt(leftIndex) - 'a']++;
            }
        }
        return false;
    }
}