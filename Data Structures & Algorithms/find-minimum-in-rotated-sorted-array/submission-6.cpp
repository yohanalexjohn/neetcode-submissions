class Solution {
public:
    int findMin(vector<int> &nums) {
        int result{nums[0]}; // handle negative 
        int left{0};
        int right(nums.size() - 1);

        while(left <= right){

            if(nums[right] > nums[left]){
                result = min(result, nums[left]);
                break;
            }

            int middle = left + (right - left)/2;
            result = min(result, nums[middle]);

            // Left is sorted
            if(nums[left] <= nums[middle]){
                left = middle + 1;
            }
            // right is sorted
            else{
                right = middle - 1;
            }
        }
        return result;
    }
};
