#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        // Fix: Map number to its frequency count
        std::unordered_map<int, int> freqMap;

        // Count frequencies
        for(int num : nums) {
            freqMap[num]++;
        }

        // Convert map to a vector of pairs so we can sort it
        vector<pair<int, int>> freqList(freqMap.begin(), freqMap.end());

        // Sort by frequency in descending order
        sort(freqList.begin(), freqList.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second;
        });

        // Extract the top k elements
        for(int i = 0; i < k && i < freqList.size(); i++) {
            result.push_back(freqList[i].first);
        }

        return result;
    }
};