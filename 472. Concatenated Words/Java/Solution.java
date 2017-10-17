public class Solution {
    public List<String> findAllConcatenatedWordsInADict(String[] words) {
        List<String> result = new ArrayList<>();
        Set<String> wordsSet = new HashSet<>();
        Arrays.sort(words, new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                return o1.length() - o2.length();
            }
        });
        for (String word : words) {
            if (!wordsSet.isEmpty()) {
                int length = word.length();
                boolean[] dp = new boolean[length + 1];
                dp[0] = true;
                for (int i = 0; i <= length; i++) {
                    for (int j = 0; j < i; j++) {
                        if (!dp[j]) {
                            continue;
                        }
                        if (wordsSet.contains(word.substring(j, i))) {
                            dp[i] = true;
                            break;
                        }
                    }
                }
                if (dp[length]) {
                    result.add(word);
                }
            }
            wordsSet.add(word);
        }
        return result;
    }
}