class Solution {
    int sumofdigits(int n) {
        int sum = 0;
        while (n) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, vector<int>> mpp; // Store sum of digits and corresponding numbers
        int maxsum = -1; // Initialize maxsum to a valid low value

        for (auto it : nums) {
            mpp[sumofdigits(it)].push_back(it);
        }

        for (auto& it : mpp) {
            auto& vec = it.second;
            int vecsize = vec.size();
            if (vecsize > 1) {
                sort(vec.begin(), vec.end(), greater<int>()); // Sort in descending order
                maxsum = max(maxsum, vec[0] + vec[1]); // Pick the top two values
            }
        }
        return maxsum;
    }
};
