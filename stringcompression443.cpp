#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0;
        for (int j = 1, count = 1; j <= chars.size(); j++, count++) {
            if (j == chars.size() || chars[j] != chars[j-1]) {
                chars[i++] = chars[j-1];
                if (count > 1){
                    string num = to_string(count);
                    for(char c: num) {
                        chars[i++] = c;
                    }
                }
                count = 0;
            }
        }
        return i;
    }
};