class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        // TC: O(N) for storing count in map + O(mapsize) to build priority + O(k) to traverse priority queue and store res
        // SC: O(k) for resultant vector and O(k) to store in pq
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

       
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }

        for (const auto& [key, value] : mp) {
            pq.push({value, key});
            if (pq.size() > k)
                pq.pop();
        }

        vector<int> res;
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};