class Solution {
public:
    class comparator{
    public:
        // 这里函数名必须是operator()
        bool operator()(pair<int, int>& left, pair<int, int>& right){
            return left.second > right.second;
        } 
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        priority_queue<pair<int, int>, vector<pair<int, int>>, comparator> my_queue;
        unordered_map<int, int> my_map;
        for (int i = 0; i < nums.size(); i++){
            my_map[nums[i]]++;
        }

        for (unordered_map<int, int>::iterator itr = my_map.begin(); itr != my_map.end(); itr++){
            my_queue.push(*itr);
            if (my_queue.size() > k){
                // priority queue只有pop和push 无法指定是back还是front
                my_queue.pop();
            }
        }

        for (int i = 0; i < k; i++){
            // priority queue没有front函数 只有top(毕竟是堆,考虑堆顶)
            res.push_back(my_queue.top().first);
            my_queue.pop();
        }
        return res;
    }

};