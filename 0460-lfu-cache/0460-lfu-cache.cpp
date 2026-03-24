class Node{
    public:
    int key, value, freq;
    Node *next, *prev;
    Node(int key, int value){
        this->key = key;
        this->value = value;
        freq = 1;
        next = NULL;
        prev = NULL;
    }
};

class LRUlist{
    public:
    Node*head, *tail;
    int size;
    LRUlist(){
        size = 0;
        head = new Node(-1,-1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;        
    }

    void insert(Node *node){
        // latest near head
        Node *nextHead = head->next;

        head->next = node;
        node->prev = head;

        node->next = nextHead;
        nextHead->prev = node;
        
        size++;
    }

    void unlink(Node *node){
        Node *nextNode = node->next;
        Node *prevNode = node->prev;

        nextNode->prev = prevNode;
        prevNode->next = nextNode;

        node->next = NULL;
        node->prev = NULL;

        size--;
    }

    Node *getLeastUsed(){
        if(size==0) return NULL;
        Node *leastUsed = tail->prev;
        // unlink
        unlink(leastUsed);
        return leastUsed;
    }

    bool empty(){
        return size == 0;
    }
};



class LFUCache {
public:
    // near tail least used -- near head latest (freq, and lru list)
    unordered_map<int, LRUlist*>freqBucket;
    // key and node -- node has key, value and freq
    unordered_map<int,Node*>m;
    int curr, size, minFreq;
    LFUCache(int capacity) {
        size = capacity;
        curr = 0;
        minFreq = 0;
    }
    
    int get(int key) {
        if(size==0) return -1;

        // if not found --
        if(m.find(key)==m.end()) return -1;

        // found --
        Node*node = m[key];
        int value = node->value;
        updateLRUList(node);
        return value;
        
    }
    
    void put(int key, int value) {
        if(size==0) return;

        if(m.find(key)!=m.end()){
            // if found
            Node *node = m[key];
            // update value
            node->value = value;
            updateLRUList(node);
            return;
        }

        // if not found
        if(curr==size){     
            // if size full

            // get list from minFreq
            LRUlist *list = freqBucket[minFreq]; 
            // get the least used (unlinked)
            Node *leastUsed = list->getLeastUsed();
            // delete from the map
            m.erase(leastUsed->key);
            delete(leastUsed);

            curr--;
        }

        Node *node = new Node(key, value);
        // update minFreq
        minFreq = 1;
        if(freqBucket.find(1)==freqBucket.end()){
            // if no list with freq 1 then create
            freqBucket[1] = new LRUlist();
        }
        // insert
        freqBucket[1]->insert(node);
        // insert in map
        m[key] = node;
        curr++;
    }

    private:
    void updateLRUList(Node *node){
        int freq = node->freq;
        // remove the node from the LRU -- but don't delete node
        freqBucket[freq]->unlink(node);

        if(freq==minFreq && freqBucket[freq]->empty()) minFreq++;

        // increase freq --
        node->freq = freq+1;
        int currFreq = node->freq;

        // add the node in the currFreq (if not present create)
        if(freqBucket.find(currFreq)==freqBucket.end()){
            freqBucket[currFreq] = new LRUlist();
        }
        // insert it --
        freqBucket[currFreq]->insert(node);
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */