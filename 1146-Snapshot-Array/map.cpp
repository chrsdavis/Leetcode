#include "util/common.h"

// Note: very similar to 981 -- Time Based K/V storage
// Note: b/c snapshot id is monotonically increasing, we can just use a vector<vector>>
// instead of vector<map> as we only insert to the back (push_back O(1)), but map[] is average
// O(log snapshot_id), or even O(snapshot_id). In this case, we just call:
// upper_bound(vec.begin(), vec.end(), target) and return the prev.

class SnapshotArray {
private:
    vector<map<int, int>> data;
    size_t current_snap = 0;
public:
    SnapshotArray(int length) { // O(length)
        data.resize(length, {{0,0}});
    }

    void set(int index, int val) { // O(log current_snap)
        data[index][current_snap] = val;
    }

    int snap() { // O(1)
        return current_snap++;
    }
    
    int get(int index, int snap_id) { // O(log current_snap)
        return prev(data[index].upper_bound(snap_id))->second;
    }
};