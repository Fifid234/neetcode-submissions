class Solution {
public:

    string encode(vector<string>& strs) {
        if (strs.size() == 0)
            return "gfg";

        for (int i = 1; i < strs.size(); ++i) {
            strs[0] += "~";
            strs[0] += strs[i];
        }

        return strs[0];
    }

    vector<string> decode(string s) {
        if (s == "gfg")
            return {};
        vector<string> dec;

        int beg = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '~') {
                dec.push_back(s.substr(beg, i - beg));
                ++i;
                beg = i;
                continue;
            }
        }

        dec.push_back(s.substr(beg, s.length() - beg+1));

        return dec;
    }
};
