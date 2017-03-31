public class Solution {
    public String getPermutation(int n, int k) {
        int[] factor = new int[n];
        factor[0] = 1;
        for (int i = 1; i < n; i++) {
            factor[i] = factor[i - 1] * i;
        }
        StringBuilder builder = new StringBuilder();
        k--;
        List<Integer> numbers = new ArrayList<>();
        for (int i = 1; i < 10; i++) {
            numbers.add(i);
        }
        for (int i = n - 1; i >= 0; i--) {
            int number = k / factor[i];
            k %= factor[i];
            builder.append(Integer.toString(numbers.get(number)));
            numbers.remove(number);
        }
        return builder.toString();
    }
}