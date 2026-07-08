class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minSoFar=prices[0];
        int maxProfit=INT_MIN;

        for(int i=0;i<prices.size();i++){
            minSoFar=min(prices[i], minSoFar);
            maxProfit=max(maxProfit, prices[i]-minSoFar);
        }

        return maxProfit;
    }
};