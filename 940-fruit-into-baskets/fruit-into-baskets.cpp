class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0, right = 0;
    int n = fruits.size();
    int maxLen = 0;

    unordered_map<int, int> basket; 

    while (right < n) {
        basket[fruits[right]]++;  
        while (basket.size() > 2) {
            basket[fruits[left]]--;
            if (basket[fruits[left]] == 0) {
                basket.erase(fruits[left]);
            }
            left++;
        }

        maxLen = max(maxLen, right - left + 1);
        right++;
    }

    return maxLen;
        
    }
};