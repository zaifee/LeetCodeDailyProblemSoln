class Solution {
public:
    vector<int> solveUsingTwoSets(vector<int>& nums1, vector<int>& nums2){
        unordered_set<int> st(begin(nums1), end(nums1));
        unordered_set<int> st2;

        for(auto &num: nums2){
            if(st.find(num) != st.end()){
                st2.insert(num); //it means set1 and nums2 elements are equal 
            }
        }
        vector<int> res(begin(st2), end(st2));
        return res;

        //Time Complexity - O(m+n); m and n are the size of nums vector 
        //Space complexity - O(m+n);

    }
    vector<int> solveUsingOneSet(vector<int>& nums1, vector<int>& nums2){
        unordered_set<int> st(begin(nums1), end(nums1));
        vector<int> res;
        for(auto &num: nums2){
            if(st.find(num) != st.end()){
               res.push_back(num);
               st.erase(num); //erase the element which was unequal at that time
            }
        }
        
        return res;

        //Time Complexity - O(m+n); m and n are the size of nums vector 
        //Space complexity - O(m);

    }
    bool binarySearch(vector<int>& nums1, int target){
        int s = 0, e = nums1.size()-1;
        while(s <= e){
            int mid = s + (e-s)/2;

            if(nums1[mid] == target) 
                return true; //yaha galti ki thi
            else if(nums1[mid] < target)
                s = mid + 1;
            else
                e = mid-1;
        }
        return false;
    }

    vector<int> solveUsingBinarySearch(vector<int>& nums1, vector<int>& nums2){
        sort(nums1.begin(), nums1.end()); //sorting done 
        unordered_set<int> st;
        for(auto &num: nums2){
            if(binarySearch(nums1, num)){
                st.insert(num);
            }
        }
        vector<int> res(begin(st), end(st));
        return res;

    }
    vector<int> solveUsingTwoPointersApproach(vector<int>& nums1, vector<int>& nums2){
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int m = nums1.size();
        int n = nums2.size();
        int i = 0; //representing nums1
        int j = 0; //representing nums2
        vector<int>res;
        while(i < m && j < n){

            if(nums1[i] == nums2[j]){
                res.push_back(nums1[i]);

                //handling with duplicates element 
                while(i < m-1 && nums1[i] == nums1[i+1]){
                    i++;
                }
                while(i < n-1 && nums2[j] == nums2[j+1]){
                    j++;
                }

                    
                i++;
                j++;
            }
            else if(nums1[i] < nums2[j]){
                i++;
            }
            else{
                j++;
            }
        }
        return res;
    }



    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // auto ans = solveUsingTwoSets(nums1, nums2);
        // return ans; 
        //    auto ans = solveUsingOneSet(nums1, nums2);
        //    return ans;
            // auto ans = solveUsingBinarySearch(nums1, nums2);
            // return ans;
            auto ans = solveUsingTwoPointersApproach(nums1, nums2);
            return ans;




    }
};
