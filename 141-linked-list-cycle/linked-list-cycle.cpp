/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /*
 //method1 mark and check
class Solution {
public:
    bool hasCycle(ListNode *head) {
      unordered_map<ListNode*,bool>visited;//mark
       ListNode* temp=head;
       while(temp){
        if(visited[temp]==true) return true;
        visited[temp]=true;
        temp=temp->next;
       }
  return false;
    }
};
*/





//****************M2--- TORTOISE AND HARE
class Solution {
// int slow_fastlen(ListNode* &slow,ListNode* &fast){
//     while(slow!=fast){
//         slow=slow->next;
//     }
// }
public:
    bool hasCycle(ListNode *head) {
    ListNode* fast=head;
    ListNode* slow=head;
    while(fast && fast->next){
        fast=fast->next->next;
        slow=slow->next;
        if(slow==fast) return true;
    }
   return false;
    }
};


