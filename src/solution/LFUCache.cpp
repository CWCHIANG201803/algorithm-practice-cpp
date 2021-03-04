#include "LFUCache.hpp"


int LFUCache::get(int key){
    auto it = n_.find(key);
    if(it == n_.cend())
        return -1;

    touch(it->second);

    return it->second.value;
}

void LFUCache::put(int key, int value){
    if(capacity_==0)
        return;

    auto it = n_.find(key);
    if( it != n_.cend()){

        it->second.value = value;
        touch(it->second);
        return;
    }

    if(n_.size() == capacity_){

        const int key_to_evict = l_[min_freq_].back();
        l_[min_freq_].pop_back();

        n_.erase(key_to_evict);
    }

    const int freq = 1;
    min_freq_= freq;

    l_[freq].push_front(key);

    n_[key] = { key, value, freq, l_[freq].cbegin()};
}


void LFUCache::touch(CacheNode& node){
    const int prev_freq = node.freq;
    const int freq = ++(node.freq);

    l_[prev_freq].erase(node.it);

    if(l_[prev_freq].empty() && prev_freq == min_freq_){

        l_.erase(prev_freq);
        ++min_freq_;
    }



    l_[freq].push_front(node.key);
    node.it = l_[freq].cbegin();
}
