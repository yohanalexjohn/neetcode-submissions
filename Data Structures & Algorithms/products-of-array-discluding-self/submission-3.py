class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        output = [1] *len(nums)

        ## Brute force
        # for i in range(len(nums)):
        #     product = 1

        #     for j in range(len(nums)):
        #         if i != j:
        #             product *= nums[j]

        #     output.append(product)

        # return output

        ## Prefix and suffix algorithm

        prefix = 1

        for i in range(len(nums)):
            output[i] = prefix
            prefix *= nums[i]
        
        suffix = 1;

        for j in range(len(nums) -1, -1, -1):
            output[j] *= suffix
            suffix *= nums[j]

        return output
