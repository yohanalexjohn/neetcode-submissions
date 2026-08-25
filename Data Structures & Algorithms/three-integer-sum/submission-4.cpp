class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> output;

        std::sort(nums.begin(), nums.end());

        // big iteraotr less than the 2 left and right pointers
        for (int i = 0; i < nums.size() - 2; i++) {
            // If smallest number is positive, sum can never be 0
            if (nums[i] > 0) {
                break;
            }

            // Skip duplicate elements for the first position
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            // now do the left and right pointer   
            int left = i +1;
            int right = nums.size() -1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    output.push_back({nums[i], nums[left], nums[right]});
                    // skip left duplicate
                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }

                    // skip left duplicate
                    while (right > left && nums[right] == nums[right - 1]) {
                        right--;
                    }
                    left++;
                    right--;
                }
                else if (sum > 0) {
                    right--;
                }
                else
                {
                    left++;
                }
            }
        }

        return output;
    }
};
