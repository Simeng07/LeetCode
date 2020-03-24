class Solution {
public:
    int daysBetweenDates(string date1, string date2) {
        int day1 = daysTo1970(date1);
        int day2 = daysTo1970(date2);
        return abs(day1 - day2);
    }
    
    int daysTo1970(string date) {
        vector<int> d;
        stringstream ss(date);
        string tmp;
        while (getline(ss, tmp, '-')) {
            d.push_back(stoi(tmp));
        }
        // year
        int days = 365 * (d[0] - 1970);
        days += (d[0] - 1970) / 4;
        days += (d[0] - 1970) % 4 >= 3 ? 1 : 0;
        // month
        int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (d[0] % 4 == 0 && d[0] != 2100) {
            month[1] = 29;
        }
        for (int i = 0; i < d[1] - 1; i++) {
            days += month[i];
        }
        // day
        days += d[2] - 1;
        
        return days;
    }
};