class Solution {
//Tabulation and Binary Search
    private:
    int findNextMin(int i, int n, vector<vector<int>>&intervals){
        int l = i, r = n;
        while(l+1<r){
            int m = l+(r-l)/2;
            if(intervals[m][0] < intervals[i][1]){
                l = m;
            }
            else{
                r = m;
            }
        }
        return r;
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    int n = intervals.size();
    sort(intervals.begin(), intervals.end());
   vector<int>dp(n+1, 0);
   for(int i = n-1; i>=0; i--){
    int j = findNextMin(i, n, intervals);
    dp[i] = max(1+dp[j], dp[i+1]);
   }
   return n-dp[0];
    }
};