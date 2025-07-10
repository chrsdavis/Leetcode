// See if you can divide the hand into straights of groupSize size.
// Straight means they are consecutive, e.g. [1, 2, 3, 4, 5, ...]
// can make better with just a boolean array to mark used cards, then iterate over sorted hand
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;
        sort(hand.begin(), hand.end());
        unordered_map<int, int> freq;
        for (int card: hand) freq[card]++;

        const int num_groups = hand.size() / groupSize;
        int k = 0;
        for (int i = 0; i < num_groups; i++) {
            while (k < hand.size() && freq[hand[k]] == 0)
                k++;
            if (k == hand.size()) return false;
            freq[hand[k]]--;

            int prev = k;
            for (int j = 0; j < groupSize - 1; j++) {
                int l = prev + 1;
                while (l < hand.size() &&
                       (freq[hand[l]] == 0 || hand[l] == hand[prev]))
                    l++;
                if (l == hand.size() || hand[l] != hand[prev]+1)
                    return false;
                freq[hand[l]]--;
                prev = l;
            }
        }
        return true;
    }
};