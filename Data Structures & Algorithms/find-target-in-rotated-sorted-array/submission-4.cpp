class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left{0};
        int right(nums.size() -1 );

        while(left <= right){
            int middle = left + (right - left)/2;

            if(nums[middle] == target) return middle;

            // Check which half is sorted
            // left half is sorted
            if(nums[left] <= nums[middle]){
                // Check if we must use this block or bin it
                if((nums[left] <= target) && (target < nums[middle])){
                    right = middle - 1;
                }
                else{
                    left = middle + 1; // bin this section 
                }
            }
            // Right Half must be sorted
            else{
                // Check if we must use this block or bin it
                if((nums[right] >= target) && (target > nums[middle])){
                    left = middle + 1;
                }
                else{
                    right = middle - 1;
                }
            
            }
        }

        return -1;
    }
};
