class CombinationIterator {
    string last = "";
    string current = "";
    int combl = 0;
    string cs;
    int size = 0;
    int index[16] = {0};
public:
    CombinationIterator(string characters, int combinationLength) {
        combl = combinationLength;
        cs = characters;
        size = characters.size();
        last = characters.substr(size - combinationLength, combinationLength);
        current = characters.substr(0, combinationLength);
        for (int i = 0; i < combinationLength; i++) {
            index[i] = i;
        }
    }
    
    string next() {
        string result = current;
        if (current == last) {
            current = "";
        } else {
            for (int i = combl - 1; i >= 0; i--) {
                if (index[i] != size - 1 - (combl - 1 - i)) {
                    index[i]++;
                    current[i] = cs[index[i]];
                    if (i != combl - 1) {
                        for (int j = i + 1; j < combl; j++) {
                            index[j] = index[i] + (j - i);
                            current[j] = cs[index[j]];
                        }
                    }
                    break;
                }
            }
        }
        return result;
    }
    
    bool hasNext() {
        return (current.size() != 0);
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */