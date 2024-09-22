class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
      unordered_map<string, int> banndedset;
      for(int i = 0 ; i< bannedWords.size(); i++){
        banndedset[bannedWords[i]]++;
      }
    int count = 0;
      for(int i = 0; i < message.size(); i++){
        if(banndedset[message[i]] != 0){
            count++;
            if(count >= 2){
                return true;
            }
        }
      }
      return false;
    }
};