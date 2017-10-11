"""
# Employee info
class Employee:
    def __init__(self, id, importance, subordinates):
        # It's the unique id of each node.
        # unique id of this employee
        self.id = id
        # the importance value of this employee
        self.importance = importance
        # the id of direct subordinates
        self.subordinates = subordinates
"""


class Solution:
    def getImportance(self, employees, id):
        """
        :type employees: Employee
        :type id: int
        :rtype: int
        """

        def dfs(employee, infos):
            importance = employee.importance
            for child in employee.subordinates:
                importance += dfs(infos[child], infos)
            return importance

        infos = {}
        for employee in employees:
            infos[employee.id] = employee
        return dfs(infos[id], infos)
