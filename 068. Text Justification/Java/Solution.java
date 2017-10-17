public class Solution {
    public List<String> fullJustify(String[] words, int maxWidth) {
        List<String> result = new ArrayList<>();
        int countChar = 0;
        List<String> row = new ArrayList<>();
        for (String word : words) {
            if (word.length() + countChar + row.size() > maxWidth) {
                if (row.size() == 1) {
                    char[] spaces = new char[maxWidth - row.get(0).length()];
                    Arrays.fill(spaces, ' ');
                    result.add(row.get(0) + String.valueOf(spaces));
                } else {
                    int countSpace = (maxWidth - countChar) / (row.size() - 1);
                    int countExtra = (maxWidth - countChar) % (row.size() - 1);
                    StringBuilder builder = new StringBuilder();
                    char[] spaces = new char[countSpace];
                    Arrays.fill(spaces, ' ');
                    for (int i = 0; i < row.size() - 1; i++) {
                        builder.append(row.get(i));
                        if (i < countExtra) {
                            builder.append(' ');
                        }
                        builder.append(spaces);
                    }
                    builder.append(row.get(row.size() - 1));
                    result.add(builder.toString());
                }
                countChar = 0;
                row.clear();
            }
            countChar += word.length();
            row.add(word);
        }
        StringBuilder builder = new StringBuilder();
        for (String item : row) {
            builder.append(item);
            builder.append(' ');
        }
        builder.deleteCharAt(builder.length() - 1);
        char[] spaces = new char[maxWidth - builder.length()];
        Arrays.fill(spaces, ' ');
        builder.append(spaces);
        result.add(builder.toString());
        return result;
    }
}