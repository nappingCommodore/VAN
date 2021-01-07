// https://leetcode.com/problems/add-two-numbers/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL || l2 == NULL) {
            return NULL;
        }
        
        ListNode* result = new ListNode();
        ListNode* tmpRes = result;
        ListNode* prev = result;
        int carry = 0;
        while(l1 != NULL && l2 != NULL) {
            int tmp = l1->val + l2->val + carry;
            tmpRes->val = tmp%10;
            carry = tmp/10;
            tmpRes->next = new ListNode();
            prev = tmpRes;
            tmpRes = tmpRes->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1 != NULL) {
            int tmp = l1->val + carry;
            carry = tmp/10;
            tmpRes->val = tmp%10;
            l1 = l1->next;
            tmpRes->next = new ListNode();
            prev = tmpRes;
            tmpRes = tmpRes->next;
        }
        while(l2 != NULL) {
            int tmp = l2->val + carry;
            carry = tmp/10;
            tmpRes->val = tmp%10;
            l2 = l2->next;
            tmpRes->next = new ListNode();
            prev = tmpRes;
            tmpRes = tmpRes->next;
        }
        if(carry != 0) {
            tmpRes->val = 1;
        } else {
            prev->next = NULL;
        }
        
        return result;
    }
};