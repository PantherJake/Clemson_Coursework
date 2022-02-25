package cpsc2150.MyDeque;

/** @invariant
 * myQ consists of valid characters only
 * myLength <= MAX_LENGTH
 */
public class ArrayDeque extends AbsDeque implements IDeque {
    // where the data is stored. myQ[0] is the front of the deque
    private Character[] myQ;
    // tracks how many items in the deque
    // also used to find the end of the deque
    private int myLength;
    // complete the class

    public ArrayDeque() {
        myLength = 0;
        myQ = new Character[MAX_LENGTH];
    }
    /**
     * @post
     * myLength = 0
     * myQ is a new character array with MAX_LENGTH indices
     */

    @Override
    public void enqueue(Character X) {
        if(myLength >= MAX_LENGTH) {
            System.out.println("Error: List is full!");
            return;
        }

        myLength++;
        myQ[myLength-1] = X;
    }

    @Override
    public Character dequeue() {
        if(myLength == 0) {
            System.out.println("Deque is empty!");
            return ' ';
        }
        Character X = myQ[0];

        for(int i = 0; i < myLength-1; ++i) {
            myQ[i] = myQ[i+1];
        }

        myLength--;
        return X;
    }

    @Override
    public void inject(Character X) {
        if(myLength >= MAX_LENGTH) {
            System.out.println("Error: List is full!");
            return;
        }

        for(int i = myLength; i > 0; --i) {
            if(myLength > 1) myQ[i+1] = myQ[i];
        }

        myLength++;
        myQ[0] = X;
    }

    @Override
    public Character removeLast() {
        if(myLength == 0) {
            System.out.println("Deque is empty!");
            return ' ';
        }

        Character X = myQ[myLength-1];
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
