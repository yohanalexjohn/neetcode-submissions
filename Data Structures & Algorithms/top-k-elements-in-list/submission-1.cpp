class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> counts;
        for (int num : nums) counts[num]++;

        // // Buckets index represents frequency (max frequency is nums.size())
        // std::vector<std::vector<int>> buckets(nums.size() + 1);
        // for (auto& pair : counts) {
        //     int num = pair.first;
        //     int freq = pair.second;
        //     buckets[freq].push_back(num);
        // }

        // std::vector<int> output;
        // // Walk backward from highest frequency down to 1
        // for (int i = buckets.size() - 1; i >= 0 && output.size() < k; i--) {
        //     for (int num : buckets[i]) {
        //         output.push_back(num);
        //         if (output.size() == k) break;
        //     }
        // }

        // return output;

        // Min-heap storing pairs of {frequency, number}
        std::priority_queue<std::pair<int, int>, 
                            std::vector<std::pair<int, int>>, 
                            std::greater<std::pair<int, int>>> minHeap;

        for(auto & pair : counts)
        {
            minHeap.push({pair.second, pair.first});
            if (minHeap.size() > k) {
                minHeap.pop(); // remove lowest freq element
            }
        }

        std::vector<int>output;
        while (!minHeap.empty()) {
            output.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return output;
    }
};
