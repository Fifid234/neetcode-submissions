class Solution 
{
public:
    bool isPalindrome(string& s) 
    {
        int l = 0;
        int r = s.length()-1;

        while(r > l) {
            while (!isalnum(s[l]) && l < r)
                l++;
            
            while (!isalnum(s[r]) && r > l)
                r--;
            
            if (tolower(s[l]) == tolower(s[r])) {
                l++;
                r--;
            }
            else
                return false;
        }

        return true;
    }
};
