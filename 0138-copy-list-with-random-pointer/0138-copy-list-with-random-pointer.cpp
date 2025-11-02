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

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        // use hashmap
        unordered_map<Node*,Node*>m;        

        Node*temp = head;        

        // create copy and store in hashmap
        while(temp){
            Node *newNode = new Node(temp->val);
            m[temp] = newNode;
            temp = temp->next;
        }

        // now point the next and the random pointers        
        temp = head;
        while(temp){
            // curr copy
            Node *curr = m[temp];
            //find the next copy
            if(m.find(temp->next)!=m.end()){
                // next copy
                Node *next = m[temp->next];
                //point curr next to next
                curr->next = next; 
            }

            //find the random copy
            if(m.find(temp->random)!=m.end()){
                // random copy
                Node*random = m[temp->random];
                //point curr random to random
                curr->random = random;
            }

            temp = temp->next;
        }
        //return copy of head
        return m[head];


    }
};