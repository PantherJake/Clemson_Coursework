package cpsc2150.MyDeque;

import java.lang.reflect.Array;

import static java.lang.System.exit;

/** @invariant 0 <= myLength <= MAX_LENGTH
 * self = myQ[myLength]
 */
public class ArrayDeque<T> extends AbsDeque<T> implements IDeque<T> {
    // where the data is stored. myQ[0] is the front of the deque
    private T[] myQ;
    // tracks how many items in the deque
    // also used to find the end of the deque
    private int myLength;
    // complete the class

    public ArrayDeque() {
        myLength = 0;
        myQ = (T[]) new Object[MAX_LENGTH];
    }
    /**
     * @post
     * myLength = 0
     * myQ is a new character array with MAX_LENGTH indices
     */

    @Override
    public void enqueue(T X) {
        if(myLength >= MAX_LENGTH) {
            System.out.println("Error: List is full!");
            return;
        }

        myQ[myLength] = X;
        myLength++;
    }

    @Override
    public T dequeue() {
        T X = myQ[0];

        for(int i = 1; i <= myLength-1; i++){
            myQ[i-1] = myQ[i];
        }

        myLength--;
        return X;
    }

    @Override
    public void inject(T X) {
        if(myLength >= MAX_LENGTH) {
            System.out.println("Error: List is full!");
            return;
        }

        for(int i = myLength; i > 0; --i) {
            myQ[i] = myQ[i-1];
        }

        myLength++;
        myQ[0] = X;
    }

    @Override
    public T removeLast() {
        T X = myQ[myLength-1];
        myQ[myLength-1] = null;
        myLength--;
        return X;
    }

    @Override
    public int length() {
        return myLength;
    }

    @Override
    public void clear() {
        for(int i = 0; i < myLength; ++i) {
            myQ[i] = myQ[myLength+1];
        }

        myLength = 0;
    }
}
