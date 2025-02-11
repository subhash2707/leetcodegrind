class Solution {
public:
    string removeOccurrences(string s, string part) {
       while(s.length()>0 && s.find(part)<s.length()){
        s.erase(s.find(part),part.length());
       } 
       return s;
    }

    /*
    string removeOccurrences(string s, string part) {
    // Repeat until no more occurrences of 'part' are found
    while (true) {
        size_t pos = s.find(part);  // Find the substring 'part' in 's'
        
        if (pos != string::npos) {
            s.erase(pos, part.length());  // Erase the substring from the string
        } else {
            break;  // No more occurrences of 'part', exit the loop
        }
    }
    
    return s;  // Return the modified string
}
*/
};