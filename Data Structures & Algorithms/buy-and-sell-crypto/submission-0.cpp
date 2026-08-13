class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int n = prices.size();
        if (n == 1)
            return 0;

        int out = -INT32_MAX;


        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (prices[j] - prices[i] > out)
                    out = prices[j] - prices[i];
            }
        }

        if (out < 0)
            return 0;

        return out;
    }
};
