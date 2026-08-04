class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        //{distance, point} priority queue is by default max heap
        priority_queue<pair<int,vector<int>>> maxHeap;
        for (auto point : points) {
            int x = point[0], y = point[1];
            int dist = x * x + y * y;
            maxHeap.push({dist, {x,y}});
            if (maxHeap.size() > k)
                maxHeap.pop();
        }

        vector<vector<int>> ans;
        while (!maxHeap.empty()) {
            auto val = maxHeap.top();
            ans.push_back({val.second[0], val.second[1]});
            maxHeap.pop();
        }

        return ans;
    }
};