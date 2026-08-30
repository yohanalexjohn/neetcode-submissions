class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> store(nums.begin(), nums.end());
        int output(0);

        // Brute force
        for (int num : store) {
            // ONLY start counting if 'num - 1' is NOT in the set!
            // If 'num - 1' exists, 'num' is NOT the start of a sequence.
           if (store.find(num - 1) == store.end()) {
            int streak(1);
            int current = num;

            while(store.find(current + 1) != store.end())
            {
                streak++;
                current++;
            }
            output = max(output, streak);
           }
        }
        return output;
    }
};
