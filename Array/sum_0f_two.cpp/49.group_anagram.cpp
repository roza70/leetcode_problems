class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.size()==0){
            return {};
        }
        unordered_map<string , vector<string>> ansMap;
        for(string s : strs){
            int count[26] ={0}; //frequency array
            //count characters
            for(char c : s){
                count [c - 'a']++;

            }
            //build key
            string key =" ";
            for (int i = 0; i<26 ; i++){
                key += "#" + to_string(count[i]);
            }
            // insert into hashmap
            ansMap[key].push_back(s);


        }
        //convert hashmap values to results
        vector<vector<string>> result;
        for(auto & pair : ansMap){
            result.push_back(pair.second);
        }
    return result;
    }
};