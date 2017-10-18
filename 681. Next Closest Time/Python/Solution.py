class Solution:
    def nextClosestTime(self, time):
        """
        :type time: str
        :rtype: str
        """
        nums = [int(time[0]), int(time[1]), int(time[3]), int(time[4])]
        nums.sort()
        greater = [-1] * 10
        for num in nums:
            for i in range(num - 1, -1, -1):
                if greater[i] != -1:
                    break
                greater[i] = num
        times = list(time)
        the_min = str(nums[0])
        if greater[int(times[4])] != -1:
            times[4] = str(greater[int(times[4])])
        else:
            times[4] = the_min
            if greater[int(times[3])] != -1 and greater[int(times[3])] < 6:
                times[3] = str(greater[int(times[3])])
            else:
                times[3] = the_min
                if greater[int(times[1])] != -1 and (times[0] < '2' or greater[int(times[1])] < 4):
                    times[1] = str(greater[int(times[1])])
                else:
                    times[1] = the_min
                    if greater[int(times[0])] != -1 and greater[int(times[0])] < 2:
                        times[0] = str(greater[int(times[0])])
                    else:
                        times[0] = the_min
        return ''.join(times)
