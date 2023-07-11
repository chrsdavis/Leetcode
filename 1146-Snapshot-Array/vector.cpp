#include "util/common.h"

// slight improvement over map solution (set is constant, not logarithmic now)

class SnapshotArray {
private:
    vector<vector<pair<int, int>>> data;
    size_t current_snap = 0;
public:
    SnapshotArray(int length) { // O(length)
        data.resize(length, {{0,0}});
    }

    void set(int index, int val) { // O(1)
        if(data[index].back().first != current_snap)
            data[index].push_back({current_snap, val});
        else 
            data[index].back().second = val;
    }

    int snap() { // O(1)
        return current_snap++;
    }
    
    int get(int index, int snap_id) { // O(log current_snap)
        return prev(upper_bound(data[index].begin(), data[index].end(), 
            pair<int,int>{snap_id, INT_MAX}))->second;
    }
};