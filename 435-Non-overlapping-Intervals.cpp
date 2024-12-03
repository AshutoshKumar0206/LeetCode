class Solution {
//Sorting
    private:
    static bool cmp(vector<int>&a, vector<int>&b){
        return a[1]<b[1];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    int n = intervals.size();
    sort(intervals.begin(), intervals.end(), cmp);
    int prev = intervals[0][1];
    int cnt = 0; 
    for(int i = 1; i<n; i++){
        if(prev > intervals[i][0]){
            cnt++;
        }
        else{
            prev = intervals[i][1];
        }
    }
    return cnt;
    }
};