class LRUCache {
public:
class Node{
    public:
    int key;
    int val;
    Node* next;
    Node* prev;
    Node(int _key,int _val){
        key=_key;
        val=_val;
    }
};
int cap;
Node* head = new Node(-1,-1);
Node* tail = new Node(-1,-1);
unordered_map<int,Node*>mpp;
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
        
    }
    void delrear(Node* node){
        Node* front = node->next;
        Node* previous = node->prev;
        previous->next = front;
        front->prev = previous;
    }
    void insertfront(Node* node){
        Node* temp = head->next;
        head->next = node;
        node->prev = head;
        node->next = temp;
        temp->prev = node;

    }
    int get(int key) {
       if(mpp.find(key)!=mpp.end()){
        Node* node = mpp[key];
        delrear(node);
        insertfront(node);
        return node->val;
       }
       return -1;
        
    }
    
    void put(int key, int value) {
        if(mpp.find(key) != mpp.end()){
            Node* node = mpp[key];
            node->val=value;
            delrear(node);
            insertfront(node);

        }
        else{
            if(mpp.size()==cap){
                Node* lru = tail->prev;
                delrear(lru);
                mpp.erase(lru->key);
                delete lru;
            }
            Node* node = new Node(key,value);
            insertfront(node);
            mpp[key] = node;
        }
        }
        
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */