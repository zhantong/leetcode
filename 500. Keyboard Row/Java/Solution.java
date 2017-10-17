public class Solution {
    public String[] findWords(String[] words) {
        Map<Character, Integer> pattern = new HashMap<>();
        for (char letter : "qwertyuiop".toCharArray()) {
            pattern.put(letter, 1);
        }
        for (char letter : "asdfghjkl".toCharArray()) {
            pattern.put(letter, 2);
        }
        for (char letter : "zxcvbnm".toCharArray()) {
            pattern.put(letter, 3);
        }
        List<String> resultList = new ArrayList<>();
        for (String word : words) {
            String wordLower = word.toLowerCase();
            int category = pattern.get(wordLower.charAt(0));
            boolean isSameCategory = true;
            for (char letter : wordLower.toCharArray()) {
                if (pattern.get(letter) != category) {
                    isSameCategory = false;
                    break;
                }
            }
            if (isSameCategory) {
                resultList.add(word);
            }
        }
        return resultList.toArray(new String[resultList.size()]);
    }
}