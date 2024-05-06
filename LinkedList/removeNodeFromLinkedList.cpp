/******************************************** Approach 1 ***********************************************\
  // T.C : O(n); n here is the size of the linked list 
  // S.C: O(n); bcz we are using the stack
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> st;

        ListNode* curr = head;
        while(curr != NULL){
            st.push(curr);
            curr = curr->next;
        }

        //Now we are ready to perform operation on the list

        //Step1: First pop out the fist value from the stack
        curr = st.top();
        st.pop();

        //Step2: Set the Max Value 
        int maxVal = curr->val; 

        ListNode* newNode = new ListNode(curr->val); 
        while(!st.empty()){
            curr = st.top();
            st.pop();

            if(curr->val < maxVal){
                continue; //we will ignore that value
            }else{
                ListNode* resultNode = new ListNode(curr->val);
                resultNode->next = newNode;
                newNode = resultNode;
                maxVal = curr->val;
            }
        }
        return newNode;
    }
};
/******************************************** Approach 2 ***********************************************\
  class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        // Approch 2 : Using Recusrion 
        

        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* nextNode = removeNodes(head->next);

        if(head->val < nextNode->val){
            delete(head);
            return nextNode;
        }
        
            head->next = nextNode;
            return head;
    }
};

// T.C : O(n); n here is the size of the linked list 
  // S.C: O(1)
