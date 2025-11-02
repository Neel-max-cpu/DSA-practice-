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
#include<map>
#include<algorithm>
#include <unordered_map>
using namespace std;
class Solution {
public:
    Node* copyRandomList(Node* head) {
        /*
        Node *temp = head;
        map<Node*, Node*>m;
        while(temp!=NULL){
            Node *newNode = new Node(temp->val);
            m[temp] = newNode;
            temp = temp->next;
        }

        temp = head;
        Node *newHead  = NULL;
        Node *newTail = NULL;
        while(temp!=NULL){
            if(newHead == NULL){
                newHead = m[temp];
                newTail = m[temp];
                newHead->random = temp->random;
            }
            else{
                newTail->next = m[temp];
                newTail = newTail->next;
                newTail->random = temp->random;
            }
            temp = temp->next;
        }

        return newHead;
        */

        // better ---
        /*
        Node* temp = head;
        unordered_map<Node*, Node*> mpp;

        while(temp != NULL){
            Node* newNode = new Node(temp->val);
            mpp[temp] = newNode;
            temp = temp->next;
        }
        
        temp = head;
        while(temp != NULL){
            Node* copyNode = mpp[temp];
            copyNode->next = mpp[temp->next];
            copyNode->random = mpp[temp->random];
            temp = temp->next;
        }
        
        return mpp[head];
        */

        // optimal ----
        Node *temp = head;
        // making the Nodes
        while(temp != NULL){
            // create a copy node
            Node *copyNode = new Node(temp->val);
            // point the copy node to temp->next;
            copyNode->next = temp->next;
            // point the next of temp to copy node
            temp->next = copyNode;

            // move the temp (next of next since copy node is in between)
            temp = temp->next->next;
        }	

        // connecting the randoms
        temp = head;
        while(temp!=NULL){
            // temp of next is a copy node 
            Node *copyNode = temp->next;
            // copy node will point to original's random's next(IF NOT NULL)
            if(temp->random != NULL){
                copyNode->random = temp->random->next;
            }
            else{
                // if null then point it to null
                copyNode->random = NULL;
            }

            temp = temp->next->next;
        }

        // connecting the next pointer/extracting the linkedlist
        Node *dummy = new Node(-1);
        Node *res = dummy;
        temp = head;
        while(temp!=NULL){
            // point the res to the copy node
            res->next = temp->next;
            // release the copy node from the main
            temp->next = temp->next->next;

            // move the res and temp
            res = res->next;
            temp = temp->next;
        }

        return dummy->next;

    }
};