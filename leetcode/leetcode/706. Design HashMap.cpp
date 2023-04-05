class MyHashMap {
public:
    vector<int> hashmap;
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        int size = hashmap.size();
        if(key >= size) {
            for(int i = size; i <= key; i++) {
                hashmap.push_back(-1);
            }
        }
        hashmap[key] = value;
    }
    
    int get(int key) {
        if(key >= hashmap.size()) return -1;
        return hashmap[key]; 
    }
    
    void remove(int key) {
        if(key >= hashmap.size()) return;
        hashmap[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */