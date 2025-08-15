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
    bool isPalindrome(ListNode* head) {
        if(head==nullptr||head->next==nullptr)return true;
        ListNode*ptr=head;
        ListNode* fast = head;
      stack<int>st;
      while(fast!=nullptr&&fast->next!=nullptr)
      {
        st.push(ptr->val);
        ptr=ptr->next;
        fast = fast->next->next;
      }
      if (fast != nullptr)
            ptr = ptr->next;
      while(!st.empty()&&ptr!=nullptr)
      {
        if(st.top()==ptr->val)
        {
            st.pop();
            ptr=ptr->next;
        }
        else{
            return false;
        }
      }
      return true;
    }
};