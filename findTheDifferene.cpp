class Solution {
public:
    char solveUsingMap(string s, string t){
         unordered_map<char, int>mapping;

        for(auto &ch: s){
            mapping[ch]++;
        }

        // for(auto &ch : t){
        //     mapping[ch]--;

        //     if(mapping[ch] < 0){
        //         return ch;
        //     }
        // }

          for(auto &ch: t){
              if(mapping.find(ch) == mapping.end())
                return ch;  
          }
        // it will never comes here 
        return 'x';
    }

    char solveUsingSumDiff(string s, string t){

        int sum_s = 0;
        for(auto &ch: s){
            sum_s += ch;
        }

        int sum_t = 0;
        for(auto &ch: t){
            sum_t += ch;
        }

        return  char(sum_t - sum_s);
    }
    
    char solveUsingXOR(string s, string t){
        int XOR = 0;

        for(auto ch : s){
            XOR ^= ch;
        }

        for(auto ch: t){
            XOR ^= ch;
        }

        return (char)XOR;
    }


    char findTheDifference(string s, string t) {
    //    char ans = solveUsingMap(s, t);
    //    return ans;  
          
        //   char ans = solveUsingSumDiff(s, t);
        //   return ans;

         char ans = solveUsingXOR(s, t);
          return ans;
    }
};
