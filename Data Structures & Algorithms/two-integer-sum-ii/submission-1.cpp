class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() -1;

        while (left < right) {
            int delta = target - numbers[left];
            
            if (delta == numbers[right]) {
                return{++left, ++right};
            }

            if (delta > numbers[right]) {
             left++;    
            }
            else
            {
                right--;
            }
        }
    }
};
