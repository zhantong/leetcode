public class Solution {
    public String findLongestWord(String s, List<String> d) {
        Collections.sort(d, new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                if (o1.length() == o2.length()) {
                    return o1.compareTo(o2);
                } else {
                    return o2.length() - o1.length();
                }
            }
        });
        for (String word : d) {
            int i = 0;
            for (char letter : s.toCharArray()) {
                if (letter == word.charAt(i)) {
                    i++;
                }
                if (i == word.length()) {
                    break;
                }
            }
            if (i == word.length()) {
                return word;
            }
        }
        return "";
    }
}