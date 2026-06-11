class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice=INT_MAX;
        int profit=0;
        int n=prices.size();
        for(int i=0;i<n;i++){
            minPrice=min(minPrice, prices[i]);
            profit=max(profit, prices[i]-minPrice);
        }
        return profit;
    }
};