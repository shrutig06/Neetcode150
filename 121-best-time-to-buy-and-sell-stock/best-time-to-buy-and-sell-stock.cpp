//Shruti
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> minPrefix(n);
        vector<int> maxSuffix(n);
        int minSoFar=prices[0];
        int maxSoFar=prices[n-1];
        for(int i=0;i<n;i++){
            minPrefix[i]= min(prices[i], minSoFar);
            minSoFar=minPrefix[i];
        }
        for(int i=n-1;i>=0;i--){
            maxSuffix[i]=max(prices[i], maxSoFar);
            maxSoFar=maxSuffix[i];
        }
        int profit=0;
        for(int i=0;i<n;i++){
            profit=max(maxSuffix[i]-minPrefix[i], profit);
        }
        return profit;
    }
};