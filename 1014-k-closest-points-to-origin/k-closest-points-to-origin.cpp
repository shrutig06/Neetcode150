class Solution {
public:
    struct comp {
        bool operator()(const pair<vector<int>, double>& p1,
                        pair<vector<int>, double>& p2) const {
            return p1.second < p2.second;
        }
    };

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<vector<int>, double>, vector<pair<vector<int>, double>>,
                       comp>
            maxHeap;
        for (auto point : points) {
            int x = point[0], y = point[1];
            double dist = x * x + y * y;
            maxHeap.push({{x, y}, dist});
            if (maxHeap.size() > k)
                maxHeap.pop();
        }

        vector<vector<int>> ans;
        while (!maxHeap.empty()) {
            auto val = maxHeap.top();
            ans.push_back({val.first[0], val.first[1]});
            maxHeap.pop();
        }

        return ans;
    }
};