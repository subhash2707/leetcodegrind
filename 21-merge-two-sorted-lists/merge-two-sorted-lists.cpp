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
//1.using arrr
//2 using two pointer
/*
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
*/



//METHOD 2 USING TWO POINTER
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;

        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;

        while (list1 && list2) {
            if (list1->val <= list2->val) {
                ListNode* newnode = new ListNode(list1->val);
                temp->next = newnode;
                temp = newnode;
                list1 = list1->next;
            } else {
                ListNode* newnode = new ListNode(list2->val);
                temp->next = newnode;
                temp = newnode;
                list2 = list2->next;
            }
        }

        while (list1) {
            ListNode* newnode = new ListNode(list1->val);
            temp->next = newnode;
            temp = newnode;
            list1 = list1->next;
        }

        while (list2) {
            ListNode* newnode = new ListNode(list2->val);
            temp->next = newnode;
            temp = newnode;
            list2 = list2->next;
        }

        return dummy->next;
    }
};
