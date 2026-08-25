class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> output;
        std::unordered_map<string, vector<string>> seen;

        for (const string &str : strs) {
            string key = str;
            std::sort(key.begin(), key.end());

            seen[key].push_back(str);
        }

        // return for each unique key the list of strings to output 
        for (auto& pair : seen) {
            output.push_back(pair.second);
        }
        return output;
    }
};
