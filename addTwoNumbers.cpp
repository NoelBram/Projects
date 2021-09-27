/*  Created: 06/24/20
    Modified: 11/06/20
    Completed: 11/06/20

Description:
    You are given two non-empty linked lists representing two non-negative integers. 
    The digits are stored in reverse order and each of their nodes contain a single digit. 
    Add the two numbers and return it as a linked list.
    You may assume the two numbers do not contain any leading zero, 
    except the number 0 itself.

The Definition of a singly-linked list in c++:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };
 */
#include "brambila.h"

class Solution {
    public:    
        ListNode *addTwoNumbers(ListNode *l1, ListNode *l2){
            return addNodes(l1, l2, 0);
        }
        ListNode *addNodes(ListNode *l1, ListNode *l2, int carry){
            if(!l1 && !l2 && carry==0){     
                return NULL;
            }

            int a = 0, b = 0; 

            if(l1){ 
                a = l1 -> val;          // First Node of l1 is now declared to a
            }
            if(l2){ 
                b = l2 -> val;          // First Node of l2 is now declared to b
            }

            int value = a + b + carry;  

            ListNode *head = new ListNode(value %10);   // The first node to the sum of the two linked lists
            head -> next = addNodes(l1 ? l1 -> next: NULL, l2 ? l2 -> next: NULL, value / 10);
            return head;                // The sum of the two linked lists 
        }
};    