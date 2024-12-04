class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
   int i = 0, j = 0;
   int n = sentence.length();
   int m = searchWord.length();
   int string_Number = 1;
   bool flag = false;
   while(i<n && j<m){
       if(sentence[i] == ' '){
         string_Number++;
         i++;
         if(j<m){
            j = 0;
         }
       }
        else if(sentence[i] == searchWord[j] && i == 0){
        flag = true;
        j++;
        i++;
       }
       else if(sentence[i] == searchWord[j] && flag == true){
        j++;
        i++;
       }
       else if(sentence[i] == searchWord[j] && sentence[i-1] == ' '){
        flag = true;
        j++;
        i++;
       }
       else if(sentence[i] != searchWord[j]){
        i++;
        j = 0;
        flag = false;
       }
       else{
        i++;
       }
   }
   if(j<m){
    return -1;
   }
   return string_Number;
    }
};