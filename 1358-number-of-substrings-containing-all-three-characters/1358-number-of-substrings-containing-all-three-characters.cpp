class Solution {
public:
    int numberOfSubstrings(string s) {
     int n=s.size();
     vector<int>lastseen(3,-1);//stores last seen of characters
     int cnt=0;
     for(int i=0;i<n;i++){
      lastseen[s[i]-'a']=i;
      //if all are present cnt no. of substring
      if(lastseen[0]!=-1 && lastseen[1]!=-1 && lastseen[2]!=-1){
        //starting point of min valid substr
int min_index=min(lastseen[0],(min(lastseen[1],lastseen[2])));// 
        cnt+=min_index+1;
      }
     } 
     return cnt;  
    }
};