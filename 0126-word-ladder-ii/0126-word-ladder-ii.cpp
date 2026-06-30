class Solution {
public:
    vector<vector<string>> ans;
    
    void dfs(string word, string beginWord, vector<string>& path, unordered_map<string, vector<string>>& parent){
        if(word == beginWord){
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
        }
        else{
            for(const string& p : parent[word]){
                path.push_back(p);
                dfs(p, beginWord, path, parent);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        unordered_map<string, int> dist;
        unordered_map<string, vector<string>> parent;
        queue<string> q;
        
        q.push(beginWord);
        dist[beginWord] = 0;
        
        while(!q.empty()){
            string current = q.front();
            q.pop();
            
            // Optimization: stop if we already found the shortest distance to endWord
            if (dist.count(endWord) && dist[current] >= dist[endWord]) continue;

            string parentWord = current; 
            for(int i = 0; i < current.size(); i++){
                char originalChar = current[i];
                for(char c = 'a'; c <= 'z'; c++){
                    if (c == originalChar) continue;
                    
                    current[i] = c;
                    if(dict.count(current)){
                        if(!dist.count(current)){
                            dist[current] = dist[parentWord] + 1;
                            parent[current].push_back(parentWord);
                            q.push(current);
                        }
                        else if(dist[current] == dist[parentWord] + 1){
                            parent[current].push_back(parentWord);
                        }
                    }
                }
                current[i] = originalChar; // Restore character
            }
        }
        
        vector<string> path;
        path.push_back(endWord);
        if (dist.count(endWord)) {
            dfs(endWord, beginWord, path, parent);
        }

        return ans;
    }
};