class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<int, int> counter;
        priority_queue<int, vector<int>> maxHeap;
        queue<pair<int, int>> q;
        int time = 0;

        for (char c : tasks) {
            counter[c]++;
        }

        for(auto [key, value] : counter) maxHeap.push(value);

        while (!maxHeap.empty() || !q.empty()) {
            time += 1;
            if (!maxHeap.empty()) {
                int val = maxHeap.top();
                maxHeap.pop();
                // pushing remaining count and next possible time
                if (val - 1 > 0) {
                    q.push({val - 1, time + n});
                }
            }

            if (!q.empty() && q.front().second == time) {
                maxHeap.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};