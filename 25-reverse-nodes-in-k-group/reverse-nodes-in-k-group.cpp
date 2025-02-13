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
 /*
class Solution {
    void reverse(  ListNode* head){
              ListNode*  curr=head;
          ListNode* prev=NULL;
                ListNode*   forward=NULL;
                while(curr) {
                    forward=curr->next;
                    curr->next=prev;
                    prev=curr;
                    curr=forward;
                }
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
     ListNode* curr=head;
     ListNode* dummy=new  ListNode(0);
     dummy->next=head;
     while(curr){
     ListNode*   last=curr;
     int move=k-1;
        while(last && (move)--){
            last=last->next;
        }//if last is null means all traversed
        // if last is not null then reverse
        if(!last) break;
       // if(last){ //reverse
        else{
          ListNode* newhead=last->next;//head of new grpup
          last->next=nullptr;//to reverese
          reverse(curr);
          curr->next=newhead;
          curr=newhead;
         // last=newhead;//already done at starting
     } 
     }
     return dummy->next;
    }
};
*/







class Solution {
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev; // New head after reversal
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prevGroupEnd = dummy;

        while (true) {
            ListNode* kthNode = prevGroupEnd;
            int count = k;
            while (count-- && kthNode) {
                kthNode = kthNode->next;
            }

            if (!kthNode) break;  // Not enough nodes left to reverse

            ListNode* groupStart = prevGroupEnd->next;
            ListNode* nextGroupStart = kthNode->next;

            kthNode->next = nullptr;  // Temporarily break the link
            prevGroupEnd->next = reverse(groupStart);

            groupStart->next = nextGroupStart;  // Reconnect to next group
            prevGroupEnd = groupStart;
        }

        return dummy->next;
    }
};
