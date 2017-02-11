public class Solution {
    public List<String> fizzBuzz(int n) {
        List<String> result = new ArrayList<>(n);
        for (int i = 1; i <= n; i++) {
            String formatted = Integer.toString(i);
            if (i % 3 == 0 && i % 5 == 0) {
                formatted = "FizzBuzz";
            } else if (i % 3 == 0) {
                formatted = "Fizz";
            } else if (i % 5 == 0) {
                formatted = "Buzz";
            }
            result.add(formatted);
        }
        return result;
    }
}