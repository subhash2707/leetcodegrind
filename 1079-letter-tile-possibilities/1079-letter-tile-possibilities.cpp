//sol
class Solution {
public:
    void backtrack(unordered_map<char, int>& freq, int& count, int length, int n) {
        if (length > 0) count++;  // Count the current sequence

        for (auto& [ch, f] : freq) {
            if (f > 0) {
                freq[ch]--;  // Use this character
                backtrack(freq, count, length + 1, n);
                freq[ch]++;  // Restore for next sequences
            }
        }
    }

    int numTilePossibilities(string tiles) {
        unordered_map<char, int> freq;
        for (char ch : tiles) freq[ch]++;

        int count = 0;
        backtrack(freq, count, 0, tiles.size());
        return count;
    }
};
