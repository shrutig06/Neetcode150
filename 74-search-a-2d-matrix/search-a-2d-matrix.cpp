class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int possibleRow=0;

        for(int i=0;i<m;i++){
            if(target==matrix[i][n-1]){
                return true;
            } else if(target<matrix[i][n-1]){
                possibleRow=i;
                break;
            }
        }

        for(int j=0;j<n;j++){
            if(matrix[possibleRow][j]==target) return true;
        }

        return false;
    }
};