/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        res.clear();
        if(intervals.empty()) {
            res.push_back(newInterval);
            return res;
        }
        int len = intervals.size();
        int s = 0, e = 0;
        while(s < len && intervals[s].end < newInterval.start) {
            res.push_back(intervals[s]);
            ++s;
        }
        if(s == len) {
            res.push_back(newInterval);
            return res;
        }
        if(newInterval.end < intervals[s].start) {
            res.push_back(newInterval);
        } else {
            newInterval.start = min(intervals[s].start, newInterval.start);
            newInterval.end = max(intervals[s].end, newInterval.end);
            cout << newInterval.start << " " << newInterval.end << endl;
            while(s < len && intervals[s].start < newInterval.end) {
                newInterval.end = max(intervals[s].end, newInterval.end);
                ++s;
            }

            res.push_back(newInterval);
        }
        while(s < len) {
            res.push_back(intervals[s]);
            ++s;
        }
        return res;
    }
    
private:
    vector<Interval> res;
};


