public class Solution {
    Map<String, List<Integer>> memory;

    public Solution() {
        memory = new HashMap<>();
    }

    public List<Integer> diffWaysToCompute(String input) {
        if (memory.containsKey(input)) {
            return memory.get(input);
        }
        List<Integer> result = new ArrayList<>();
        for (int i = 0; i < input.length(); i++) {
            char letter = input.charAt(i);
            if (letter == '+' || letter == '-' || letter == '*') {
                List<Integer> leftVals = diffWaysToCompute(input.substring(0, i));
                List<Integer> rightVals = diffWaysToCompute(input.substring(i + 1));
                for (int left : leftVals) {
                    for (int right : rightVals) {
                        int current = 0;
                        switch (letter) {
                        case '+':
                            current = left + right;
                            break;
                        case '-':
                            current = left - right;
                            break;
                        case '*':
                            current = left * right;
                        }
                        result.add(current);
                    }
                }
            }
        }
        if (result.isEmpty()) {
            result.add(Integer.valueOf(input));
        }
        memory.put(input, result);
        return result;
    }
}