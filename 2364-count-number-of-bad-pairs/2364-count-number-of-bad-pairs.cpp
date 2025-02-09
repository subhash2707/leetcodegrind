class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
    int n=nums.size();
    long long totalpairs=(long long)n*(n-1)/2;
    unordered_map<int,int>mpp;
    int cnt=0;
    for(int i=0;i<n;i++){
        mpp[nums[i]-i]++;
    }   
    for(auto it:mpp){
        if(it.second>1) cnt+=(long long)it.second*(it.second-1)/2;;
    } 
    return totalpairs-cnt;

    }
};