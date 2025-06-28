struct Node{
    int key,value,cnt;
    Node* prev;
    Node* next;
    Node(int _key,int _value){
        key=_key;
        value=_value;
        cnt=1;
    }
};
struct List{
    int size;Node* tail;Node* head;
    List(){
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->prev = head;
        size=0;
    }
    void insert(Node* node){
        Node* temp = head->next;
        node->prev =head;
        node->next = temp;
        temp->prev = node;
        head->next = node;
        size++;
    }
    void del(Node* node){
        Node* front = node->next;
        Node* previous = node->prev;
        front->prev = previous;
        previous->next = front;
        size--;
    }
};
class LFUCache {
public:
map<int,List*>freqlist;
map<int,Node*> keynode;
int maxsize;
int cursize;
int minfreq;
    LFUCache(int capacity) {
        maxsize = capacity;
        cursize=0;
        minfreq=0;
    }
    void update(Node* node){
        keynode.erase(node->key);
        freqlist[node->cnt]->del(node);
        if(node->cnt == minfreq && freqlist[node->cnt]->size==0) minfreq++;
        List* nexthigh = new List();
        if(freqlist.find(node->cnt+1) != freqlist.end()){
            nexthigh = freqlist[node->cnt+1];
        }
        node->cnt++;
        nexthigh->insert(node);
        freqlist[node->cnt] = nexthigh;
        keynode[node->key]=node;
    }
    int get(int key) {
        if(keynode.find(key) != keynode.end()){
            Node* node = keynode[key];
            int val = node->value;
            update(node);
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(maxsize==0) return;
        if(keynode.find(key) != keynode.end()){
            Node* node = keynode[key];
            node->value  = value;
            update(node);
        }
        else{
            if(maxsize==cursize){
                List* list = freqlist[minfreq];
                keynode.erase(list->tail->prev->key);
                freqlist[minfreq]->del(list->tail->prev);
                cursize--;

            }
            cursize++;
            minfreq=1;
            List* list = new List();
            if(freqlist.find(minfreq)!=freqlist.end())
            list = freqlist[minfreq];
            Node* node = new Node(key,value);
            list->insert(node);
            keynode[key] = node;
            freqlist[minfreq]=list;

            
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */