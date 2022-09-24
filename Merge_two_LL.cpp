#define node ListNode
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        node*finalhead = NULL;
        node*finaltail = NULL;

        //check initial things
        if(head1 == NULL){
            return head2;
        }
        if(head2 == NULL){
            return head1;
        }

        while(head1 != NULL and head2 != NULL){
            //we are comparing the first node
            if(finalhead == NULL and finaltail == NULL){

                if(head1->val<head2->val){
                    finalhead = head1;
                    finaltail = head1;
                    head1 = head1->next;
                }
                else{
                    finalhead = head2;
                    finaltail = head2;
                    head2 = head2->next;
                }

            }
            else{

                if(head1->val < head2->val){
                    finaltail->next = head1;
                    finaltail = finaltail->next;
                    head1 = head1->next;
                }
                else{
                    finaltail->next = head2;
                    finaltail = finaltail->next;
                    head2 = head2->next;
                }
            }
        }
        if(head1 != NULL){
            finaltail->next = head1;
        }
        if(head2 != NULL){
            finaltail->next = head2;
        }

        return finalhead;
    }
};