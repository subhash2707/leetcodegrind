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
    pair<ListNode*,ListNode*> middleandprev(ListNode* &head){
        ListNode* slow=head,*fast=head;
        ListNode* prev=NULL;//prev of slow
        while(fast!=nullptr && fast->next!=nullptr){
            fast=fast->next->next;
            //first increment prev 
            prev=slow;
            slow=slow->next;

        }
        return {slow,prev};
    }
public:
    ListNode* deleteMiddle(ListNode* head) {
        //if no or one node
        if(head==nullptr || head->next==nullptr) return nullptr;
      pair<ListNode*,ListNode*>midd_prev=middleandprev(head);
      ListNode* middle= midd_prev.first;
      ListNode* prev=midd_prev.second;

     prev->next=middle->next;
     delete middle;
     return head; 
    }
};