public class Solution {
    public List<String> letterCombinations(String digits) {
        if (digits.isEmpty()) {
            return new ArrayList<>();
        }
        List<String> result = new ArrayList<>();
        result.add("");
        String[] pattern = new String[] {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        for (char digit : digits.toCharArray()) {
            List<String> tempResult = new ArrayList<>();
            for (String item : result) {
                for (char letter : pattern[digit - '0'].toCharArray()) {
                    tempResult.add(item + letter);
                }
            }
            result = tempResult;
        }
        return result;
    }
}