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
    ListNode* sortList(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return head;
        
    ListNode*temp=NULL;
    ListNode*slow=head;
    ListNode*fast=head;
    while(fast!=NULL&&fast->next!=NULL)
    {
        temp=slow;
        slow=slow->next;
        fast=fast->next->next;

    }    
    temp->next=NULL;

    ListNode*l1=sortList(head);
    ListNode*l2=sortList(slow);

    return merge(l1,l2);
    }

   ListNode* merge(ListNode*l1,ListNode*l2)
   {
    ListNode*dummy=new ListNode(0);
    ListNode*ptr=dummy;
    while(l1!=NULL&&l2!=NULL)
    {
        if(l1->val<=l2->val)
        {
            ptr->next=l1;
            l1=l1->next;
            
        }
        else{
            ptr->next=l2;
            l2=l2->next;
        }
         ptr=ptr->next;
    }
    if(l1!=NULL)
    {
        ptr->next=l1;
        l1=l1->next;
    }
    if(l2!=NULL)
    {
        ptr->next=l2;
        l2=l2->next;
    }
    return dummy->next;
   }
};