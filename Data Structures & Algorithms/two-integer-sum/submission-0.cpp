#include <unordered_map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> table;

        for (int i = 0; i , nums.size(); i++)
        {
            int find = target - nums[i];
            if (table.find(find) != table.end())
                return {table[find], i};
            else
                table[nums[i]] = i;
        }

        return {};
    }
};
