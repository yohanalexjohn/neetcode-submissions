class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_set<char>charSet;
        int max_length = 0;
        int left = 0;

        for (int r(0); r < s.size(); r++) {
            while (charSet.find(s[r]) != charSet.end()) {
                charSet.erase(s[left]);
                left++;
            }
            charSet.insert(s[r]);
            max_length = std::max(max_length, r - left + 1);
        }

        return max_length;
    }
};
