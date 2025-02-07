//VVE NOT AGAIN
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
      //traverse the llinked lista 
      vector<int>nums;
       ListNode* temp=head;
     while(temp!=nullptr){
         nums.push_back(temp->val);
         temp=temp->next;
     }
     int n=nums.size();
     int sum=0;
     int maxsum=0;
     for(int i=0;i<nums.size()/2;i++){
    // sum=nums[i]+nums[n-1-i];
     maxsum=max(maxsum,nums[i]+nums[n-1-i]);
     } 
     return maxsum;
    }
};