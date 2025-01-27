struct Node {
    int key;  // Key of the node
    int value;  // Value associated with the key
    Node *next;  // Pointer to the next node
    Node *prev;  // Pointer to the previous node

    // Constructor to initialize a node with given key and value
    Node(int k, int v) {
        key = k;
        value = v;
        next = nullptr;
        prev = nullptr;
    }
};

// LRU Cache class
class LRUCache {
public:
    int capacity;  // Maximum capacity of the cache
    unordered_map<int, Node *> cacheMap;  // Cache storage using hash map (key -> node)
    Node *head;  // Head node (dummy)
    Node *tail;  // Tail node (dummy)

    // Constructor to initialize the cache with a given capacity
    LRUCache(int capacity) {
        this->capacity = capacity;  // Set the cache capacity
        head = new Node(-1, -1);  // Create a dummy head node
        tail = new Node(-1, -1);  // Create a dummy tail node
        head->next = tail;  // Head's next is tail
        tail->prev = head;  // Tail's previous is head
    }

    // Function to get the value for a given key
    int get(int key) {
        // Check if the key exists in the cache
        if (cacheMap.find(key) == cacheMap.end())
            return -1;  // If key is not found, return -1

        // If key is found, get the corresponding node
        Node *node = cacheMap[key];

        // Remove the node from its current position
        remove(node);

        // Add the node to the most recent position (right after head)
        add(node);

        // Return the value of the node
        return node->value;
    }

    // Function to put a key-value pair into the cache
    void put(int key, int value) {
        // If the key already exists, remove it and delete the old node
        if (cacheMap.find(key) != cacheMap.end()) {
            Node *oldNode = cacheMap[key];
            remove(oldNode);  // Remove the old node from the list
            delete oldNode;  // Delete the old node
        }

        // Create a new node with the key and value
        Node *node = new Node(key, value);

        // Insert the node into the cache map
        cacheMap[key] = node;

        // Add the node to the most recent position (right after head)
        add(node);

        // If the cache size exceeds the capacity, remove the least recently used node
        if (cacheMap.size() > capacity) {
            // The node to be deleted is the one before the tail (least recently used)
            Node *nodeToDelete = tail->prev;

            // Remove the least recently used node from the list
            remove(nodeToDelete);

            // Remove the node from the cache map and delete it
            cacheMap.erase(nodeToDelete->key);
            delete nodeToDelete;
        }
    }

    // Add a node right after the head (most recently used position)
    void add(Node *node) {
        // Get the node that comes after the head (currently the most recent)
        Node *nextNode = head->next;

        // Insert the node right after the head
        head->next = node;
        node->prev = head;
        node->next = nextNode;
        nextNode->prev = node;
    }

    // Remove a node from the list (can be the least recently used node)
    void remove(Node *node) {
        // Get the previous and next nodes
        Node *prevNode = node->prev;
        Node *nextNode = node->next;

        // Update the pointers to remove the node from the list
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }
};
