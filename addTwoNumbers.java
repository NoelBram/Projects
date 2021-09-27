/**     Created: 06/25/20
 *      Modified: 11/06/20
 *      Compleeted: 07/01/20
 * 
 * Description: 
 *      You are given two non-empty linked lists representing two non-negative integers. 
 *      The digits are stored in reverse order and each of their nodes contain a single digit.
 *      Add the two numbers and return it as a linked list.
 *      You may assume the two numbers do not contain any leading zero, 
 *      except the number 0 itself.
 *      
 *      @author Noel Bramila 
 * 
 * The Definition of a singly-linked list in Java:
 *      public class ListNode {
 *          int val;
 *          ListNode next;
 *          ListNode(int x) {
 *              val = x;
 *              next = null;
 *          }
 *      }
 */

import java.io.*; 
import java.util.*; 

public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
    ListNode dummyHead = new ListNode(0);
    ListNode p = l1, q = l2, currentHead = dummyHead;
    int carry = 0;
    
    while (p != null || q != null) {
        int x = (p != null) ? p.val : 0;    // First Node of l1 is now declared to x
        int y = (q != null) ? q.val : 0;    // First Node of l2 is now declared to y

        int sum = carry + x + y;
        carry = sum / 10;

        currentHead.next = new ListNode(sum % 10);
        currentHead = currentHead.next;     // First Node of the sum of l1 & l2 is now declared to currentHead

        if (p != null){
            p = p.next;
        }
        if (q != null){
            q = q.next;
        }
    }
    if (carry > 0) {
        currentHead.next = new ListNode(carry);     // Carring the value(if there is one) to the second node of the sum of l1 and l2
    }
    return dummyHead.next;
}