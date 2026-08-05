class Solution {
public:
    bool isValid(string& s) {
        if (s.empty())
            return true;
        if (s.length() == 1)
            return false;
        
        stack<char> stc;

        for (int i = 0; i < s.length(); i++) {
            if (!stc.empty() && isPair(stc.top(), s[i]))
                stc.pop();
            else
                stc.push(s[i]);
        }

        return stc.empty();
    }

    bool isPair(const char& c1, const char& c2)
    {
        return (c1 == '{' && c2 == '}') || 
               (c1 == '(' && c2 == ')') ||
               (c1 == '[' && c2 == ']');
    }
};
