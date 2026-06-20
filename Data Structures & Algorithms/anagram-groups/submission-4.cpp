// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         unordered_map<string, vector<string>> table;

//         for (const auto& str : strs) {
//             string sortedStr = str;
//             ranges::sort(sortedStr);

//             table[sortedStr].push_back(str);
//         }

//         vector<vector<string>> out;

//         for (auto& p : table) {
//             out.push_back(p.second);
//         }

//         return out;
//     }
// };
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> res;
        for (const auto& s : strs) {
            vector<int> count(26, 0);
            for (char c : s) {
                count[c - 'a']++;
            }
            string key = to_string(count[0]);
            for (int i = 1; i < 26; ++i) {
                key += ',' + to_string(count[i]);
            }
            res[key].push_back(s);
        }
        vector<vector<string>> result;
        for (const auto& pair : res) {
            result.push_back(pair.second);
        }
        return result;
    }
};