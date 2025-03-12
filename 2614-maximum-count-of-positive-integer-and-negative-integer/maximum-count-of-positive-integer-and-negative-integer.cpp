// pos=ub(0);n-ans
//neg=lb(-1);ans


class Solution {
public:
    int maximumCount(vector<int>& nums) {
    int posind=upper_bound(nums.begin(),nums.end(),0)-nums.begin();
    int neg=upper_bound(nums.begin(),nums.end(),-1)-nums.begin();
    int pos=nums.size()-posind;
    return max(pos,neg);
    }
};
/*
//very very easey 
// find the pos=upper_bound of 0 
class Solution {
public:
    int maximumCount(vector<int>& nums) {
     int n=nums.size();
     int pos=0;
     int neg=0;
     // pos=upper bound of 0
     int l=0;
     int r=n-1;
     int ans=-1;
     while(l<=r){
        int mid=l+(r-l)/2;
        if(nums[mid]>0){
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
     }   
     pos=n-l;

     //find lower bound of 0
     l=0;
     r=n-1;
     ans=-1;
     while(l<=r){
        int mid=l+(r-l)/2;
        if(nums[mid]<0){
            ans=mid;
            l=mid+1;
            
        }
        else r=mid-1;
     }   
     neg=l;
    
    return max(pos,neg);
}
};
*/