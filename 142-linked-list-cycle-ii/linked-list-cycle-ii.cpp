/*
1.usnign visited map
2.using fast and slow pointer
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 /////////  m1 USING VISITED MAP RETURN ALREADY MARKED NODE
 //TC-(N),SC-(ON)
 /*
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
     ListNode* temp=head;
     int timer=1;
     unordered_map<ListNode*,bool>visited;//node pos
     while(temp){
        if(visited[temp])// already visited node is start
          return temp;
          
           visited[temp]=true;
          temp=temp->next;  
     }  
     return nullptr; 
    }
};
*/





// M2 ---- FAST AND SLOW POINTERS
// start slow from head and when it meets fast again then it is stating point of cycle
class Solution {
ListNode* starting(ListNode* fast,ListNode* head){
    ListNode* temp=head;
    while(temp!=fast){
        temp=temp->next;
        fast=fast->next;
    }
    return fast;//temp

}
public:
    ListNode *detectCycle(ListNode *head) {
     ListNode* fast=head;
     ListNode* slow=head;
    while(fast && fast->next){
        fast=fast->next->next;
        slow=slow->next;
        if(slow==fast)
        return starting(fast,head);
    }
   return nullptr;
    }
};