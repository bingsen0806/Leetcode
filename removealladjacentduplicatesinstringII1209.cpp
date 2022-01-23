#include <vector>
#include <string>
using namespace std;

//Stack solution
//Can also use two pointers i, j, both starting at 0
//Then i is the position of the output and j keeps increasing
//Copies the solution in place

//Alternative: Two Pointers, or Stack using Java StringBuffer
class Solution {
public:
string removeDuplicates(string s, int k) {
        vector<pair<int,int>> stack = {{0, '#'}};
     for (char c: s) {
         if (c == stack.back().second) {
             if (++stack.back().first == k) {
                 stack.pop_back();
             }
         } else {
             stack.push_back({1, c});
         }
     }
     string ans;
     for(const auto& p: stack) {
         ans.append(p.first, p.second);
     }
     return ans;
    }
};