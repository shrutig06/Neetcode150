class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=1, high=nums.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]<nums[mid-1]) return nums[mid];
            if(nums[mid]>nums[high]) {
                low=mid+1;
            }else{
                high=mid-1;
            }
        }

        return nums[0];
    }
};