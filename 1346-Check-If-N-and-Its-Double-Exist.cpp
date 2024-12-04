class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int,int>m;
        m[0] = -1;
        for(int i = 0; i<arr.size(); i++){
           m[arr[i]]++;
        }
        for(auto i:arr){
          if(i%2 != 0){
            if(m[i+i]){
                return true;
            }
          }
          else if(m[i/2]){
            return true;
          }
        }
 return false;
    }
};