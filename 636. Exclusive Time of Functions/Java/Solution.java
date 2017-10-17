class Solution {
    public int[] exclusiveTime(int n, List<String> logs) {
        Stack<Integer> stack = new Stack<>();
        int[] result = new int[n];
        int current = 0;
        for (String log : logs) {
            String[] splits = log.split(":");
            int time = Integer.parseInt(splits[2]);
            if (splits[1].equals("start")) {
                if (!stack.empty()) {
                    result[stack.peek()] += time - current;
                }
                current = time;
                stack.push(Integer.parseInt(splits[0]));
            } else {
                result[stack.peek()] += time - current + 1;
                current = time + 1;
                stack.pop();
            }
        }
        return result;
    }
}