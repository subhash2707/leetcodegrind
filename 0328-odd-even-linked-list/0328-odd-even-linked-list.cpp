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
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head;
    ListNode* oddhead=head;
    delete head;
    ListNode* oddmover=oddhead;
    ListNode* evenhead=oddhead->next;
    //delete original list
   // head->next=nullptr;
    // ListNode* evenmover=evenhead;
    // ListNode* dummy=new ListNode(-1);
    // ListNode* mover=odd;
    while(oddhead!=nullptr){
       if(oddmover->next->next )
        oddmover=oddmover->next->next;   
    }   
    oddmover->next=evenhead;
     //move 
     while(oddhead!=nullptr){
     if(oddmover->next->next )
        oddmover=oddmover->next->next;   
    } 
   // delete head;
    return oddhead;
    }
};
*/
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
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        
        ListNode* oddhead = head;
        ListNode* oddmover = oddhead;
        ListNode* evenhead = oddhead->next;
        ListNode* evenmover = evenhead;

        // Process odd and even nodes together
        while(oddmover->next && evenmover->next) {
            oddmover->next = evenmover->next;
            oddmover = oddmover->next;

            evenmover->next = oddmover->next;
            evenmover = evenmover->next;
        }

        oddmover->next = evenhead; // Connect odd list to even list

        return oddhead;
    }
};


