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