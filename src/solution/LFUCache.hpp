#include <vector>
#include <unordered_map>
#include <list>
using namespace std;

class LFUCache {
struct CacheNode{
    int key;
    int value;
    int freq;
    list<int>::const_iterator it;
};
private:
    int capacity_;
    int min_freq_;
    unordered_map<int, CacheNode> n_;
    unordered_map<int, list<int>> l_;
    void touch(CacheNode& node);
public:
    LFUCache(int capacity) :capacity_(capacity), min_freq_(0){}
    int get(int key);
    void put(int key, int value);
};