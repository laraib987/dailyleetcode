class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false;

    vector<char> mapS(256, 0);  
    vector<char> mapT(256, 0);  

    for (int i = 0; i < s.length(); i++) {
        char c1 = s[i], c2 = t[i];

        // Check if mapping exists and is consistent
        if ((mapS[c1] && mapS[c1] != c2) || (mapT[c2] && mapT[c2] != c1)) {
            return false;
        }


        mapS[c1] = c2;
        mapT[c2] = c1;
    }

    return true;
        
    }
};