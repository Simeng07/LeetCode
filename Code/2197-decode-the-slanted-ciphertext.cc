class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        if (encodedText.size() == 0) {
            return "";
        }
        string result = "";
        int columns = encodedText.size() / rows;
        int charCount = columns - (rows - 1);
        for (int i = 0; i < charCount; i++) {
            for (int j = 0; j < rows; j++) {
                result += encodedText[columns * j + j + i];
            }
        }
        for (int j = 0; j < rows - 1; j++) {
            result += encodedText[columns * j + j + charCount];
        }
        result = removeSpaces(result);
        return result;
    }
    
    string removeSpaces(string s) {
        const auto strEnd = s.find_last_not_of(' ');
        const auto strRange = strEnd + 1;
        return s.substr(0, strRange);
    }
};