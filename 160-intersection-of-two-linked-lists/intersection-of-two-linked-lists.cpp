/* 3 APPROACHES
1.USE MAP AND MARK THE VISITED
2.FIND DIFFERCE AND MOVE LARGER TO COME AT SAME DISTANCE AND THEN COMPARE BOTH
3.TRAVERSE BOTH BY TWO POINTER THAT START FROM TWO LL AND 
WHEREVER THEY MEET AGAIN IS THE POI
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 //.  METHOD 1 USNG LENGTH 
class Solution {
    int len (ListNode* head){
        ListNode* t=head;
        int cnt=0;
        while(t){
            cnt++;
            t=t->next;
        }
        return cnt;
    }

    ListNode* poi(ListNode* head1,ListNode* head2,int diff){
        //bigger and smalll
        //considering head1 as greater
        ListNode* t1=head1;
        while(diff--){
           t1=t1->next;
        }
        // now both are at same level
        ListNode* t2=head2;
        while(t1 &&t2){
           // if(t1->next==t2->next) return t1->next;
           if(t1==t2) return t1;
            t1=t1->next;
            t2=t2->next;
        }
        return nullptr;

    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
       
        //IF BOTH HAS SAME HEAD THEY MAY INTERSECT
        if(!headA || !headB  ) return nullptr;
       // 
int len1=len(headA);
int len2=len(headB);
int diff=abs(len1-len2);
if(len1>len2) 
        return poi(headA,headB,diff);
    else return poi(headB,headA,diff);
}
};