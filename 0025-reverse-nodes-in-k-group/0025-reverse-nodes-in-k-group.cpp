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
     ListNode* reverseList(ListNode* head) {
        ListNode*prev=nullptr;
        ListNode*curr=head;
     
        while(curr!=nullptr)
        {   
            ListNode*forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
         
        }
        return prev;
          
        }
    ListNode* getK(ListNode* head, int k)
    {
        ListNode* temp=head;
        k-=1;
        while(temp!=nullptr && k>0)
        {
            k--;
            temp=temp->next;
        }
        return temp;

    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode*prevNode=nullptr;
        while(temp!=nullptr)
        {
            ListNode* kth=getK(temp,k);
            if(kth==nullptr)
            {
                if(prevNode)prevNode->next=temp;
                break;
            }

            ListNode* nextNode=kth->next;
            kth->next=nullptr;
            reverseList(temp);
            if(temp==head)
            {
                head=kth;
            }
            else
            {
                prevNode->next=kth;
            }
            prevNode=temp;
            temp=nextNode;

        }
        return head;

        
    }
};