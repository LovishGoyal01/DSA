class Twitter {
    int timer;

    unordered_map<int, unordered_set<int>> followMap;
    unordered_map<int, vector<pair<int,int>>> tweets;

public:
    Twitter() {
        timer = 0;
    }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timer++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {

        priority_queue<vector<int>> pq;

        followMap[userId].insert(userId);

        for(auto user : followMap[userId]) {

            auto &userTweets = tweets[user];

            if(!userTweets.empty()) {

                int idx = userTweets.size() - 1;

                pq.push({
                    userTweets[idx].first,  // time
                    userTweets[idx].second, // tweetId
                    user,                   // userId
                    idx                     // index
                });
            }
        }

        vector<int> ans;

        while(!pq.empty() && ans.size() < 10) {

            auto cur = pq.top();
            pq.pop();

            int tweetId = cur[1];
            int user = cur[2];
            int idx = cur[3];

            ans.push_back(tweetId);

            idx--;

            if(idx >= 0) {
                pq.push({
                    tweets[user][idx].first,
                    tweets[user][idx].second,
                    user,
                    idx
                });
            }
        }

        return ans;
    }

    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {

        if(followerId == followeeId)
            return;

        followMap[followerId].erase(followeeId);
    }
};