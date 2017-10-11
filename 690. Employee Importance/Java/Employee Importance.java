/*
// Employee info
class Employee {
    // It's the unique id of each node;
    // unique id of this employee
    public int id;
    // the importance value of this employee
    public int importance;
    // the id of direct subordinates
    public List<Integer> subordinates;
};
*/
class Solution {
    public int getImportance(List<Employee> employees, int id) {
        class Utils {
            int dfs(Employee employee, Map<Integer, Employee> infos) {
                int importance = employee.importance;
                for (int child : employee.subordinates) {
                    importance += dfs(infos.get(child), infos);
                }
                return importance;
            }
        }
        Map<Integer, Employee> infos = new HashMap<>();
        for (Employee employee : employees) {
            infos.put(employee.id, employee);
        }
        Utils utils = new Utils();
        return utils.dfs(infos.get(id), infos);
    }
}