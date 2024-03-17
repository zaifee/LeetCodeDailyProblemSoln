class Solution {
public:
    vector<vector<int>> usingBruteForceApproch(vector<vector<int>>& intervals, vector<int>& newInterval){
        int i = 0;
//We are using i < intervals.size() instead of i < n because when we erase from the interval vector then the size will vary 
        while(i < intervals.size()){

            if(intervals[i][1] < newInterval[0]){
                i++; //range me nhi aa sakta interval ki
            }
            else if(intervals[i][0] > newInterval[1]){
                //range me hai -- to insert kardo 
                intervals.insert(intervals.begin()+i, newInterval);
                return intervals;

            }
            else{
                //overlap kar raha hai merge kardo uske according 
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
                //erase bhi to karna hai 
                intervals.erase(intervals.begin()+i);
            }
        }

        //baaki bache hoe interval ko inert kardo 
        intervals.push_back(newInterval); //yaha gali ki thi push karne me
        return intervals;
    }

    vector<vector<int>> usingOptimizedApproch(vector<vector<int>>& intervals, vector<int>& newInterval){
           
            vector<vector<int>> result;
            int n = intervals.size();
            int i = 0;

            while(i < n){
                if(intervals[i][1] < newInterval[0]){
                    result.push_back(intervals[i]);
                }
                else if(intervals[i][0] > newInterval[1]){
                    break;
                }else{
                    //merge karke choose karlo 
                    newInterval[0] =  min(newInterval[0], intervals[i][0]);
                    newInterval[1] = max(newInterval[1], intervals[i][1]);
                }   
                i++;
            }
//Merge k
            result.push_back(newInterval);
            while(i < n){
                result.push_back(intervals[i]);
                i++; //yaha ye galti ki thi
            }
            return result;
    }

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        return usingBruteForceApproch(intervals, newInterval);  //T.C - O(n ^2) approx keh sakte hai space- O(1)
        // return usingOptimizedApproch(intervals, newInterval); //T.C - O(n) bcz we are traversing the vector just once and spaceComplexity - O(n)

    }
};
