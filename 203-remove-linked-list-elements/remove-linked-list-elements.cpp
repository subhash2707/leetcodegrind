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
 //NEW APPRACH ->DUMMMY APPROACH
 /*
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
    ListNode* ans=new ListNode(0,head);//before head
    //0->head->2->3->4
    ListNode* dummy=ans;//point to ans
    //move dummy 
    while(dummy!=nullptr){
        //check if dummynext has val
        while(dummy->next!=nullptr && dummy->next->val==val) {
        dummy->next=dummy->next->next;
    }  
    dummy=dummy->next;
    }
    //change ans
    ListNode* res=ans->next;
    delete ans;
    return res;
    }
};
*/



/*
/ --------AS USUAL ------------

class Solution {
    void del(ListNode* &curr,ListNode* prev){
     ListNode* temp=curr; 
     curr=curr->next;//move curr 
     prev->next=curr;//change prev->next

     delete temp;
    }
public:
    ListNode* removeElements(ListNode* head, int val) {
     

       // Remove leading nodes with value `val`
       while (head != nullptr && head->val == val) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }
      // If the list becomes empty after removing leading elements
      if (head == nullptr) return nullptr;
        
      ListNode* prev=head;
      ListNode* curr=head->next;
      while(curr!=nullptr){
        if(curr->val==val){
            del(curr,prev);
        } else
        { 
            prev=curr;
            curr=curr->next;
        }
      }
 return head;

    }
};
*/


/*
// dummy method (more clean)

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
    ListNode* ans=new ListNode(0,head);//before head
    ans->next=head;
    ListNode* dummy=ans;

    while(dummy && dummy->next){
        if(dummy->next->val==val){
            ListNode* todelete=dummy->next;
            dummy->next=dummy->next->next;
            delete todelete;
        }else  dummy=dummy->next;
    }
    head=ans->next;
    delete ans;
    return head;
    }
};
*/



class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
    //delete all starting occurences 
    while(head && head->val==val) {
        ListNode* temp=head;
        head=head->next;
        delete temp;
    } 
    //check if head is not null
    if(!head) return nullptr;

    // now delete all occurences after headd
   //only one previos node is enough to delete a.node
    ListNode* mover=head;
    while(mover->next){      // can use prev and curr approach
        if(mover->next->val==val){
            ListNode* todelete=mover->next;
            mover->next=mover->next->next;
            delete todelete;
        }
        else mover=mover->next;
        
    }
    return head;
    }
};






