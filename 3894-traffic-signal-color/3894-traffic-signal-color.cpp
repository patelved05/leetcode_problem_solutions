class Solution {
public:
    string trafficSignal(int timmer) {
        if (timmer == 0)
            return "Green";
        else if (timmer == 30)
            return "Orange";
        else if (30 < timmer && timmer <= 90)
            return "Red";
        return "Invalid";
    }
};