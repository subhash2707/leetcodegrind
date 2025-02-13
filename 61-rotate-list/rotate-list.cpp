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
    int len(ListNode* head){
        int len=0;
        ListNode* temp=head;
        while(temp){
            temp=temp->next;
            len++;
        }
        return len;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;
     //move to len-kth node
       int length=len(head);
       k=k%length;
       //edge case
       if(k==0) return head;//no revere
       int cnt=length-k;
       ListNode* temp=head;
       while(temp){
       cnt--;
       if(cnt==0) break;
       temp=temp->next;
       }
        ListNode* newhead=temp->next; 
         
        temp->next=nullptr;
         ListNode* temp2=newhead;
         
        while(temp2->next){
            temp2=temp2->next;
        }//now temp is tail so connect to head
        temp2->next=head;
        return newhead;
    }
};