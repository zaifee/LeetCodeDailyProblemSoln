/********************************************* Approach 1(Using UnorderedMap) *******************************************\
  // T.C: Complexity : O(n log n); bcz of sorting 
  // S.C: Complexity: O(n) bcz we are using map 

  class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        // T.C - O(n logn)
        // S.C - O(n) bcz we are using map 
        int n = score.size();
        vector<string> res(n);
        unordered_map<int, int> mp;

        for(int i=0; i<n; i++){
            mp[score[i]] = i;
        }

        //Now we cant sort easily in descending order
        sort(score.begin(), score.end(), greater<int>()); 

        for(int i=0; i < n; i++){
            if(i == 0){
                //first rank athlete 
                int ath = mp[score[i]];
                res[ath] = "Gold Medal";
            }else if(i == 1){
                 int ath = mp[score[i]];
                res[ath] = "Silver Medal";
            }else if (i == 2){
                int ath = mp[score[i]];
                res[ath] = "Bronze Medal";
            }else{
                int ath = mp[score[i]];
                res[ath] = to_string(i+1);
            }
        }

        return res;

    }
};

/********************************************* Approach 2(Using MaxHeap) *******************************************\
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        
        // Using MaxHeap 
        int n = score.size();
        vector<string> res(n);

        // Max Heap
        priority_queue<pair<int, int>> pq;

        for(int i=0; i<n; i++){
            pq.push({score[i], i});
        }

        int rank = 1;
        while(!pq.empty()){
            int post = pq.top().second; //second represent idx of element 
            pq.pop();

            if(rank == 1){
                res[post] = "Gold Medal";
            }else if(rank == 2){
                res[post]= "Silver Medal";
            }else if(rank == 3){
                res[post] = "Bronze Medal";
            }else{
                res[post] = to_string(rank);
            }
                rank++;
        }

        return res;
    }
};
