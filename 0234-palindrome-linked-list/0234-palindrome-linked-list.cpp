//1.use stack
//2.use fast and slow pointer and reverse after slow
//3. find len and revese after len/2
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


// m1 usign stack
class Solution {
    public:

 bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        stack<int>st;
ListNode* temp=head;
while(temp){
    st.push(temp->val);
    temp=temp->next;
}

temp=head;
while(temp){
    if(temp->val!=st.top()) return false;
    st.pop();
    temp=temp->next;
}
return true;
        
 }
 };




/*
// METHOD 3-------------------------------------------
class Solution {
    int len(ListNode* head) {
        ListNode* temp = head;
        int cnt = 0;
        while (temp) {
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }

    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;

        int length = len(head);
        int mid = length / 2;
        
        ListNode* temp = head;
        for (int i = 0; i < mid - 1; i++) {  // Move temp to node before mid
            temp = temp->next;
        }

        // Reverse second half and update the link
        ListNode* newhead = reverse(temp->next);
        // temp->next = reverse(secondHalf);
        // ListNode* newhead = temp->next;

        // Compare first half and reversed second half
        ListNode* t1 = head;
        ListNode* t2 = newhead;
      //  bool isPalin = true;
        while (t2) {
            if (t1->val != t2->val) {
               return false;
            }
            t1 = t1->next;
            t2 = t2->next;
        }

        // Restore the original second half
     //   temp->next = reverse(newhead);

        return true;
    }
};
*/





 
class Solution {
int len(ListNode* &head){
 ListNode* temp=head;
 int cnt=0;
 while(temp){
    cnt++;
    temp=temp->next;
 }  
 return cnt;
}


ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

public:
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
    int length=len(head);
    int mid=(length+1)/2;//first mid for even
    ListNode* temp=head;
//     int cnt=0;
//     while(cnt<mid){
//     cnt++;
//    // if(cnt==mid) break;
//     temp=temp->next;
//     }


    // for (int i = 1; i < mid; i++) {
    // temp = temp->next;
    int cnt=0;
    while(cnt<mid){
        cnt++;
        if(cnt==mid) break;
        temp=temp->next;
    }


    //now we have reached the mid
    // if(len%2==0) rev(mid->next);
    // else rev(mid->next)
    //reverse from mid-next
  //  if (length % 2 != 0) temp = temp->next;
    
    ListNode* newhead=reverse(temp->next);
    
    ListNode* t1=head;
    ListNode* t2=newhead;
    //travers from both ends
    while(t2){
        if(t1->val!=t2->val) return false;
        t1=t1->next;
        t2=t2->next;
    }
 return true;
    }
};
