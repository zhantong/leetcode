public class Solution {
    public String simplifyPath(String path) {
        List<String> stack = new ArrayList<>();
        for (String item : path.split("/")) {
            if (item.isEmpty() || item.equals(".")) {
                continue;
            }
            if (item.equals("..")) {
                if (!stack.isEmpty()) {
                    stack.remove(stack.size() - 1);
                }
            } else {
                stack.add(item);
            }
        }
        StringBuilder builder = new StringBuilder();
        for (String item : stack) {
            builder.append("/");
            builder.append(item);
        }
        if (builder.length() == 0) {
            builder.append("/");
        }
        return builder.toString();
    }
}