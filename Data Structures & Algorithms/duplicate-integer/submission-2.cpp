class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_map<int,int> seen;

        for(int num(0); num < nums.size();num++)
        {
            if (seen[nums[num]] > 0) {
                return true;
            }
            else
            {
                seen[nums[num]]++;
            }
        }
        return false;
    }
};