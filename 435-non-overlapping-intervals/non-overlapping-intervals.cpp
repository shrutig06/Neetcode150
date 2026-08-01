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
            } else {
                lastKept[1]=min(intervals[i][1],lastKept[1]);
                cnt++;
            }
        }

        return cnt;
    }
};