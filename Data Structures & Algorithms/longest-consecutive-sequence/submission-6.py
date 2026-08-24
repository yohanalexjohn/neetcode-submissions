class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        nums.sort()
        ans = []
        compare_before_delete = []
        prev = nums[0] if nums != [] else 0

        if nums != []:
            ans.append(nums[0])

        for num in nums:
            if (num - prev) == 1:
                ans.append(num)

            if len(ans) >= 2:
                if (ans[len(ans) - 1] - ans[len(ans) - 2]) != 1:
                    temp = ans[len(ans) - 1]
                    if len(compare_before_delete) < len(ans):
                        compare_before_delete = ans.copy()
                        compare_before_delete.pop(len(compare_before_delete) - 1)
                    ans.clear()
                    ans.append(prev)
                    ans.append(temp)

            prev = num

        return (
            len(ans)
            if len(ans) > len(compare_before_delete)
            else len(compare_before_delete)
        )