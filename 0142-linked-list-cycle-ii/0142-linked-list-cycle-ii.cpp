/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 /////////  m1 USING VISITED MAP RETURN ALREADY MARKED NODE
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