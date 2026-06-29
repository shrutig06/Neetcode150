class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();

        vector<int> combinedMatrix;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                combinedMatrix.push_back(matrix[i][j]);
            }
        }

        int l=0, r=combinedMatrix.size()-1;

        while(l<=r){
            int mid=l+(r-l)/2;

            if(combinedMatrix[mid]==target){
                return true;
            } else if(combinedMatrix[mid]>target){
                r=mid-1;
            } else{
                l=mid+1;
            }
        }
        return false;
    }
};