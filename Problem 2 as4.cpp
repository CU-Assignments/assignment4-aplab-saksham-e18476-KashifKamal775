#include <bits/stdc++.h>
using namespace std;

class SkylineProblem {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> events;
        for (auto& b : buildings) {
            events.emplace_back(b[0], -b[2]); // Start of a building (negative height)
            events.emplace_back(b[1], b[2]);  // End of a building (positive height)
        }

        sort(events.begin(), events.end(), [](pair<int, int>& a, pair<int, int>& b) {
            return a.first == b.first ? a.second < b.second : a.first < b.first;
        });

        multiset<int> heights = {0};
        vector<vector<int>> res;
        int prevHeight = 0;

        for (auto& e : events) {
            if (e.second < 0) {
                heights.insert(-e.second); // Add building height
            } else {
                heights.erase(heights.find(e.second)); // Remove building height
            }

            int currHeight = *heights.rbegin();
            if (currHeight != prevHeight) {
                res.push_back({e.first, currHeight});
                prevHeight = currHeight;
            }
        }
        return res;
    }
};

int main() {
    SkylineProblem obj;
    vector<vector<int>> buildings = {{2,9,10}, {3,7,15}, {5,12,12}, {15,20,10}, {19,24,8}};
    vector<vector<int>> result = obj.getSkyline(buildings);

    cout << "Skyline Output: ";
    for (auto& point : result) {
        cout << "[" << point[0] << ", " << point[1] << "] ";
    }
    cout << endl;
    return 0;
}
