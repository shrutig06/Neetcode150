class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums;
        vector<int> prefix(n), res(n);
        prefix[0]=1;
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]*nums[i-1];
        }
        int rightProd=1;

        for(int i=n-1;i>=0;i--){
            res[i]=prefix[i]*rightProd;
            rightProd=nums[i]*rightProd;
        }
        return res;
    }
};