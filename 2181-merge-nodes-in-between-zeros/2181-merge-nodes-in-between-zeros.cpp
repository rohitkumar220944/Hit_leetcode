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
    ListNode* mergeNodes(ListNode* head) {
        if(head==nullptr)return head;
        ListNode*slow=head;
        ListNode*fast=head->next;
        int sum=0;
         ListNode*newnode=0;
         
        while(fast!=nullptr)
        {
        if(fast->val!=0)
        {
            sum+=fast->val;
        
        }
        else{
            slow->val=sum;
            newnode=slow;
            slow=slow->next;
            sum=0;
          }
          fast=fast->next;
        }
        ListNode*temp=newnode->next;
        newnode->next=0;
        while(temp)
        {
            ListNode*nxt=temp->next;
            delete temp;
            temp=nxt;
        }
        return head;  
    
        
        
    }
};