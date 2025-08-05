/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

// class Solution {
// public:
 
//  Node* Head(Node*head, unordered_map<Node*,Node*>&mp)
//  {
//     if(head==0)return 0;
//     Node*newHead=new Node(head->val);
//     mp[head]=newHead;
//     newHead->next= Head(head->next,mp);
//     if(head->random)
//     {
//         newHead->random=mp[head->random];
//     }
//      Head(head->next,mp);
//     return newHead;

//  }

//     Node* copyRandomList(Node* head) {
//         unordered_map<Node*,Node*>mp;
//         return Head(head,mp);
//     }
// };

class Solution {
 public:
 Node* copyRandomList(Node* head) {

      if(head==NULL)return NULL;
      Node*it=head;
      while(it)
      {
        Node*cloneNode=new Node(it->val);
        cloneNode->next=it->next;
        it->next=cloneNode;
        it=it->next->next;
      } 

      it=head;
      while(it)
      {
        Node*clonenode=it->next;
        if(it->random!=NULL)
        {
        clonenode->random=it->random->next;
        }
        it=it->next->next;
      }

      it=head;
      Node*clonehead=it->next;
      while(it)
      {
         Node*cloneNode=it->next;
         it->next=it->next->next;
         if(cloneNode->next)
         {
            cloneNode->next=cloneNode->next->next;
         }
         it=it->next;
      }
      return clonehead;
        
    }
 };