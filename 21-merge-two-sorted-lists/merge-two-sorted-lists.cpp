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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;
        if(!list2) return list1;

     vector<int>store;
      ListNode* t1=list1;
      while(t1) {
        store.push_back(t1->val);
        t1=t1->next;
      } 
      ListNode* t2=list2;
      while(t2) {
        store.push_back(t2->val);
        t2=t2->next;
      } 
    //  if(store.size()==0) return nullptr;
      //sort store
      sort(store.begin(),store.end());
      // create a new ll
       ListNode* newhead=new  ListNode(store[0]);
        ListNode* temp=newhead;
       for (int i = 1; i < store.size(); i++) {  
    ListNode* newnode = new ListNode(store[i]);
    temp->next = newnode;
    temp = newnode;
}
return newhead;
    }
};