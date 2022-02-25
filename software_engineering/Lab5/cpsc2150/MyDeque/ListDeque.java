package cpsc2150.MyDeque;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

import static java.lang.System.exit;

/** @invariant
 * myQ consists of valid characters only
 * myQ.size() <= 100
 */
public class ListDeque<T> extends AbsDeque<T> implements IDeque<T> {
    // this time store the deque in a list
// myQ.get(0) is the front of the deque
    private List<T> myQ;
// complete the class

    public ListDeque() {
        myQ = new ArrayList<T>();
    }
    /**
     * @post
     * myQ is a new "empty" list whose size cannot exceed MAX_LENGTH
     */

    @Override
    public void enqueue(T X) {
        if(myQ.size() > MAX_LENGTH) {
            System.out.println("Error: List is full!");
            return;
        }

        myQ.add(X);
    }

    @Override
    public T dequeue() {
        T X = myQ.get(0);
        myQ.remove(0);
        return X;
    }

    @Override
    public void inject(T X) {
        if(myQ.size() > MAX_LENGTH) {
            System.out.println("Error: List is full!");
            return;
        }

        myQ.add(0, X);
    }

    @Override
    public T removeLast() {
        T X = myQ.get(myQ.size()-1);
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
