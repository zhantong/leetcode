public class Solution {
    public List<String> wordBreak(String s, List<String> wordDict) {
        class Utils {
            List<String> backTrace(String s, List<String> wordDict, Map<String, List<String>> memory) {
                if (s.isEmpty()) {
                    List<String> result = new ArrayList<>();
                    result.add("");
                    return result;
                }
                if (memory.containsKey(s)) {
                    return memory.get(s);
                }
                List<String> currentMemory = new ArrayList<>();
                for (String word : wordDict) {
                    if (s.startsWith(word)) {
                        List<String> lefts = backTrace(s.substring(word.length()), wordDict, memory);
                        for (String left : lefts) {
                            currentMemory.add(word + (left.isEmpty() ? "" : " ") + left);
                        }
                    }
                }
                memory.put(s, currentMemory);
                return currentMemory;
            }
        }
        Utils utils = new Utils();
        return utils.backTrace(s, wordDict, new HashMap<>());
    }
}