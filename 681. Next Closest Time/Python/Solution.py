class Solution:
    def nextClosestTime(self, time):
        """
        :type time: str
        :rtype: str
        """
        nums = [int(time[0]), int(time[1]), int(time[3]), int(time[4])]
        greater = [-1] * 10
        for num in nums:
            if num > 0:
                greater[num - 1] = num
        current = -1
        for i in range(len(greater) - 1, -1, -1):
            if greater[i] != -1:
                current = greater[i]
            greater[i] = current
        min_time = str(min(nums))
        times = list(time)
        if greater[nums[3]] != -1:
            times[4] = str(greater[nums[3]])
        else:
            times[4] = min_time
            if greater[nums[2]] != -1 and greater[nums[2]] < 6:
                times[3] = str(greater[nums[2]])
            else:
                times[3] = min_time
                if greater[nums[1]] != -1 and (nums[0] < 2 or greater[nums[1]] < 4):
                    times[1] = str(greater[nums[1]])
                else:
                    times[1] = min_time
                    if greater[nums[0]] != -1 and greater[nums[0]] < 2:
                        times[0] = str(greater[nums[0]])
                    else:
                        times[0] = min_time
        return ''.join(times)
