#include <unordered_map>
#include<vector>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (mp.find(nums[i]) == mp.end()) mp[nums[i]] = 0;
            mp[nums[i]] += 1;
        }
        
        for(auto const& [key, value] : mp) {
            if (value > 1) return true;
        }
        return false;
    }
};

//other ways to loop thru unordered_map:

//for (auto const& x : symbolTable)
// {
//     std::cout << x.first  // string (key)
//               << ':' 
//               << x.second // string's value 
//               << std::endl;
// }


// map<string, int>::iterator it;

// for (it = symbolTable.begin(); it != symbolTable.end(); it++)
// {
//     std::cout << it->first    // string (key)
//               << ':'
//               << it->second   // string's value 
//               << std::endl;
// }