//sol1
class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
    unordered_set<string>st(bannedWords.begin(),bannedWords.end());
     int cnt =0;//count matches
     //iterate over message and check if bannedword match with bannedword
     for(auto it:message) {
        if(st.find(it)!=st.end()) 
        cnt++;
     }  
     return cnt>1;     
    }
};





/*---.MY SOL(INP TO REMOVE ELEMENT FROM MAP WHEN COUNTED)

class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
     unordered_map<string,int>freq;
     for(auto it:message)
     freq[it]++;

      int cnt=0;
     for(auto it:bannedWords){
        auto found=freq.find(it);
        if(found!=freq.end()){
            cnt+=found->second;
            //remove that element from map
            freq.erase(found->first);
            if(cnt>1) return true;
     }   
    }
   return false;
    }

};
*/