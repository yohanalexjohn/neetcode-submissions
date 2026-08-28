class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int>frequency;
        vector<int>output;

        // calculate frequency
        for (int num : nums) {
            frequency[num]++;
        }

        // store buckets of values where index of bucket is the 
        // frequency count
        std::vector<std::vector<int>>bucket(nums.size()+1);
        for(const auto& pair: frequency)
        {
            int num(pair.first);
            int freq(pair.second);
            bucket[freq].push_back(num);
        }

        // extrac top K elements high to low
        for (int i = bucket.size() - 1; i >= 0 && output.size() < k; i--) {
            for (int num : bucket[i]) {
                output.push_back(num);
                if (output.size() == k) {
                    break;
                }
            }
            
        }

        return output;
    }
};
