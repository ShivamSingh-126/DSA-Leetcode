class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) 
    {
        
       double a = sides[0], b = sides[1], c = sides[2];

        // Step 1: Triangle validity
        if (a + b <= c || b + c <= a || a + c <= b) {
            return {};
        }

        // Step 2: Use cosine rule
        double A = acos((b*b + c*c - a*a) / (2*b*c));
        double B = acos((a*a + c*c - b*b) / (2*a*c));
        double C = acos((a*a + b*b - c*c) / (2*a*b));

        // Convert to degrees
        double factor = 180.0 / M_PI;
        A *= factor;
        B *= factor;
        C *= factor;

        vector<double> ans = {A, B, C};
        sort(ans.begin(), ans.end());

        return ans;
    }
};