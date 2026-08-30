class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int output(0);

        // Brute force
        // for (int i = 0; i < s.size(); i++) {
        //     unordered_set<char> charSet;

        //     for (int j = i; j < s.size(); j++) {
        //         if (charSet.find(s[j]) != charSet.end()) {
        //             break;
        //         }
        //         charSet.insert(s[j]);
        //     }

        //     output = max(output, (int)charSet.size());
        // }

        // Sliding window

        unordered_map<char, int> mp;
        int l(0);

        for (int r = 0; r < s.size(); r++) {
            if(mp.find(s[r]) != mp.end())
            {
                // jump to the next position 
                l = max(mp[s[r]] +1, l);
            }

            mp[s[r]] = r;
            output = max(output, r - l + 1);
        }

        return output;
    }
};
