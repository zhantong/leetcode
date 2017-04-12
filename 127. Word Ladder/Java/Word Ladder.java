public class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        Queue<String> queue = new LinkedList<>();
        queue.add(beginWord);
        Set<String> set = new HashSet<>(wordList);
        int count = 0;
        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                String current = queue.poll();
                if (current.equals(endWord)) {
                    return count + 1;
                }
                for (int j = 0; j < current.length(); j++) {
                    char[] letters = current.toCharArray();
                    for (char letter = 'a'; letter <= 'z'; letter++) {
                        letters[j] = letter;
                        String temp = new String(letters);
                        if (set.contains(temp)) {
                            queue.add(temp);
                            set.remove(temp);
                        }
                    }
                }
            }
            count++;
        }
        return 0;
    }
}