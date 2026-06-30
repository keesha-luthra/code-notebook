class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return 0;
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        while(!q.empty()){
            string word = q.front().first;
            int level = q.front().second;
            if(word == endWord) return level;
            q.pop();
            for(int i = 0; i < word.size(); i++){
                char original = word[i];
                for(char c = 'a'; c <= 'z'; c++){
                    word[i] = c;
                    if(dict.count(word)){
                        q.push({word, level + 1});
                        dict.erase(word);
                    }
                    word[i] = original;
                }
            }
        }
        return 0;
    }
};