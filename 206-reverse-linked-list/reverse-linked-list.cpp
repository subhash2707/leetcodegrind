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
 //vve
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* node = nullptr;

        while (head != nullptr) {
            ListNode* temp = head->next;
            head->next = node;
            node = head;
            head = temp;
        }

        return node;        
    }
};



 /*
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
    ListNode* prev=NULL;
    ListNode* curr=head;
    ListNode* forward=NULL;//curr//head

    while(curr){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }   
    return prev; 
    }
};
*/