class Solution {
public:int countSubarraysWithSumAtMost(vector<int>& nums, int K) {
    if (K < 0) return 0; 
    int left = 0, sum = 0, count = 0;
    for (int right = 0; right < nums.size(); right++) {
        sum += nums[right];
        while (sum > K) {
            sum -= nums[left];
            left++;
        }
        count += (right - left + 1);  
    }
    return count;
}
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return countSubarraysWithSumAtMost(nums, goal) -
           countSubarraysWithSumAtMost(nums, goal - 1);
        
    }
   
};