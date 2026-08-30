class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        unique_nums = set(nums)

        result = 0;

        for num in unique_nums:
            if num - 1 not in unique_nums: 
                streak = 1
                while (num + streak) in unique_nums:
                    streak += 1
                result = max(result , streak)
        return result