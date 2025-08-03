class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        set<vector<int>> unique;
        
        for(int i=0;i<nums.size();i++){
            int divisible=0;
            vector<int>arr;
            for(int j=i;j<nums.size();j++){
                arr.push_back(nums[j]);
                if(nums[j]%p==0){
                    divisible++;
                }
                if(divisible>k){
                    break;
                }
                unique.insert(arr);
            }
        }
        return unique.size();
    }
};