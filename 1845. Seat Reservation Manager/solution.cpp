class SeatManager {
public:
    SeatManager(int n) {
        for (int i = 1; i <= n; i++) PQ.push(i);
    }
    
    int reserve() {
        auto cur = PQ.top();
        PQ.pop();
        
        return cur;
    }
    
    void unreserve(int seatNumber) {
        PQ.push(seatNumber);
    }
private:
    priority_queue<int, vector<int>, greater<int>> PQ;
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
