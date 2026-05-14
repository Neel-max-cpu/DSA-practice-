class Node{
    public:
    int data;
    Node *next;
    Node*prev;
    Node(int data){
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};


struct compare{
    bool operator()(const pair<int,int>&a, const pair<int,int>&b){
        return a.first < b.first;
    }
};

class Twitter {
public:
    // users vs followers ---
    /*
    unordered_map<int,Node*>m;
    // users vs post ---
    vector<pair<int,int>>v;
    */
    
    // better ----
    /*
    // users vs followers ---
    unordered_map<int,unordered_set<int>>m;
    // users vs post ---
    vector<pair<int,int>>v;
    */

    // optimal --
    // users vs following ---
    unordered_map<int,unordered_set<int>>m;
    // users vs post --- save with tweet time
    unordered_map<int, vector<pair<int,int>>>posts;   
    int time; 

    
    Twitter() {        
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        /*
        v.push_back({userId, tweetId});
        */
        posts[userId].push_back({time, tweetId});
        if (posts[userId].size() > 10) {
            posts[userId].erase(posts[userId].begin());
        }
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        /*
        vector<int>data; 
        int n = v.size();       
        //cout<<"size: "<<n<<endl;
        for(int i=n-1; i>=0; i--){
            //cout<<"vi first: "<<v[i].first<<" parent: "<<userId<<endl;                
            if(v[i].first==userId || oneOfFollowing(v[i].first, userId)){
                data.push_back(v[i].second);
                if(data.size()==10) break;
            }
        }
        return data;
        */

        /*
        priority_queue<pair<int,int>, vector<pair<int,int>>, compare>pq;
        for(auto it:posts){
            if(it.first==userId || oneOfFollowing2(userId, it.first)){
                // vector
                for(auto x:it.second){
                    pq.push(x);                    
                }
            }
        }
        vector<int>data;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            data.push_back(it.second);
        }
        return data;
        */

        // similar to merge k sorted list ---
        m[userId].insert(userId);
        priority_queue<pair<int,int>>maxHeap;
        // iterate over the following list
        for(auto user:m[userId]){
            // for that particular user's tweet list -- 'it' is set            
            for(auto tweet:posts[user]){                
                maxHeap.push(tweet);                
            }                        
        }

        vector<int>res;
        while(!maxHeap.empty() && res.size()<10){
            auto x = maxHeap.top();
            maxHeap.pop();
            res.push_back(x.second);
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        /*
        if(m.find(followeeId)!=m.end()){
            // if found
            Node *newNode = new Node(followerId);
            setFollower(m[followeeId], newNode);
            // update
            m[followeeId]=newNode;
        }
        else{
            // not found
            Node *newNode = new Node(followerId);
            m[followeeId]=newNode;
        }
        */
        
        //m[followeeId].insert(followerId);
        
        m[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        /*
        if(m.find(followeeId)!=m.end()){
            // if found            
            unSetFollower(m[followeeId], followerId);                        
        } 
        */
        // update in users vs followers
        //m[followeeId].erase(followerId);
        
        if (m[followerId].count(followeeId)) {
            m[followerId].erase(followeeId);
        }
        
    }

    private:
    void setFollower(Node *head, Node*newNode){        
        newNode->next = head;
        head->prev = newNode;    
    }
    void unsetFollower(Node*head, Node*node){
        Node*dummy = head;
        while(dummy!=node){
            dummy=dummy->next;
        }
        // get prev
        Node *prev = dummy->prev;
        Node*next = dummy->next;

        prev->next = next;
        next->prev = prev;

        node->next = NULL;
        node->prev = NULL;

        delete(node);
    }
    bool oneOfFollowing(int parent, int currentUser){
        if(m[parent].find(currentUser)!=m[parent].end()) return true;
        else return false;
    }
    bool oneOfFollowing2(int user, int followingId){
        if(m[user].find(followingId)!=m[user].end()) return true;
        else return false;
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */