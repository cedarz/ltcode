/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool cmp(Interval a, Interval b) {
    if(a.start < b.start) {
        return true;
    } else if(a.start == b.start) {
        return a.end < b.end;
    } else {
        return false;
    }
}

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        res.clear();
        if(intervals.empty()) return res;
        sort(intervals.begin(), intervals.end(), cmp);
        int len = intervals.size();
        Interval itv = intervals[0];
        for(int i = 0; i < len; ++i) {
            if(itv.end < intervals[i].start) {
                res.push_back(itv);
                itv = intervals[i];
            } else {
                itv.end = max(itv.end, intervals[i].end);
            }
            if(i == len - 1) {
                res.push_back(itv);
            }
        }
        
        return res;
    }
    
            
private:
    vector<Interval> res;
};


