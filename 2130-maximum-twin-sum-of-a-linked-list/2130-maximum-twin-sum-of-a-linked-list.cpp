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
    ListNode* reverse(ListNode* head){
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(curr!=NULL){
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    ListNode* middle(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    int pairSum(ListNode* head) {
        ListNode* mid=middle(head);
        ListNode* head1=mid->next;
        ListNode* head2=reverse(head1);
        mid->next=NULL;
        int ans=0;
        while(head!=NULL){
            ans=max(ans,head2->val + head->val);
            head=head->next;
            head2=head2->next;
        }
        return ans;
    }
};




/*
 //my sol
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
*/