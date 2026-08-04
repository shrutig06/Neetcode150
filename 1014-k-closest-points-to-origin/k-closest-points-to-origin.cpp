class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        //{distance, point index} priority queue is by default max heap
        priority_queue<pair<int,int>> maxHeap;
        for (int i=0;i<points.size();i++) {
            int x = points[i][0], y = points[i][1];
            int dist = x * x + y * y;
            maxHeap.push({dist,i});
            if (maxHeap.size() > k)
                maxHeap.pop();
        }

        vector<vector<int>> ans;
        while (!maxHeap.empty()) {
            auto idx = maxHeap.top().second;
            ans.push_back({points[idx][0], points[idx][1]});
            maxHeap.pop();
        }

        return ans;
    }
};