class Solution {
public:
    string solveUsingMap(string order, string s){
        // unordered_map<int,int>map; 
        int count[26] = {0};
        //Putting all the characters of string s in the array or map 
        for(auto &ch : s){
             count[ch-'a']++;
        }

        string res = "";
        // Matching the character of order in the array if present pushing into the ans and reducing the freq in the array 
        for(auto &ch : order){

            while(count[ch-'a'] > 0){
                res.push_back(ch);
                //reducing freq of character that was appended 
                count[ch-'a']--;
            }
        }

        //appending rest of the character of string s
        for(auto &ch: s){
            if(count[ch-'a'] > 0){
                res.push_back(ch);
            }
        }

        return res;

//Time Compexity: O(n+m) where n and m are the length of string order and s
//Space complexity : O(1) //bcz we are using just array of const size
    }

    void solveUsingCustomComparator(string order, string &s){
         vector<int> index(26,-1);
         

         for(int i = 0; i < order.length(); i++){
             char ch = order[i];
             index[ch-'a'] = i; //putting index of character
         }

      
        sort(s.begin(), s.end(), [& index](char &ch1, char &ch2){
            return  index[ch1-'a'] < index[ch2-'a']; //yaha character ko sort karna to ch-'a' karna padega nhi to error aayega 
            //ascending order me character palc kar dega
        });

      //Time Complexty - O(1) + O(n log n) //traversing + sorting complexity 
      //Space Compexity - O(1) //just using a vector of const size 


    }


    string customSortString(string order, string s) {
        // string ans = solveUsingMap(order, s);
        // return ans; 
          solveUsingCustomComparator(order, s);
          return s;
          
    }
};
