class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minSoFar = 1e9;
        int n = prices.size();
        int maxProfit = -1;
        for(int i = 0;i < n;i++){
            minSoFar = min(minSoFar,prices[i]);
            maxProfit = max(maxProfit,(prices[i] - minSoFar));
        }
        return maxProfit;
    }
};