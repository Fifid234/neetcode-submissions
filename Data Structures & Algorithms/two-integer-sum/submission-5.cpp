#include <unordered_map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // std::unordered_map<int, int> table;
        // table.reserve(nums.size());

        // for (int i = 0; i < nums.size(); i++)
        // {
        //     int find = target - nums[i];
        //     if (table.find(find) != table.end())
        //         return {table[find], i};
            
        //     table[nums[i]] = i;
        // }

        // return {};
        std::unordered_map<int, int> table;
    
    // Optimization: Prevent rehashing by reserving space upfront
    table.reserve(nums.size()); 

    for (int i = 0; i < nums.size(); ++i) { // Fixed the comma bug here
        int complement = target - nums[i];
        
        // Use an iterator to avoid searching the map twice
        auto it = table.find(complement);
        if (it != table.end()) {
            return {it->second, i};
        }
        
        table[nums[i]] = i;
    }

    return {};
    }
};
