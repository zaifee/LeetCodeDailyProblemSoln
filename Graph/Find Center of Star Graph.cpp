//***********************************************Approach 1 ****************************************************\\
//Time Complexity : O(n); because we are traversing each and every element of the Map;
//Space Complexity: O(n); because we are storing degree of Node in the Map;

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, int> degree;

        for(auto &it: edges){

            int u = it[0];
            int v =  it[1];

            degree[u]++;
            degree[v]++;
        }

        for(auto &cent: degree){
            if(cent.second > 1){
                return cent.first;
            }
        }

        return -1;
    }
};
//***********************************************Approach 2 ****************************************************\\
//Time Complexity : O(1); because we are just taking two edges of the map and comparing with it ~O(2n) = O(1);
//Space Complxity: O(1); 
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        
        vector<int> firstEdge = edges[0];
        vector<int> secondEdge = edges[1];

        //Now we will start comparing 

        if(firstEdge[0] == secondEdge[0] || firstEdge[0] == secondEdge[1]){
            return firstEdge[0];
        }

        return firstEdge[1];
    }
};

