#include <unordered_map>
#include <list>

class LRUCache
{

public:

    LRUCache(int capacity)
    {
        _capacity = capacity;
    }
    int get(int key);
    void set(int key, int value);
    void use(std::unordered_map<int, std::pair<int, std::list<int>::iterator>>::iterator& it);

private:
    int _capacity;
    std::unordered_map<int, std::pair<int, std::list<int>::iterator>> _cache;
    std::list<int> _lru;
};
