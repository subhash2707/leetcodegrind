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
 //move two pointers on t1 and t2
 //sum=t1+t2;
 //carry=sum/10;
 //sum%=10;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* head1=l1;
    ListNode* head2=l2;  
    ListNode* newhead=new ListNode(0);
    ListNode* mover=newhead;
    int sum=0;
    int carry=0;
    while(head1 && head2){
        sum=head1->val+head2->val+carry;
        head1=head1->next;
        head2=head2->next;
        carry=sum/10;
        sum%=10;
        ListNode* newnode=new ListNode(sum);
        mover->next=newnode;
        mover=newnode;
    } 
    //either 1 is fully traversed
     while(head1){
       sum=head1->val+carry;
        head1=head1->next;
        carry=sum/10;
        sum%=10;
        ListNode* newnode=new ListNode(sum);
        mover->next=newnode;
        mover=newnode;  
     }
       while(head2){
       sum=head2->val+carry;
        head2=head2->next;
        carry=sum/10;
        sum%=10;
        ListNode* newnode=new ListNode(sum);
        mover->next=newnode;
        mover=newnode;  
     }
     //add carry 
     if(carry){
        ListNode* newnode=new ListNode(carry);
        mover->next=newnode;
        mover=newnode;  
     }
     // freee newhead
     ListNode* res=newhead;
     res=res->next;  //shift pointer
     newhead->next=NULL;
      delete newhead;
      return res;//
    }
};


//tle because of limit of int and long long has limit 
 //1st method get n1 and n2 ans store
 /*
  runtime error: signed integer overflow: 1000000000000000000 * 10 cannot be represented in type 'long long' (solution.cpp)
SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior prog_joined.cpp:32:18
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
     ListNode* t1=l1;
     stack<int>st;
     while(t1!=NULL){
        st.push(t1->val);
         t1=t1->next;
     }
     long long num1=0;
     while(!st.empty()) {
        num1=num1*10+st.top();
        st.pop();
     }

     t1=l2;
    // stack<int>st;use same stack
     while(t1!=NULL){
          st.push(t1->val);
        t1=t1->next;
      
     }
     longlong num2=0;
     while(!st.empty()) {
        num2=num2*10+st.top();
        st.pop();
     }
     //add
    longlong sum=num1+num2;
     //edge case 
     if(sum==0) {
        return new ListNode();//put 0 and return
     }
     ListNode* newhead=new ListNode(0);//new head
     ListNode* mover=newhead;
     while(sum!=0){
        int rem=sum%10;
        ListNode* temp=new ListNode(rem);
        //add it next to mover
        sum/=10;
        mover->next=temp;
        mover=temp;
     }
     //0->a->b->c      a is head
     ListNode* res=newhead->next;
     newhead->next=NULL;
     delete newhead;
     return res;

     
    }
};
*/