#include <unordered_map>

class Solution {
public:
    bool hasDuplicate(std::vector<int>& nums) {
        std::unordered_map<int, int> table;

        for (int i = 0; i < nums.size(); i++)
        {
            if (table.find(nums[i]) != table.end())
                return true;
            table[nums[i]] = i;
        }
        return false;
    }
};