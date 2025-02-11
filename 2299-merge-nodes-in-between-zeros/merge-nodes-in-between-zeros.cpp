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
     ListNode* arrtoll(vector<int>& v) {
        int n = v.size();
        if (n == 0) return nullptr; // Handle empty case

        ListNode* head = new ListNode(v[0]); // Create first node
        ListNode* tail = head; // Maintain a tail pointer

        for (int i = 1; i < n; i++) {
            ListNode* newnode = new ListNode(v[i]);
            tail->next = newnode;
            tail = newnode; // Move tail forward
        }

        return head;
    }
public:
    ListNode* mergeNodes(ListNode* head) {
    ListNode* temp=head;
    int cnt=0;
    vector<int>ans;
    while(temp){
      if (temp->val == 0) {
    if (cnt > 0) ans.push_back(cnt); // Avoid leading zero
                cnt = 0;
}

        cnt+=temp->val;
        temp=temp->next;
    }  
    return arrtoll(ans);
    }
};