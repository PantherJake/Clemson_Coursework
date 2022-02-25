package cpsc2150.myDeque;

import java.util.*;

/** @invariant
 * myQ consists of valid characters only
 * myQ.size() <= 100
 */
public class ListDeque implements IDeque {
    // this time store the deque in a list
// myQ.get(0) is the front of the deque
    private List<Character> myQ;
// complete the class

    /** @pre
     * myQ is a new linked list with no elements
     */
    public ListDeque() {
         myQ = new LinkedList<>();
    }

    @Override
    public void enqueue(Character X) {
        if(myQ.size() > MAX_LENGTH) {
            System.out.println("Error: List is full!");
            return;
        }

        myQ.add(myQ.size(), X);
    }
    /** @post
     * myQ has an  element (X) placed to the back.
     */

    @Override
    public Character dequeue() {
        Character X = myQ.get(0);
        myQ.remove(0);
        return X;
    }
    /** @post
     * X = myQ at index 0
     * myQ removes the element at index 0
     */

    @Override
    public void inject(Character X) {
        if(myQ.size() > MAX_LENGTH) {
            System.out.println("Error: List is full!");
            return;
        }

        myQ.add(0, X);
    }
    /** @post
     * myQ has an element (X) placed at the front
     */

    @Override
    public Character removeLast() {
        Character X = myQ.get(myQ.size()-1);
        myQ.remove(myQ.size()-1);
        return X;
    }
    /** @post
     * X = the element at the very back of the list
     * myQ removes the element at the last index
     */

    @Override
    public int length() { return myQ.size(); }

    @Override
    public void clear() {
        myQ.clear();
    }
    /** @post
     *  myQ is set back to NULL and all elements are cleared.
     */
}
