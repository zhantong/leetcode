public class Solution {
    public String[] findWords(String[] words) {
        Map<Character, Integer> pattern = new HashMap<>();
        pattern.put('q', 1);
        pattern.put('w', 1);
        pattern.put('e', 1);
        pattern.put('r', 1);
        pattern.put('t', 1);
        pattern.put('y', 1);
        pattern.put('u', 1);
        pattern.put('i', 1);
        pattern.put('o', 1);
        pattern.put('p', 1);
        pattern.put('a', 2);
        pattern.put('s', 2);
        pattern.put('d', 2);
        pattern.put('f', 2);
        pattern.put('g', 2);
        pattern.put('h', 2);
        pattern.put('j', 2);
        pattern.put('k', 2);
        pattern.put('l', 2);
        pattern.put('z', 3);
        pattern.put('x', 3);
        pattern.put('c', 3);
        pattern.put('v', 3);
        pattern.put('b', 3);
        pattern.put('n', 3);
        pattern.put('m', 3);
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