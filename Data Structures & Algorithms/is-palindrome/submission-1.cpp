class Solution {
public:
    bool isPalindrome(string& s) {
        erase_if(s, [](char c) { 
            return !isalnum(c);
        });

        ranges::transform(s, s.begin(), [](char c) {
            return tolower(c);
        });

        for (int l = 0, r = s.length()-1; l < r; ++l, --r) {
            if (s[l] != s[r])
                return false;
        }

        return true;
    }
};
