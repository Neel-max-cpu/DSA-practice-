class Node{
    public:
    int key;
    int value;
    Node*prev;
    Node *next;

    Node(int key, int value){
        this->key = key;
        this->value = value;
        prev = NULL;
        next = NULL;
    }
};

class LRUCache {
public:
    int size;
    int curr;
    unordered_map<int,Node*>m;
    Node *head = new Node(-1,-1);
    Node *tail = new Node(-1,-1);
    
    LRUCache(int capacity) {
        size = capacity;
        curr = 0;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(m.find(key)==m.end()) return -1;
        else{

            Node *listNode = m[key];
            int val = listNode->value;
            //change postion in the linkedlist
            changePos(listNode);
            return val;
        }
        
    }
    
    void put(int key, int value) {
        if(m.find(key)==m.end()){
            if(curr>=size){
                //remove least used
                removeLeastUsed();            
            }
            Node *newNode = new Node(key, value);
            m[key] = newNode;        
            // put value in linkedlist
            putVal(newNode);
        }
        else{
            // if found -- update the key and put the value behind the head
            Node *listNode = m[key];
            listNode->value = value;
            changePos(listNode);
        }
    }

    private:
    void changePos(Node*listNode){
        // eg 3 in null<>1<>2<>3<>4<>null
        Node *nextToList = listNode->next;      // 4
        Node *prevToList = listNode->prev;      // 2

        //connect prev and next of list
        nextToList->prev = prevToList;       // 2<4
        prevToList->next = nextToList;      //2<>4

        Node *nextToHead = head->next;      // 1
        head->next = listNode;              // null>3
        listNode->prev = head;              // null<>3
        listNode->next = nextToHead;        // null<>3>1
        nextToHead->prev = listNode;        // null<>3<>1
    }

    void putVal(Node*newNode){
        // null<>1<>2<>4<>null -- lets say put 3 after head(null)
        Node*nextToHead = head->next;    //1
        head->next = newNode;       // null>3
        newNode->prev = head;        // null<>3  --chain done        

        newNode->next = nextToHead;     //null<>3>1
        nextToHead->prev = newNode;      // null<>3<>1 -- chain done
        curr++;
    }
    void removeLeastUsed(){
        // null<>1<>2<>3<>4<>null -- lets say remove 3 (4 tail)
        Node *leastUsed = tail->prev;    // 3
        Node *nextLeastUsed = leastUsed->prev;  //2

        // make 3 alone
        leastUsed->next = NULL;
        leastUsed->prev = NULL;

        tail->prev = nextLeastUsed;     // 2<4
        nextLeastUsed->next = tail;     //2<>4  -- chain done

        // remove from map
        m.erase(leastUsed->key);
        
        // remove 3
        delete(leastUsed);

        curr--;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */