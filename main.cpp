#include "lrucache.h"
#include <iostream>

using namespace std;

int main()
{
    LRUCache *cache = new LRUCache(2);
    cache->set(1,1);
    // 1,1
    cache->set(2,2);
    // 2,2
    cout<<cache->get(1)<<endl;
    cache->set(3,3);
    //3,1
    cout<<cache->get(2)<<endl;

}
