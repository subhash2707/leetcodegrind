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
 //int startpos=len-n+1;
class Solution {
    
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
     ListNode* temp=head;
     int len=0;
     while(temp){
        len++;
        temp=temp->next;
     } 
     int startpos=len-n+1;
     if(startpos<1) return nullptr;
     if(startpos==1) return head->next;
     int cnt=0;
     temp=head;
     while(cnt<startpos-2){
        temp=temp->next;
        cnt++;
     }
    if(temp->next)//becos we are trying to fetch temp->next
     temp->next=temp->next->next;
      return head;

    }
};