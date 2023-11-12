class Solution {
private:
    bool check_time(string &a, string &b) {
        int minutes = 60 * (stoi(b.substr(0, 2)) - stoi(a.substr(0, 2))) + (stoi(b.substr(2, 2)) - stoi(a.substr(2, 2)));
        
        return minutes < 60;
    }
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        vector<string> ans;
        
        sort(access_times.begin(), access_times.end(), [](const vector<string>&a, const vector<string>&b) {
            return (a[0] != b[0]) ? a[0] < b[0] : a[1] < b[1];
        });
        
        string name = access_times[0][0];
        int stamp = 0, time = 0;
        for (int i = 0; i < access_times.size();) {
            if (access_times[i][0] == name) {
                if (check_time(access_times[stamp][1], access_times[i][1])) {
                    time += 1;
                    i++;
                    if (time >= 3) {
                        ans.emplace_back(name);
                        time = 0;
                        while (i < access_times.size() and access_times[i][0] == name) i++;
                        if (i < access_times.size()) name = access_times[i][0], stamp = i;
                    }
                } else {
                    time -= 1;
                    stamp += 1;
                }
            } else {
                time = 0;
                stamp = i;
                name = access_times[i][0];
            }
        }
        
        return ans;
    }
};
