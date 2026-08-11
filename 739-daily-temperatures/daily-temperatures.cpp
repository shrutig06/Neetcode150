class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> st;
        vector<int> ans(temperatures.size());

        for (int i = temperatures.size() - 1; i >= 0; i--) {
            while (!st.empty() && st.top().first <= temperatures[i]) {
                st.pop();
            }
            ans[i] = st.empty() ? 0 : st.top().second - i;
            st.push({temperatures[i], i});
        }
        return ans;
    }
};