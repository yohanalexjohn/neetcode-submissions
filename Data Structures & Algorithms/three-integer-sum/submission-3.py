class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        ans = []
        temp = []

        nums.sort()

        if nums == []:
            return ans

        for i in range(len(nums)):
            if nums[i] > 0:
                break

            if (i > 0) and (nums[i - 1] == nums[i]):
                continue

            start = i + 1
            end = len(nums) - 1

            while start < end:
                if (nums[i] + nums[start] + nums[end]) > 0:
                    end -= 1

                elif (nums[i] + nums[start] + nums[end]) < 0:
                    start += 1

                else:
                    ans.append([nums[i], nums[start], nums[end]])

                    start += 1
                    end -= 1

                    continue

        for i in range(len(ans)):
            if (i > 0) and (ans[i - 1] == ans[i]):
                continue
            else:
                temp.append(ans[i])

        ans.clear()
        ans = temp.copy()

        return ans

