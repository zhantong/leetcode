class Solution {
    public int leastInterval(char[] tasks, int n) {
        int[] letters = new int[26];
        for (char letter : tasks) {
            letters[letter - 'A']++;
        }
        Arrays.sort(letters);
        int i = 25;
        while (letters[i] == letters[25]) {
            i--;
        }
        return Math.max(tasks.length, (letters[25] - 1) * (n + 1) + 25 - i);
    }
}