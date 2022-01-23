#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

//Sliding Window, hard
class Solution {
public:
    string minWindow(string s, string t) {
        if(t.length() > s.length()) return "";
        unordered_set<char> tContains;
        unordered_set<char> toFulfill;
        unordered_map<char, int> charCountToFill;
        
        for (int i = 0; i < t.length(); i++) {
            auto it = charCountToFill.find(t.at(i));
            if(it != charCountToFill.end())  {
                it->second += 1;
            } else {
                charCountToFill.insert({t.at(i), 1});
                tContains.insert(t.at(i));
                toFulfill.insert(t.at(i));
            }
        }
        
        int start = 0, end = 0, minWindow = s.length();
        int left = 0, right = 0;
        bool found = false;
        while (end < s.length()) {
            bool dontTake = false;
            //Stretch end as far as possible until fulfill condition
            while(!toFulfill.empty()) {
                if (end >= s.length()) {
                    dontTake = true;
                    break;
                }
                char c = s.at(end);
                if (tContains.find(c) != tContains.end()) {
                       charCountToFill.at(c)--;
                        if (charCountToFill.at(c) == 0) {
                            toFulfill.erase(c);
                        }
                }                
                end++;
            }
            
            if (dontTake) break;
            
            //Increase start to shrink window as far as possible
            while (true) {
                if (start >= s.length()) {
                    break;
                }
                char c = s.at(start);
                if (tContains.find(c) != tContains.end()) {
                    charCountToFill.at(c)++;
                    if (charCountToFill.at(c) > 0) {
                        toFulfill.insert(c);
                        start++;
                        break;
                    }          
                }  
                
                start++;
            }
            
            //Found new window that contains t, update new window
            if (!dontTake && minWindow >= end - start + 1) {
                found = true;
                minWindow = end - start + 1;
                left = start - 1, right = end-1;
            }
        }
        return found ? s.substr(left, right - left + 1) : "";
    }
};

//Alternative, just a shorter version
// string minWindow(string s, string t) {
//         vector<int> map(128,0);
//         for(auto c: t) map[c]++;
//         int counter=t.size(), begin=0, end=0, d=INT_MAX, head=0;
//         while(end<s.size()){
//             if(map[s[end++]]-->0) counter--; //in t
//             while(counter==0){ //valid
//                 if(end-begin<d)  d=end-(head=begin);
//                 if(map[s[begin++]]++==0) counter++;  //make it invalid
//             }  
//         }
//         return d==INT_MAX? "":s.substr(head, d);
//     }

// Template for most substring questions

// int findSubstring(string s){
//         vector<int> map(128,0);
//         int counter; // check whether the substring is valid
//         int begin=0, end=0; //two pointers, one point to tail and one  head
//         int d; //the length of substring

//         for() { /* initialize the hash map here */ }

//         while(end<s.size()){

//             if(map[s[end++]]-- ?){  /* modify counter here */ }

//             while(/* counter condition */){ 
                 
//                  /* update d here if finding minimum*/

//                 //increase begin to make it invalid/valid again
                
//                 if(map[s[begin++]]++ ?){ /*modify counter here*/ }
//             }  

//             /* update d here if finding maximum*/
//         }
//         return d;
//   }