class Twitter {
public:
    int timer;


    unordered_map<int, unordered_set<int>> follows;


    unordered_map<int, vector<pair<int,int>>> tweets;

    Twitter() {
        timer = 0;
    }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timer++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {

        priority_queue<pair<int,int>> pq;


        if(tweets.count(userId)){
            for(auto &tweet : tweets[userId]){
                pq.push(tweet);
            }
        }


        for(auto followee : follows[userId]){
            if(tweets.count(followee)){
                for(auto &tweet : tweets[followee]){
                    pq.push(tweet);
                }
            }
        }

        vector<int> ans;

        while(!pq.empty() && ans.size() < 10){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }

    void follow(int followerId, int followeeId) {
        if(followerId == followeeId) return;
        follows[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
    }
};