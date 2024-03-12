
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        int prefixSum = 0;
        unordered_map<int, ListNode*>mp;

        ListNode* dummyNode = new ListNode(0);
        dummyNode->next = head;
        mp[0] = dummyNode;

        while(head != NULL){

            prefixSum += head->val;

            if(mp.find(prefixSum) != mp.end()){
                //to delete karna hai 
                ListNode* start = mp[prefixSum];
                ListNode* temp = start;
                int pSum = prefixSum;

                 while(temp != head){
                    temp = temp->next;
                    pSum += temp->val;
                
                if(temp != head)
                    mp.erase(pSum);
                 }

                 start->next = temp->next;

            }
            else{
                mp[prefixSum] = head;
            }
                head = head->next;

        }

        
        return dummyNode->next;

        //Time Complexity - O(n) where n is the length of the list
        // Space Complexity - O(n) //bcz we are storing the elements in the map


    }
};
