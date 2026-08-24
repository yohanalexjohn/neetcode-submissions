#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Map to store: {sorted_string_key -> list of original anagrams}
        std::unordered_map<string, vector<string>> anagramMap;

        for (string s : strs) {
            string key = s;
            std::sort(key.begin(), key.end()); // Sort letters to create a universal key
            anagramMap[key].push_back(s);      // Group original string under this key
        }

        // Extract all the grouped vectors from the hash map
        vector<vector<string>> result;
        for (auto& pair : anagramMap) {
            result.push_back(pair.second);
        }

        return result;
    }
};