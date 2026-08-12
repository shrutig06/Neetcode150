class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (auto& token : tokens) {
            if (token != "*" && token != "+" && token != "/" && token != "-") {
                st.push(stoi(token));
            } else {
                int val1 = st.top();
                st.pop();
                int val2 = st.top();
                st.pop();
                int ans = 1;
                if (token == "+")
                    ans = val2 + val1;
                else if (token == "-")
                    ans = val2 - val1;
                else if (token == "*")
                    ans = val2 * val1;
                else
                    ans = val2 / val1;
                st.push(ans);
            }
        }
        return st.top();
    }
};