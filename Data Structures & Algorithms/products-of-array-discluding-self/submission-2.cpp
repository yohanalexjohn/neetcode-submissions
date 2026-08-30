class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> output(nums.size(),1);

        // // Brute force
        // for(int num(0); num < nums.size(); num++)
        // {
        //     int product(1);

        //     for(int i(0); i < nums.size(); i++)
        //     {
        //         if (i != num) {
        //             product *= nums[i];
        //         } 
        //     }

        //     output.push_back(product);
        // }
        // return output;


        // Prefix suffix algorithm
        int prefix(1);

        for(int i(0); i < nums.size(); i++)
        {
            output[i] = prefix;
            prefix *= nums[i]; 
        }

        int suffix(1);
        for (int j(nums.size() - 1); j >= 0; j-- )
        {
            output[j] *= suffix;
            suffix *= nums[j];
        }

        return output;
    }
};
