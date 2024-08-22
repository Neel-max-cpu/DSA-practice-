class LFUCache {
public:
    class Node{
        public:
        int key;
        int val;
        int count;

        Node *next;
        Node *prev;

        Node(int _key, int _val){
            key = _key;
            val = _val;
            count = 1;
        }
    };

    // list is available in c++ stl(see there too)
    class List {
        public:
        int size;
        Node *head;
        Node *tail;
        List(){
            head = new Node(0,0);
            tail = new Node(0,0);
            head->next = tail;
            tail->prev = head;
            size = 0;   
        }

        // similar to LRU -- 
        void insertAfterHead(Node *node){
            Node *temp = head->next;

            head->next = node;
            node->prev = head;

            node->next = temp;
            temp->prev = node;

            size++;
        }

        // similar to LRU -- 
        void deleteNode(Node *node){
            Node *previous = node->prev;
            Node *next_one = node->next;
            
            previous->next = next_one;
            next_one->prev = previous;
            
            size--;
        }
    };

    map<int,Node*>keyNode;
    map<int,List*>freqListMap;
    int maxSizeCache;
    int minFreq;
    int curSizeCache;

    LFUCache(int capacity) {
        maxSizeCache = capacity;
        minFreq = 0;
        curSizeCache = 0; 
    }


    void updateFreqList(Node *node){
        // remove from the map -- int, node*
        keyNode.erase(node->key);
        
        // remove from the list -- int, list* (since it would get updated like in LRU) 
        // get the freq(count) then delete node in that count 
        // eg in the map lets say there are 3 vaue (3,3) (2,2) and (1,1) all put function 
        // so in the freqmap 1-> (3,3), (2,2) and (1,1)
        // then get(1)
        // so delete it from 1 freq and put it in 2
        // 1 -> (3,3), (2,2)
        // 2 -> (1,1)
        freqListMap[node->count]->deleteNode(node);
        
        if(node->count == minFreq && freqListMap[node->count]->size==0){
            minFreq++;
        }

        List *nextHigherFreqList = new List();
        // check if next freq is present or not 
        if(freqListMap.find(node->count+1)!=freqListMap.end()){
            // if present - put the list in the new created list
            nextHigherFreqList = freqListMap[node->count+1];
        }
        // increase the count
        node->count += 1;
        // put the element after the head
        nextHigherFreqList->insertAfterHead(node);
        // update the freqMp
        freqListMap[node->count] = nextHigherFreqList;
        // update the keyNode map
        keyNode[node->key] = node;
    }
    
    int get(int key) {
        if(keyNode.find(key)!=keyNode.end()){
            // if present take the node's address 
            Node *node = keyNode[key];
            int val = node->val;
            // update the node since accessed
            updateFreqList(node);
            return val;
        }
        // doesn't present
        return -1;
    }
    
    void put(int key, int value) {
        // if max capacity is 0 ele is not allowed (edge case)
        if(maxSizeCache==0) return;
        
        // find if key is present or not 
        if(keyNode.find(key)!=keyNode.end()){
            Node *node = keyNode[key];
            // update the node's value
            node->val = value;
            updateFreqList(node);
        }
        else{
            if(curSizeCache==maxSizeCache){
                // if remove the least freq use - take the list of the minFreq
                List *list = freqListMap[minFreq];
                // erase from key node - value present previous of tail like LRU
                keyNode.erase(list->tail->prev->key);
                // remove from freqMap
                freqListMap[minFreq]->deleteNode(list->tail->prev);
                curSizeCache--;
            }
            // increase it since new ele to be inserted
            curSizeCache++;
            minFreq = 1;
            List *listFreq = new List();
            if(freqListMap.find(minFreq) != freqListMap.end()){
                listFreq = freqListMap[minFreq];
            }
            Node *node = new Node(key, value);
            listFreq->insertAfterHead(node);
            keyNode[key] = node;
            freqListMap[minFreq] = listFreq;
        }

        
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */