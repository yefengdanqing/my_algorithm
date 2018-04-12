class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       /* int len=strs.size();
        unordered_map<int,multiset<string>> hash_map;
        for(auto s: strs)
        {
            int tmp=0;
            for(int i=0;i<s.size();i++)
            {
               
                tmp+=s[i];
            }
            hash_map[tmp].insert(s);
        }
        vector<vector<string>> result;
        //for(int i=0;i<hash_map.size();i++)
        for(auto x : hash_map)
        {
            vector<string> str_vect(x.second.begin(),x.second.end());
            result.push_back(str_vect);
        }
        return result;*/
        unordered_map<string, multiset<string>> mp;
        for (string s : strs) {
            string t = s; 
            sort(t.begin(), t.end());
            mp[t].insert(s);
        }
        vector<vector<string>> anagrams;
        for (auto m : mp) { 
            vector<string> anagram(m.second.begin(), m.second.end());
            anagrams.push_back(anagram);
        }
        return anagrams;
    }
};
