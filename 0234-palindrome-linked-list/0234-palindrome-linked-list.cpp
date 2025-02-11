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
    int mid=length/2;//first mid for even
    ListNode* temp=head;
//     int cnt=0;
//     while(cnt<mid){
//     cnt++;
//    // if(cnt==mid) break;
//     temp=temp->next;
//     }


    for (int i = 0; i < mid; i++) {
    temp = temp->next;
}

    //now we have reached the mid
    // if(len%2==0) rev(mid->next);
    // else rev(mid->next)
    //reverse from mid-next

    ListNode* newhead=reverse(temp);
    
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