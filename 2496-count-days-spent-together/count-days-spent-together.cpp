class Solution {
public:
    int day_year(string s)
    {
        vector<int>days = {31,28,31,30,31,30,31,31,30,31,30,31};

        int month=stoi(s.substr(0,2));
        int day=stoi(s.substr(3,2));

        int total=day;
        for(int i=0;i<month-1;i++)
        {
            total +=days[i];
        }
        return total;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) 
    {
        int a = day_year(arriveAlice);
        int b = day_year(leaveAlice);

        int c = day_year(arriveBob);
        int d = day_year(leaveBob);

        int start = max(a,c);
        int end = min(b,d);

        if(start > end)  return 0;

        return end - start +1;
    }
};