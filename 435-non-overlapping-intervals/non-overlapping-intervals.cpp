class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int cnt=0;
        vector<int> lastKept(2);
        lastKept=intervals[0];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]>=lastKept[1]){
                lastKept=intervals[i];
            } else if(lastKept[1]>intervals[i][0]){
                if(lastKept[1]>intervals[i][1]) lastKept=intervals[i];
                cnt++;
            }
        }

        return cnt;
    }
};