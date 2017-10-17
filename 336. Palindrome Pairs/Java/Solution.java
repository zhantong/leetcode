public class Solution {
    public List<List<Integer>> palindromePairs(String[] words) {
        List<List<Integer>> result = new ArrayList<>();
        Map<String, Integer> wordsSet = new HashMap<>();
        for (int i = 0; i < words.length; i++) {
            wordsSet.put(words[i], i);
        }
        for (int i = 0; i < words.length; i++) {
            String word = words[i];
            for (int j = 0; j <= word.length(); j++) {
                String left = word.substring(0, j);
                String right = word.substring(j);
                String leftReverse = new StringBuilder(left).reverse().toString();
                String rightReverse = new StringBuilder(right).reverse().toString();
                if (left.equals(leftReverse) && wordsSet.containsKey(rightReverse) && wordsSet.get(rightReverse) != i) {
                    result.add(Arrays.asList(wordsSet.get(rightReverse), i));
                }
                if (!right.isEmpty() && right.equals(rightReverse) && wordsSet.containsKey(leftReverse) && wordsSet.get(leftReverse) != i) {
                    result.add(Arrays.asList(i, wordsSet.get(leftReverse)));
                }
            }
        }
        return result;
    }
}