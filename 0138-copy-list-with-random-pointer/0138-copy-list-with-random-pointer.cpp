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
        Node *curr = head;
        
        // create copy
        while(curr){
            Node *newNode = new Node(curr->val);
            Node *nextOriginal = curr->next;
            curr->next = newNode;
            newNode->next = nextOriginal;
            curr = nextOriginal;
        }

        curr = head;
        // link random
        while(curr){
            Node *deepCurr = curr->next;
            Node *random = curr->random;
            if(random)
                deepCurr->random = random->next;
            else deepCurr->random = NULL;

            curr = curr->next->next;
        }

        // seperate it
        curr = head;
        Node *copyHead = new Node(-1);
        Node *dummy = copyHead;

        while(curr){
            Node *deepCurr = curr->next;
            dummy->next = deepCurr;

            Node *nextOriginal = deepCurr->next;            
            curr->next = nextOriginal;

            dummy = dummy->next;

            curr = nextOriginal;
        }
        return copyHead->next;

        
    }
};