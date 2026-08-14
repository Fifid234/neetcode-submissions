class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0)
            return 0;

        int substrMaxLen = 1;

        for (int i = 0; i < s.length(); i++)
        {
            unordered_map<char, bool> table;
            int substrLen = 0;
            while (i + substrLen < s.length() && !table.contains(s[i + substrLen])) {
                table[s[i + substrLen]] = true;
                substrLen++;
            }
            if (substrLen > substrMaxLen)
                substrMaxLen = substrLen;
        }

        return substrMaxLen;
    }
};
