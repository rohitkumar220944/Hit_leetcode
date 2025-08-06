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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>ans{-1,-1};
        ListNode*prev=head;
         if(prev==nullptr)return ans;
        ListNode*curr=head->next;
        if(curr==nullptr)return ans;
        ListNode*nxt=head->next->next;
        if(nxt==nullptr)return ans;
        int firstcp=-1;
        int lastcp=-1;
        int mindist=INT_MAX;
        int i=1;
        while(nxt)
        {
            bool iscrt=((curr->val>prev->val && curr->val>nxt->val)||
                         (curr->val<prev->val && curr->val<nxt->val)) ?    true:false;
          if(iscrt && firstcp==-1)
          {
            firstcp=i;
            lastcp=i;
          } 
          else if(iscrt)
          {
            mindist=min(mindist,i-lastcp);
            lastcp=i;
          }
          i++;
          prev=prev->next;
           curr=curr->next;
            nxt=nxt->next;
        }
        if(lastcp==firstcp)
        {return ans;}
        else{
            ans[0]=mindist;
            ans[1]=lastcp-firstcp;
        }
        return ans;
        
    }
};