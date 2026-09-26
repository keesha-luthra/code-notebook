class LRUCache {
private:
    int capacity;

    // Doubly linked list:
    // Front = most recently used
    // Back = least recently used
    list<pair<int, int>> cache;

    // Map each key to its position in the linked list
    unordered_map<int, list<pair<int, int>>::iterator> mp;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {

        // Return -1 if the key does not exist
        if (mp.find(key) == mp.end()) {
            return -1;
        }

        // Find the node using its stored iterator
        auto it = mp[key];

        // Save its value before moving the node
        int value = it->second;

        // Remove it from its current position
        cache.erase(it);

        // Move the accessed item to the front
        cache.push_front({key, value});

        // Update the map to point to the new list position
        mp[key] = cache.begin();

        return value;
    }

    void put(int key, int value) {

        // If key already exists, remove its old list node
        if (mp.find(key) != mp.end()) {
            cache.erase(mp[key]);
        }

        // If key is new and the cache is full,
        // remove the least recently used item from the back
        else if (cache.size() == capacity) {

            // Get the key of the least recently used item
            int lruKey = cache.back().first;

            // Remove that item from the list
            cache.pop_back();

            // Remove its entry from the map
            mp.erase(lruKey);
        }

        // Insert the new or updated item at the front
        // It is now the most recently used item
        cache.push_front({key, value});

        // Store the iterator of the newly inserted node
        mp[key] = cache.begin();
    }
};