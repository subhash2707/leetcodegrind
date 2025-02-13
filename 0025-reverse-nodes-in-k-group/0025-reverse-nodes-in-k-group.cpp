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
   private:
    int getLength(ListNode* head) {

    int length = 0;

    ListNode* temp =head;

    while(temp != NULL) {
        length++;
        temp = temp -> next;
    }

    return length;
    }
public:
   // ListNode* reverseKGroup(ListNode* head, int k) {
      




    ListNode* reverseK(ListNode* &head, int k, int length) {
        
    //Base case
    if(head == NULL || head -> next == NULL || k == 1 || length < k)
        return head;
    
    //Step 1 : Reverse first k nodes
    ListNode* nxt = NULL;
    ListNode* curr = head;
    ListNode* prev = NULL;

    int count = 1;

    while(curr != NULL && count <= k) {

        nxt = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = nxt;
        count++;
    }

    //Step 2 : Reverse next k nodes using recursion
    if(nxt != NULL) { 
        head -> next = reverseK(nxt, k, (length - k));
    }

    //Step 3 : Return head of the reversed linked list
    head = prev;
    
    return head;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

    int len = getLength(head);
    
    return reverseK(head, k, len);
    }  
    
};
*/

class Solution {
public:
    ListNode* _reverseKGroup(ListNode* head, int size, int k){
        if(head==nullptr || size<k) return head;
        ListNode* prev=nullptr, *cur=head, *next=nullptr;
        int count=0;
        while(cur!=nullptr && count<k){
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
            count++;
        }
        head->next=_reverseKGroup(next, size-k, k);
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int size=0;
        ListNode* temp=head, *root;
        while(temp!=nullptr){
            temp=temp->next;
            size++;
        }
        return _reverseKGroup(head, size, k);
    }
};