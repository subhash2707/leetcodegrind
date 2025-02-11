/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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