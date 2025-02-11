//sol good
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        ListNode* cur = head;
        stack<ListNode*> stack;
        
        while (cur != nullptr) {
            while (!stack.empty() && stack.top()->val < cur->val) {
                stack.pop();
            }
            stack.push(cur);
            cur = cur->next;
        }
        
        ListNode* nxt = nullptr;
        while (!stack.empty()) {
            cur = stack.top();
            stack.pop();
            cur->next = nxt;
            nxt = cur;
        }
        
        return cur;
    }
};






/*
//my code 
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        // Create a vector to store values
        vector<int> vals;
        ListNode* temp = head;
        while (temp) {
            vals.push_back(temp->val);
            temp = temp->next;
        }  

        // Iterate vector from end and mark in map
        unordered_map<int, bool> mpp; // Stores index -> keep/remove
        int maxi = vals.back(); // Last element as max

        for (int i = vals.size() - 1; i >= 0; i--) {
            if (vals[i] >= maxi) {
                mpp[i] = true; // Keep this index
                maxi = vals[i];
            } else {
                mpp[i] = false; // Remove this index
            }
        }

        // Dummy node to simplify deletion
        ListNode* ans = new ListNode(0, head);
        ListNode* dummy = ans;
        int ind = 0; // Track index in linked list

        // Iterate over the linked list and delete if marked
        while (dummy->next) {
            if (!mpp[ind]) { // If value is marked for deletion
               // ListNode* toDelete = dummy->next;
                dummy->next = dummy->next->next; // Remove node
               // delete toDelete; // Free memory
            } else {
                dummy = dummy->next; // Move forward
            }
            ind++;
        }

        // Return modified list
        head = ans->next;
        delete ans; // Free dummy node
        return head;
    }
};
*/