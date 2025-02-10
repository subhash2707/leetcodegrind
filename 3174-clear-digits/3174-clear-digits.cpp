class Solution {
public:
    string clearDigits(string s) {
      stack<char>st;
    //traverse s and compare with stack
    for(auto it:s){
        char ch=it;
        if(st.empty() || isalpha(ch)){
            st.push(ch);
        }
        else st.pop();
    }
    s.clear();
    while(!st.empty()) s.push_back(st.top()), st.pop();
    // reverse string 
    reverse(s.begin(),s.end());
    return s; 
    }
};