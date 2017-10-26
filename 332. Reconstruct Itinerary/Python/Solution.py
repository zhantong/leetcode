class Solution(object):
    def findItinerary(self, tickets):
        """
        :type tickets: List[List[str]]
        :rtype: List[str]
        """
        def dfs(travels, result, start, length):
            result.append(start)
            if start not in travels or not travels[start]:
                if len(result) == length:
                    return True
                result.pop()
                return False
            for i in range(len(travels[start])):
                new_start = travels[start].pop(i)
                if dfs(travels, result, new_start, length):
                    return True
                travels[start].insert(i, new_start)
            result.pop()

        travels = {}
        for ticket in tickets:
            if ticket[0] not in travels:
                travels[ticket[0]] = []
            travels[ticket[0]].append(ticket[1])
        for item in travels.values():
            item.sort()
        start = 'JFK'
        result = []
        dfs(travels, result, start, len(tickets) + 1)
        return result
