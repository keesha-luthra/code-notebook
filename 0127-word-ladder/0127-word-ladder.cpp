class Solution {
public:
    int ladderLength(string beginWord,
                     string endWord,
                     vector<string>& wordList) {

        // Store words in a set for fast lookup
        // Only words in this set are still undiscovered
        unordered_set<string> remaining(
            wordList.begin(), wordList.end()
        );

        // If endWord is not in the dictionary,
        // transformation is impossible
        if (remaining.find(endWord) == remaining.end()) {
            return 0;
        }

        // Queue stores {current word, transformation count}
        queue<pair<string, int>> q;

        // Begin with the starting word
        // The starting word counts as one word in the sequence
        q.push({beginWord, 1});

        // Mark the starting word as visited
        remaining.erase(beginWord);

        // BFS explores transformations in increasing path length
        while (!q.empty()) {

            // Get the word at the front of the queue
            auto [word, steps] = q.front();
            q.pop();

            // If we reached the destination, return the sequence length
            if (word == endWord) {
                return steps;
            }

            // Try changing each character in the current word
            for (int i = 0; i < word.size(); i++) {

                // Save the original character so we can restore it
                char original = word[i];

                // Replace it with every lowercase English letter
                for (char ch = 'a'; ch <= 'z'; ch++) {

                    // Skip the original character
                    if (ch == original) {
                        continue;
                    }

                    // Generate a possible neighboring word
                    word[i] = ch;

                    // Check whether this word is undiscovered
                    if (remaining.count(word)) {

                        // Mark it visited immediately when enqueued
                        // This prevents duplicate queue entries
                        remaining.erase(word);

                        // Add the new word with one more transformation
                        q.push({word, steps + 1});
                    }
                }

                // Restore the original character before
                // trying to change the next position
                word[i] = original;
            }
        }

        // No valid transformation sequence exists
        return 0;
    }
};