class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> strsSort = strs;

        for (int i = 0; i < strsSort.size(); ++i)
            ranges::sort(strsSort[i]);


        vector<vector<string>> out;

        for(int i = 0; i < strs.size(); ++i) {
            vector<string> curr;

            bool isUnique = true;
            for (int j = 0; j < out.size(); ++j) {
                string t = out[j][0];
                ranges::sort(t);
                if (strsSort[i] != t)
                    continue;
                
                isUnique = false;
                break;
            }
            if (!isUnique) continue;
            curr.push_back(strs[i]);

            for(int j = 0; j < strs.size(); ++j) {
                if (i == j) continue;

                if (strsSort[i] != strsSort[j])
                    continue;
                
                curr.push_back(strs[j]);
            }

            out.push_back(curr);
        }

        return out;
    }
};
