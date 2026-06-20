class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> table;

        for (const auto& str : strs) {
            string sortedStr = str;
            ranges::sort(sortedStr);

            table[sortedStr].push_back(str);
        }

        vector<vector<string>> out;

        for (auto& p : table) {
            out.push_back(p.second);
        }

        return out;
    }
};
