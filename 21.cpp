//Time Complexity : O(n)
//Space Complexity : O(n)

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        //jab dono list  me koi element nhi hai to hum null value ke roop me kisi ka bhi head return kar sakte hai
        
         if(list1 == NULL){
            return list2;
        }
         if(list2 == NULL){
            return list1;
        }


        ListNode* newHead = NULL;
        ListNode* temp = NULL;



            int val1 = list1->val;
            int val2 = list2->val;

        
                if(val1<val2){
                    newHead = new ListNode(val1);
                    list1=list1->next;
                }
                else{
                    newHead = new ListNode(val2);
                    list2=list2->next;
                }

                temp = newHead;
            



        while(list1 != NULL && list2 != NULL){
           
            val1 = list1->val;
            val2 = list2->val;

                if(val1<val2){
                    temp->next = new ListNode(val1);
            
                    list1=list1->next;
                }
                else{
                    temp->next = new ListNode(val2);
                
                    list2=list2->next;
                }
                temp=temp->next;

            }
        

        if(list1 != NULL){
            temp->next = list1;
        }
        else if(list2 != NULL ){
            temp->next = list2;
        }


        return newHead;
        
    }
};