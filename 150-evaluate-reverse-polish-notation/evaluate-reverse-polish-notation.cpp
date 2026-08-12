class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] != "*" && tokens[i] != "+" && tokens[i] != "/" &&
                tokens[i] != "-") {
                st.push(stoi(tokens[i]));
            } else {
                int val1 = st.top();
                st.pop();
                int val2 = st.top();
                st.pop();
                int ans = 1;
                if (tokens[i] == "+")
                    ans = val2 + val1;
                else if (tokens[i] == "-")
                    ans = val2 - val1;
                else if (tokens[i] == "*")
                    ans = val2 * val1;
                else
                    ans = val2 / val1;
                st.push(ans);
            }
        }
        return st.top();
    }
};