class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<pair<string, string>> v;

        for(auto str: strs) {
            string key = str;
            sort(key.begin(), key.end());
            v.push_back({key, str});
        }

        // sort by key
        sort(v.begin(), v.end());

        vector<vector<string>> ans;

        for(int i = 0; i < v.size(); i++) 
        {
            vector<string> group;
            string currKey = v[i].first;

            while(i < v.size() && v[i].first == currKey) {
                group.push_back(v[i].second);
                i++;
            }
            i--;
            ans.push_back(group);
        }
        return ans;
    }
};