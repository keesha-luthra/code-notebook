
class LRUCache {
private:
    int capacity;

    // Most recently used key is at the front.
    // Least recently used key is at the back.
    list<pair<int, int>> dll;

    // Key -> iterator pointing to its node in the list.
    unordered_map<int, list<pair<int, int>>::iterator> mp;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }

        // Get the node's iterator.
        auto it = mp[key];

        // Move the accessed node to the front.
        dll.splice(dll.begin(), dll, it);

        return it->second;
    }

    void put(int key, int value) {
        // If key already exists, update and mark recent.
        if (mp.find(key) != mp.end()) {
            auto it = mp[key];
            it->second = value;
            dll.splice(dll.begin(), dll, it);
            return;
        }

        // Insert new key at the front.
        dll.push_front({key, value});
        mp[key] = dll.begin();

        // Evict least recently used if over capacity.
        if (mp.size() > capacity) {
            auto lru = dll.back();
            mp.erase(lru.first);
            dll.pop_back();
        }
    }
};