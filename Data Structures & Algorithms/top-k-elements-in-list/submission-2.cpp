class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> table;

        for (const auto& n : nums) {
            table[n]++;
        }

        std::vector<std::pair<int, int>> sortV(table.begin(), table.end());
        std::ranges::sort(sortV, std::ranges::greater{}, &std::pair<int, int>::second);

        vector<int> out;

        int i = 0;
        for (auto& p : sortV) {
            if (!(i < k))
                break;
            
            out.push_back(p.first);

            ++i;
        }

        return out;
    }
};
