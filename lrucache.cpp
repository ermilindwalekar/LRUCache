#include "lrucache.h"

int LRUCache::get(int key)
{
    // If key found return value
    //if not found return -1
    auto item = _cache.find(key);
    if(item == _cache.end())
    {
        return -1;
    }
    else
    {
        use(item);
        return item->second.first;
    }
}
void LRUCache::set(int key, int value)
{
    //Check if it is present
    auto item = _cache.find(key);
    if(item != _cache.end())
    {
        use(item);
        _cache[key] = {value, _lru.begin()};
    }
    //insert the key value at the end if key is not present
    if(_lru.size() == _capacity)
    {
        //Kick out the LRU item
        _cache.erase(_lru.back());
        _lru.pop_back();
    }
    _lru.push_front(key);
    _cache.insert({key,{value,_lru.begin()}});
}
void LRUCache::use(std::unordered_map<int, std::pair<int, std::list<int>::iterator>>::iterator& it)
{
    _lru.erase(it->second.second);
    _lru.push_front(it->second.first);
    it->second.second = _lru.begin();
}
