class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
     sort(begin(nums), end(nums));
     vector<int>dp(nums.size(), 1);
     vector<int>prev_index(nums.size(), -1);

     int max_Length = 1;
     int last_seen_index = 0;
     for(int i = 1; i<nums.size(); i++){
      for(int j = 0; j<i; j++){
        if(nums[i] % nums[j] == 0){
            if(dp[i] < dp[j]+1){
                dp[i] = dp[j]+1;
                prev_index[i] = j;
            }
            if(dp[i] > max_Length){
                max_Length = dp[i];
                last_seen_index = i;
            }
        }
      }
     }
     vector<int>res;
     while(last_seen_index != -1){
        res.push_back(nums[last_seen_index]);
        last_seen_index = prev_index[last_seen_index];
     }
    return res;
    }
};