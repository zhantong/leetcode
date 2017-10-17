public class Solution {
    public double[] calcEquation(String[][] equations, double[] values, String[][] queries) {
        class Utils {
            double dfs(String start, String end, Map<String, List<String>> graph, Map<String, List<Double>> graphValue, Set<String> current, double currentValue) {
                if (current.contains(start) || !graph.containsKey(start)) {
                    return 0.0;
                }
                if (start.equals(end)) {
                    return currentValue;
                }
                current.add(start);
                List<String> nodes = graph.get(start);
                List<Double> values = graphValue.get(start);
                for (int i = 0; i < nodes.size(); i++) {
                    double got = dfs(nodes.get(i), end, graph, graphValue, current, currentValue * values.get(i));
                    if (got != 0.0) {
                        current.remove(start);
                        return got;
                    }
                }
                current.remove(start);
                return 0.0;
            }
        }
        double[] result = new double[queries.length];
        Map<String, List<String>> graph = new HashMap<>();
        Map<String, List<Double>> graphValue = new HashMap<>();
        for (int i = 0; i < equations.length; i++) {
            String[] equation = equations[i];
            double value = values[i];
            if (!graph.containsKey(equation[0])) {
                graph.put(equation[0], new ArrayList<>());
                graphValue.putIfAbsent(equation[0], new ArrayList<>());
            }
            graph.get(equation[0]).add(equation[1]);
            graphValue.get(equation[0]).add(value);
            if (!graph.containsKey(equation[1])) {
                graph.put(equation[1], new ArrayList<>());
                graphValue.putIfAbsent(equation[1], new ArrayList<>());
            }
            graph.get(equation[1]).add(equation[0]);
            graphValue.get(equation[1]).add(1.0 / value);
        }
        Utils utils = new Utils();
        for (int i = 0; i < queries.length; i++) {
            String[] query = queries[i];
            result[i] = utils.dfs(query[0], query[1], graph, graphValue, new HashSet<>(), 1.0);
            if (result[i] == 0.0) {
                result[i] = -1.0;
            }
        }
        return result;
    }
}