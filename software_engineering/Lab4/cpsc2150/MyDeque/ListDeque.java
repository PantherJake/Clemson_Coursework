package cpsc2150.MyDeque;

import java.util.*;

/** @invariant
 * myQ consists of valid characters only
 * myQ.size() <= 100
 */
public class ListDeque extends AbsDeque implements IDeque {
    // this time store the deque in a list
// myQ.get(0) is the front of the deque
    private List<Character> myQ;
// complete the class

    public ListDeque() {
        myQ = new LinkedList<>();
    }
    /**
     * @post
     * myQ is a new "empty" list whose size cannot exceed MAX_LENGTH
     */

    @Override
    public void enqueue(Character X) {
        if(myQ.size() > MAX_LENGTH) {
            System.out.println("Error: List is full!");
            return;
        }

        myQ.add(myQ.size(), X);
    }

    @Override
    public Character dequeue() {
        if(myQ.size() == 0) {
            System.out.println("Deque is empty!");
            return ' ';
        }

        Character X = myQ.get(0);
        myQ.remove(0);
        return X;
    }

    @Override
    public void inject(Character X) {
        if(myQ.size() > MAX_LENGTH) {
            System.out.println("Error: List is full!");
            return;
        }

        myQ.add(0, X);
    }

    @Override
    public Character removeLast() {
        if(myQ.size() == 0) {
            System.out.println("Deque is empty!");
            return ' ';
        }

        Character X = myQ.get(myQ.size()-1);
        myQ.remove(myQ.size()-1);
        return X;
    }

    @Override
    public int length() { return myQ.size(); }

    @Override
    public void clear() {
        myQ.clear();
    }
}
