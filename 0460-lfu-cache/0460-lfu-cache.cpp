class Node{
    public:
    int key;
    int value;
    int freq;
    Node *prev;
    Node*next;
    Node(int key, int value){
        this->key = key;
        this->value = value;
        freq = 1;
        prev = NULL;
        next = NULL;
    }
};

class LRUList{
    public:
    // inside we have atlease 1 head and 1 tail
    Node *head;
    Node *tail;    
    int size;
    LRUList(){
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;        
        size=0;
    }

    // insert
    void insert(Node *listNode){
        // near the tail newest
        // -1<>2<>3<>-1      --add 4(after 3 --- -1 end tail)
        Node *lastNode = tail->prev;    //3
        lastNode->next = listNode;      //3>4
        listNode->prev = lastNode;      //3<>4
        listNode->next = tail;          //4>-1
        tail->prev = listNode;          //4<>-1
        size++;
    }

    // remove
    void remove(Node*listNode){
        // -1<>2<>3<>4<>-1      --remove 3
        Node*nextNode = listNode->next;     //4
        Node *prevNode = listNode->prev;    //2

        prevNode->next = nextNode;  //2>4
        nextNode->prev = prevNode;  //2<>4

        listNode->prev = NULL;
        listNode->next = NULL;
        size--;        

        //don't delete
        //delete(listNode);
    }

    Node*popLRU(){
        if(size==0) return NULL;
        Node*listNode = head->next;
        remove(listNode);
        return listNode;
    }    

    // empty
    bool empty(){
        return size == 0;
    }

};

class LFUCache {
public:    
    unordered_map<int, LRUList*> freqBucket; // near head oldest - near tail newest
    unordered_map<int,Node*>m;    // key and node
    int curr;
    int size;
    int minFreq;
    LFUCache(int capacity) {
        size = capacity;
        curr = 0;
        minFreq = 0;
    }
    
    int get(int key) {
        if(size==0) return -1;
        
        // not present in the map
        if(m.find(key)==m.end()){             
            return -1;
        }
        else{
            Node *listNode = m[key];
            int value = listNode->value;
            // remove from the freq and add it to freq+1   
            updateLRUList(listNode);
            return value;
        }
    }
    
    void put(int key, int value) {
        if(size==0) return;

        if(m.find(key)!=m.end()){
            // if found
            Node *listNode = m[key];
            listNode->value = value;
            updateLRUList(listNode);
            return;
        }

        if(curr == size){
            LRUList *list = freqBucket[minFreq];
            // free from lru (don't delete - now)
            Node *delNode = list->popLRU();
            // delete from map
            m.erase(delNode->key);
            // finally delete then node
            delete(delNode);
            curr--;
        }

        Node *listNode = new Node(key, value);
        minFreq = 1;
        if(freqBucket.find(1)==freqBucket.end()){
            // if no lrulist with freq 1
            freqBucket[1] = new LRUList();
        }
        // insert in lru list
        freqBucket[1]->insert(listNode);
        // insert in map
        m[key]=listNode;
        curr++;
    }    

    private:    
    void updateLRUList(Node*listNode){
        // here we are detatching the list -- don't delete

        int freq = listNode->freq;                
        freqBucket[freq]->remove(listNode); 

        if(freq==minFreq && freqBucket[freq]->empty()) minFreq++;        

        // increase freq
        listNode->freq = freq+1;
        int currFreq = listNode->freq;

        // add in the new LRU list if size small
        if(freqBucket.find(currFreq) == freqBucket.end()){
            // if freq not there then add
            freqBucket[currFreq] = new LRUList();
        }
        // add it 
        freqBucket[currFreq]->insert(listNode);
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */