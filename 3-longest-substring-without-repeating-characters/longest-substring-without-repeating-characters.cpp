class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0,right=0;
        int maxlen=0;
        vector<int> freq(256,0);
        int n=s.length();
        while(right<n){
            char c=s[right];
            while(freq[c]>0){
                freq[s[left]]--;
                left++;
            }
            freq[c]++;
            maxlen=max(maxlen,right-left+1);
            right++;
        }
        return maxlen;

        
    }
};