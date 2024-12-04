class Solution {
    //Recursion
    private:
    bool formSquare(int index, int sum_sides, int req_equal_sides, int square_sides,
    vector<int>& matchsticks, vector<int>&vis){
        if(square_sides == 1){
            return true;
        }
        if(sum_sides == req_equal_sides){
            return formSquare(0, 0, req_equal_sides, square_sides-1, matchsticks, vis);
        }
        for(int j = index; j<matchsticks.size(); j++){
            if(vis[j] || (sum_sides + matchsticks[j] > req_equal_sides)) continue;
            vis[j] = 1;
            if(formSquare(j+1, sum_sides + matchsticks[j], req_equal_sides,
            square_sides, matchsticks, vis))return true;
            vis[j] = 0;
        }
        return false;
    }
public:
    bool makesquare(vector<int>& matchsticks) {
        long long total_matchsticks = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        int req_equal_sides = total_matchsticks/4;
        int square_sides = 4;
        if(matchsticks.size()<4 || total_matchsticks % 4) return false;
        vector<int>vis(matchsticks.size(), 0);
        return formSquare(0, 0, req_equal_sides, square_sides, matchsticks, vis);
    }
};