class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int>count(3,0);
        int left=0,right=0;
        int res=0;
        for(int right=0;right<s.size();right++){
            count[s[right]-'a']++;
            while(count[0]>0&&count[1]>0&&count[2]>0){
                res+=s.length()-right;
                count[s[left]-'a']--;
                left++;
            }
        }
        return res;
        
    }
};