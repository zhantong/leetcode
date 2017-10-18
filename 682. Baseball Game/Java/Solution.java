class Solution {
    public int calPoints(String[] ops) {
        Stack<Integer> history = new Stack<>();
        for (String op : ops) {
            switch (op) {
            case "+":
                history.push(history.peek() + history.get(history.size() - 2));
                break;
            case "D":
                history.push(history.peek() * 2);
                break;
            case "C":
                history.pop();
                break;
            default:
                history.push(Integer.parseInt(op));
            }
        }
        int result = 0;
        for (int item : history) {
            result += item;
        }
        return result;
    }
}