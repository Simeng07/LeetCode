class Solution {
public:
    string validIPAddress(string IP) {
        bool is4 = (IP.find('.') != string::npos);
        bool is6 = (IP.find(':') != string::npos);
        if ((is4 && is6) || (!is4 && !is6) || IP[0] == '.' || IP[0] == ':' || IP[IP.size() - 1] == '.' || IP[IP.size() - 1] == ':') {
            return "Neither";
        }
        stringstream ss(IP);
        string num;
        int count = 0;
        if (is4) {
            while (getline(ss, num, '.')) {
                count++;
                for (auto n : num) {
                    if (!(isdigit(n))) {
                        return "Neither";
                    }
                }
                if (count > 4 || num.length() == 0 || num.length() > 3 || stoi(num) > 255 || (num.length() > 1 && num[0] == '0')) {
                    return "Neither";
                }
            }
            if (count == 4) {
                return "IPv4";
            }
        }
        if (is6) {
            while (getline(ss, num, ':')) {
                count++;
                if (count > 8 || num.length() == 0 || num.length() > 4) {
                    return "Neither";
                }
                for (auto n : num) {
                    if (!(isdigit(n) || (n >= 'a' && n <= 'f') || (n >= 'A' && n <= 'F'))) {
                        return "Neither";
                    }
                }
            }
            if (count == 8) {
                return "IPv6";
            }
        }
        return "Neither";
    }
};