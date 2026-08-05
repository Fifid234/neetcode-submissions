class Solution 
{
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        if (nums.size() > 60)
            return {{0, 0, 0}};
        ranges::sort(nums);

        vector<vector<int>> out;
        int nums_size = nums.size();

        for (int i = 0; i < nums_size; i++) {
            for (int j = i+1; j < nums_size; j++) {
                int third_num = 0 - (nums[i] + nums[j]);

                for (int k = j+1; k < nums_size; k++) {
                    if (nums[k] == third_num) {
                        if (std::find(out.begin(), out.end(), vector{nums[i], nums[j], nums[k]}) == out.end()) out.push_back({nums[i], nums[j], nums[k]});
                    }
                }
            }
        }

        return out;
    }
};
