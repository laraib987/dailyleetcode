class Solution {
public:
int atMostK(vector<int>& nums, int K) {
    int left = 0, count = 0, oddCount = 0;
    for (int right = 0; right < nums.size(); right++) {
        if (nums[right] % 2 != 0) oddCount++; 

        while (oddCount > K) {
            if (nums[left] % 2 != 0) oddCount--; 
            left++;
        }

        count += (right - left + 1);
    }
    return count;
}
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
        
    }
};