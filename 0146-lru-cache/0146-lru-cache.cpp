class Node{
    public:    
    int key;
    int val;
    Node*next;
    Node*prev;
    Node(int key, int val){
        this->key = key;
        this->val = val;
        next = NULL;
        prev = NULL;
    }
};

class LRUCache {
public:
    unordered_map<int, Node*>m;
    int size = 0;
    Node*head;
    Node*tail;
    LRUCache(int capacity) {
        size = capacity;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);

        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(m.find(key)==m.end()){
            // not found
            return -1;
        }
        else{
            int data = m[key]->val;
            // update most resently used
            updateMRU(m[key]);
            return data;
        }
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            // change the value
            m[key]->val = value;
            updateMRU(m[key]);
        }
        else{
            if(m.size()==size){
                // remove the least used
                removeLeastUsed();
            }

            Node *newNode = new Node(key, value);
            addNode(newNode);
            
            // add map
            m[key] = newNode;        
        }
    }

    private:
    void updateMRU(Node*node){        
        // get
        Node*nodeNext = node->next;
        Node*nodePrev = node->prev;

        if(nodeNext==tail && nodePrev==head) return;

        // link
        nodePrev->next = nodeNext;
        nodeNext->prev = nodePrev;     

        // unlink
        node->next = NULL;
        node->prev = NULL;

        // add next to head
        addNode(node);
    }

    void addNode(Node*newNode){
        Node*prevMostUsed = head->next;

        // link new
        head->next = newNode;
        newNode->prev = head;

        // old link
        newNode->next = prevMostUsed;
        prevMostUsed->prev = newNode;
    }

    void removeLeastUsed(){
        // get least used tail
        Node *leastUsed = tail->prev;
        if(leastUsed==head) return;

        // link
        Node*secondLeastUsed = leastUsed->prev;
        secondLeastUsed->next = tail;
        tail->prev = secondLeastUsed;

        // then remove from map
        int key = leastUsed->key;
        m.erase(key);

        // unlink
        leastUsed->next = NULL;
        leastUsed->prev = NULL;

        // delete
        delete(leastUsed);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */