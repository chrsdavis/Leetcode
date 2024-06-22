// We know that the new timestamps from set are stricly increasing,
// so we can just push_back the new values into a plain vector
// without worrying about insertion logic or using an std::map


class TimeMap {
public:
    TimeMap() { }
    
    void set(string key, string value, int timestamp) {
        hm[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto& vals = hm[key];
        auto it = std::upper_bound(
            vals.begin(), vals.end(), timestamp, [](int a, const auto& b) {
                return a < b.first;
            }
        );
        if(it == vals.begin()) return "";
        return prev(it)->second;
    }

private:
    unordered_map<string, vector<pair<int,string>>> hm;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */