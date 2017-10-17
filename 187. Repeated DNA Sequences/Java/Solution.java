public class Solution {
    public List<String> findRepeatedDnaSequences(String s) {
        Set<Integer> firstGot = new HashSet<>();
        Set<Integer> secondGot = new HashSet<>();
        Map<Character, Integer> pattern = new HashMap<>();
        pattern.put('A', 0);
        pattern.put('C', 1);
        pattern.put('G', 2);
        pattern.put('T', 3);
        List<String> result = new ArrayList<>();
        for (int i = 0; i < s.length() - 9; i++) {
            int current = 0;
            for (int j = i; j < i + 10; j++) {
                current <<= 2;
                current |= pattern.get(s.charAt(j));
            }
            if (!firstGot.contains(current)) {
                firstGot.add(current);
            } else if (!secondGot.contains(current)) {
                result.add(s.substring(i, i + 10));
                secondGot.add(current);
            }
        }
        return result;
    }
}