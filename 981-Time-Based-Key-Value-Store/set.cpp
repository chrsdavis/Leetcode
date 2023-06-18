#include "util/common.h"

// using unordered_map< string, map<int, string> > is much easier
// also, the timestamps are strictly increasing, so you can simply do a binary search on
// a vector, i.e. unordered_map<string, vector<pair<int, string>>>

class TimeMap {
private:
    unordered_map<string, unordered_map<int,string>> kv;
    unordered_map<string, set<int>> times;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) { // O(1)
        kv[key][timestamp] = value;
        times[key].insert(timestamp);
    } 
    
    string get(string key, int timestamp) { // O(log n)
        if(times[key].size() == 0)
            return "";

        auto it = times[key].lower_bound(timestamp);

        if(it == times[key].end() || (*it != timestamp && it != times[key].begin()) )
            return kv[key][*prev(it)];
       
        if(*it == timestamp)
            return kv[key][*it];
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */