/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee *> employees, int id) {
        class Utils {
        public:
            int dfs(Employee *employee, unordered_map<int, Employee *> &infos) {
                int importance = employee->importance;
                for (int child : employee->subordinates) {
                    importance += dfs(infos[child], infos);
                }
                return importance;
            }
        };
        unordered_map<int, Employee *> infos;
        for (Employee *employee : employees) {
            infos[employee->id] = employee;
        }
        Utils utils;
        return utils.dfs(infos[id], infos);
    }
};