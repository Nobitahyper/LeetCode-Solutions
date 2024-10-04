class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        int n = operations.size();
        vector<long long> lengths(n + 1);
        lengths[0] = 1; // Initial length of word "a"

        // Precompute lengths after each operation
        for (int i = 1; i <= n; ++i) {
            lengths[i] = lengths[i - 1] * 2;
            if (lengths[i] > k) {
                lengths[i] = k; // No need to store lengths beyond k
            }
        }

        return findChar(k, n, operations, lengths);
    }

private:
    char findChar(long long k, int step, vector<int>& operations, vector<long long>& lengths) {
        if (step == 0) {
            return 'a'; // Base case: initial character
        }

        long long halfLength = lengths[step - 1];
        if (k <= halfLength) {
            // The k-th character is in the first half
            return findChar(k, step - 1, operations, lengths);
        } else {
            // The k-th character is in the second half
            if (operations[step - 1] == 0) {
                // Operation 0: second half is identical to the first half
                return findChar(k - halfLength, step - 1, operations, lengths);
            } else {
                // Operation 1: second half is the transformed version of the first half
                char c = findChar(k - halfLength, step - 1, operations, lengths);
                return nextChar(c);
            }
        }
    }

    char nextChar(char c) {
        return c == 'z' ? 'a' : c + 1; // Wrap around from 'z' to 'a'
    }
};
