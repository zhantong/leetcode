class Solution:
    def findDuplicate(self, paths):
        """
        :type paths: List[str]
        :rtype: List[List[str]]
        """
        memory = {}
        for path in paths:
            splits = path.split()
            base = splits[0]
            for file in splits[1:]:
                left_parent_index = file.find('(')
                key = file[left_parent_index + 1:]
                if key not in memory:
                    memory[key] = []
                memory[key].append(base + '/' + file[:left_parent_index])
        return [value for value in memory.values() if len(value) > 1]
