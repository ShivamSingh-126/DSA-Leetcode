class Solution {
public:
    vector<int> constructRectangle(int area) {
        int wid = sqrt(area);
        while (area % wid != 0) {
            wid--;
        }
        int len = area / wid;
        return {len, wid};
    }
};