/*
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        long long totalPairs = 1LL * n * (n - 1) / 2;  // Use 1LL to prevent overflow
        unordered_map<int, int> mpp;
        long long goodPairs = 0;

        for (int i = 0; i < n; i++) {
            mpp[nums[i] - i]++;
        }

        for (auto it : mpp) {
            if (it.second > 1) {
                goodPairs += 1LL * it.second * (it.second - 1) / 2; // Correct formula
            }
        }

        return totalPairs - goodPairs;
    }
};
*/



class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
    int n=nums.size();
    long long totalpairs=(long long)n*(n-1)/2;
    unordered_map<int,int>mpp;
    long long cnt=0;
    for(int i=0;i<n;i++){
        mpp[nums[i]-i]++;
    }   
    for(auto it:mpp){
        if(it.second>1) cnt+=(long long)it.second*(it.second-1)/2;;
    } 
    return totalpairs-cnt;

    }
};

