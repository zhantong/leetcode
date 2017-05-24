public class Solution {
    public int nextGreaterElement(int n) {
        char[] s = Integer.toString(n).toCharArray();
        int length = s.length;
        int i = length - 2;
        while (i >= 0) {
            if (s[i] < s[i + 1]) {
                break;
            }
            i--;
        }
        if (i == -1) {
            return -1;
        }
        int j = i + 1;
        char smallest = '9';
        int smallestIndex = -1;
        while (j < length) {
            if (s[j] > s[i] && s[j] <= smallest) {
                smallest = s[j];
                smallestIndex = j;
            }
            j++;
        }
        char temp = s[i];
        s[i] = s[smallestIndex];
        s[smallestIndex] = temp;
        Arrays.sort(s, i + 1, length);
        long result = Long.parseLong(String.valueOf(s));
        if (result > Integer.MAX_VALUE) {
            return -1;
        }
        return (int) result;
    }
}