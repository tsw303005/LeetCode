#include <iostream>
#include <unordered_map>

using namespace std;

class UndergroundSystem {
private:
    unordered_map<int, pair<string, int>> checkInWithId;
    unordered_map<string, pair<int, int>> totalTimeCount;
public:
    UndergroundSystem() {
        checkInWithId.clear();
        totalTimeCount.clear();
    }
    
    void checkIn(int id, string stationName, int t) {
        checkInWithId[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string twoStation = concatenate(checkInWithId[id].first, stationName);
        updateTime(twoStation, checkInWithId[id].second, t);
        checkInWithId.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        string twoStation = concatenate(startStation, endStation);
        if (totalTimeCount.find(twoStation) == totalTimeCount.end()) {
            return 0.0;
        } else {
            return (double)totalTimeCount[twoStation].first / (double)totalTimeCount[twoStation].second;
        }
    }
    
    string concatenate(string a, string b) {
        return a + '>' + b;
    }
    
    void updateTime(string twoStation, int startTime, int endTime) {
        int totalTime = endTime - startTime;
        
        if (totalTimeCount.find(twoStation) == totalTimeCount.end()) {
            totalTimeCount[twoStation] = {totalTime, 1};
        } else {
            auto storeValue = totalTimeCount[twoStation];
            totalTimeCount[twoStation] = {storeValue.first + totalTime, storeValue.second + 1};
        }
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
