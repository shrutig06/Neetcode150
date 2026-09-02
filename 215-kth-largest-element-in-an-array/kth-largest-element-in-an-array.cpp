class Solution {
public:
 int partition_algo(vector<int>& nums, int L, int R){
    int i=L+1, j=R;

    int pivot=L;

    while(i<=j){
        if(nums[i]<nums[pivot] && nums[j]>nums[pivot]){
            swap(nums[i], nums[j]);
            i++; j--;
        }

        if(nums[i]>=nums[pivot]) i++;
        if(nums[j]<=nums[pivot]) j--;
    }
    swap(nums[j], nums[pivot]);
    return j;
 }
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int L = 0, R = n - 1;
        int pivot_idx=0;
        while(true){
            pivot_idx=partition_algo(nums, L, R);

            if(pivot_idx==k-1){
               break;
            }else if(pivot_idx>k-1){
                R=pivot_idx-1;
            }else{
                L=pivot_idx+1;
            }
        }

        return nums[pivot_idx];
    }
};