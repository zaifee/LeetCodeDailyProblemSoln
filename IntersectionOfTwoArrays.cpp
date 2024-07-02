//**********************************Appraoch 1*****************************************\\
//Time Complexity - O(n)
//Space Complexity - O(n) bcz we are using map
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        int m = nums2.size();

        unordered_map<int, int> mp;
        for(auto &num: nums1){
            mp[num]++;
        }

        vector<int> ans;
        for(int i=0; i<m; i++){

            int num = nums2[i];

            if(mp[num] > 0){
                mp[num]--;
                ans.push_back(num);
                
            }
        }

        return ans;
        
    }
};
//**********************************Appraoch 2*****************************************\\
//Time Complexity - O(n) + O(n log n) bcz of traversing and sorting;
// Space Complexity- O(n);

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> ans;
        
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        int i = 0;
        int j = 0;

        while(i < n && j < m){
            if(nums1[i] == nums2[j]){
                ans.push_back(nums1[i]);
                i++;
                j++;
            }
            else if(nums1[i] > nums2[j]){
                    j++;
            }else{
                i++;
            }
        }

        return ans;

        // Time Complexity - O(n) + O(n log n); 
        //Space Comp - O(n); bcz we are using vector
        
    }
};
