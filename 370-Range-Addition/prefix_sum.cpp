#include "util/common.h"

// basically, we put the +change at the start index, and then
// put -change at (end idx + 1)
// we basically then just do a cumulative sum of the array
// e.g. say we have only 1 update, and it's to increment [1,3] to +2
// so, we do:
// [0, 0, 0, 0, 0, 0] --> [0, 2, 0, 0, -2, 0]
// then the cumulative sum (left to right) is:
// [0, 2 + 0, 0 + 2, 0 + 2, 2 - 2, 0 + 0] --> [0, 2, 2, 2, 0, 0]
// we store length + 1 to avoid idx out of bounds, but last entry is useless
// this way it's branchless


class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        // length + 1 to avoid checking for index bounds
        vector<int> answer(length + 1, 0);

        for(const vector<int>& update: updates) {
            answer[update[0]] += update[2];
            answer[update[1] + 1] -= update[2];
        }

        partial_sum(answer.begin(), answer.end(), answer.begin());

        answer.pop_back(); // remove useless answer[N]
        return answer;
    }
};
