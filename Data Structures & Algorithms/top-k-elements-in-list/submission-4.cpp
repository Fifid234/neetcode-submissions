// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         unordered_map<int, int> table;

//         for (const auto& n : nums) {
//             table[n]++;
//         }

//         vector<std::pair<int, int>> sortV(table.begin(), table.end());
//         ranges::sort(sortV, ranges::greater{}, &pair<int, int>::second);

//         vector<int> out;

//         int i = 0;
//         for (auto& p : sortV) {
//             if (!(i < k))
//                 break;
            
//             out.push_back(p.first);

//             ++i;
//         }

//         return out;
//     }
// };
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
        for (const auto& [val, freq] : count) { // 1. Use structured binding for readability
            heap.push({freq, val});
            if (heap.size() > k) {
                heap.pop();
            }
        }

        vector<int> res;
        res.reserve(k); // 2. Prevents the vector from constantly resizing in memory
        while (!heap.empty()) { // 3. Safer loop condition than checking index bounds
            res.push_back(heap.top().second);
            heap.pop();
        }
        return res;
    }
};
