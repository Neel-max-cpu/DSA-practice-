class LRUCache {
public:
    class Node {
        public:
            int key;
            int val;
            Node *next;
            Node *prev;
            
            Node(int _key, int _val){
                key = _key;
                val = _val;
            }
    };

    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1,-1);

    int cap;
    unordered_map<int,Node*>m;

    LRUCache(int capacity) {
        // initially 
        cap = capacity;
        head->next = tail;
        tail->prev = head;    
    }

    void insertAfterHead(Node *node){
        // save the head's next
        Node *temp = head->next;

        // head of next = node and node's prev = head;
        head->next = node;
        node->prev = head;

        // and node's next = temp and temp's prev = node;
        node->next = temp;
        temp->prev = node;
    }

    void deleteNode(Node* node){
        Node *previous = node->prev;
        Node *nextone = node->next;

        previous->next = nextone;
        nextone->prev = previous;
    }
    
    int get(int key) {
        // if the map doesnt have the key
        if(m.find(key) == m.end()) return -1;

        Node *node = m[key];

        // since most recent one move it forward
        deleteNode(node);
        insertAfterHead(node);

        // return the node value;
        return node->val;
    }
    
    // method 1 ---
    /*
    void put(int key, int value) {
        // if the map has it
        if(m.find(key) != m.end()){
            // change the value;
            Node *node = m[key];
            node->val = value;
            
            // make it most recently used            
            deleteNode(node);
            insertAfterHead(node);            
        }
        else{
            // 2 case if not present
            
            // size exceeds
            if(m.size()==cap){
                // delete the least recently used(near the tail)
                Node *node = tail->prev;
                // remove from the map
                m.erase(node->key);
                deleteNode(node);

                // create a newNode and insert it;
                Node *newNode = new Node(key, value);
                insertAfterHead(newNode);
                // make changes in the map
                m[key] = newNode;
            }
            else{
                // size doesn't exceeds
                
                // create a newNode and insert it;
                Node *newNode = new Node(key, value);
                insertAfterHead(newNode);
                // make changes in the map
                m[key] = newNode;
            }
        }
    }
    */

    // method 2 -- better writing
    void put(int key, int value) {
        // if key found 
        if(m.find(key) != m.end()){
            Node *node = m[key];
            // update the value;
            node->val = value;                        
            // since most currently used
            deleteNode(node);
            insertAfterHead(node);                        
            return;
        }

        if(m.size()==cap){
            // remove the least used
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        // create a newNode
        Node *newNode = new Node(key, value);
        insertAfterHead(newNode);
        // update the map
        m[key] = newNode;
    }
    
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */