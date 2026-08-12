class Solution {
public:
    bool isOper(char c) {
        return c == '+' || c == '-' ||
               c == '/' || c == '*';
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (auto&& s : tokens) {
            if (s.length() == 1 && isOper(s[0])) {
                int num2 = st.top();
                st.pop();
                int num1 = st.top();
                st.pop();

                switch(s[0]) {
                case '+':
                    st.push(num1 + num2);
                    break;
                case '-':
                    st.push(num1 - num2);
                    break;
                case '/':
                    st.push(num1 / num2);
                    break;
                case '*':
                    st.push(num1 * num2);
                    break;
                }
                continue;
            }
            st.push(stoi(s));
        }

        return st.top();
    }
};