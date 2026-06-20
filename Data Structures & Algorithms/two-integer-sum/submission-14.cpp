// #include <unordered_map>

// Add this at the top of your file outside the class/function
auto speedup = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> table;
        table.reserve(nums.size());

        for (int i = 0; i < nums.size(); i++)
        {
            int find = target - nums[i];
            if (table.find(find) != table.end())
                return {table[find], i};
            
            table[nums[i]] = i;
        }

        return {};
    }
};
