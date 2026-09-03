class Twitter {
public:

    // follower -> set of users they follow
    unordered_map<int, unordered_set<int>> following;

    // user -> {time, tweetId}
    unordered_map<int, vector<pair<int, int>>> tweets;

    int timestamp = 0;

    Twitter() {
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timestamp++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {

        // Max heap:
        // {timestamp, tweetId, userId, index}
        priority_queue<
            tuple<int, int, int, int>
        > pq;

        // Users whose tweets we need to consider
        unordered_set<int> users = following[userId];

        // User also sees their own tweets
        users.insert(userId);

        // Add the newest tweet of every relevant user
        for (int user : users) {

            if (!tweets[user].empty()) {

                int index = tweets[user].size() - 1;

                auto [time, tweetId] = tweets[user][index];

                pq.push({time, tweetId, user, index});
            }
        }

        vector<int> feed;

        // We only need 10 tweets
        while (!pq.empty() && feed.size() < 10) {

            auto [time, tweetId, user, index] = pq.top();
            pq.pop();

            feed.push_back(tweetId);

            // Add the next older tweet from the same user
            if (index > 0) {

                int nextIndex = index - 1;

                auto [nextTime, nextTweetId] =
                    tweets[user][nextIndex];

                pq.push({
                    nextTime,
                    nextTweetId,
                    user,
                    nextIndex
                });
            }
        }

        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};