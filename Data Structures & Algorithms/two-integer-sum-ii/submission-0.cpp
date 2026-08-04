class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;

        while(true) {
            int sum_of_points = numbers[left] + numbers[right];

            if (sum_of_points == target)
                return {left + 1, right + 1};
            
            if (sum_of_points > target) right--;
            else left++;
        }

        return {};
    }
};
