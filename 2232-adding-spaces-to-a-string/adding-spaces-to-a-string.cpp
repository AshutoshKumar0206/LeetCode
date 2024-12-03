class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string st;
        int j = 0;
        for(int i = 0; i<spaces.size(); i++){
            while(j!=spaces[i]){
                st += s[j]; 
                j++;
            }
            if(j == spaces[i]){
                st += " ";
                st += s[j];
                j++;
            }
        }
        while(j!=s.length()){
            st+=s[j];
            j++;
        }
        return st;
    }
};