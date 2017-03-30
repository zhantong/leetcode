public class Solution {
    public List<String> findItinerary(String[][] tickets) {
        class Utils {
            boolean dfs(Map<String, List<String>> travels, List<String> result, String start, int length) {
                result.add(start);
                if (!travels.containsKey(start) || travels.get(start).isEmpty()) {
                    if (result.size() == length) {
                        return true;
                    }
                    result.remove(result.size() - 1);
                    return false;
                }
                for (int i = 0; i < travels.get(start).size(); i++) {
                    String newStart = travels.get(start).get(i);
                    travels.get(start).remove(i);
                    if (dfs(travels, result, newStart, length)) {
                        return true;
                    }
                    travels.get(start).add(i, newStart);
                }
                result.remove(result.size() - 1);
                return false;
            }
        }
        Map<String, List<String>> travels = new HashMap<>();
        for (String[] ticket : tickets) {
            if (!travels.containsKey(ticket[0])) {
                travels.put(ticket[0], new ArrayList<>());
            }
            travels.get(ticket[0]).add(ticket[1]);
        }
        for (List<String> item : travels.values()) {
            Collections.sort(item);
        }
        String start = "JFK";
        List<String> result = new ArrayList<>();
        Utils utils = new Utils();
        utils.dfs(travels, result, start, tickets.length + 1);
        return result;
    }
}