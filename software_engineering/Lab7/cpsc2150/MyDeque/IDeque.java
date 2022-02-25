package cpsc2150.MyDeque;

public interface IDeque<T> {
    /**
     * @ensures
     * An empty Deque with different insert, remove, and get operations.
     * @define
     * A deque is a data structure a double-ended queue that allows you
     * to insert and remove from both ends.
     * @constraint
     * This deque is bounded by MAX_LENGTH
     */
    public static final int MAX_LENGTH = 100;

    // Adds x to the end of the deque
    public void enqueue(T X);
    /**
     * @pre
     * length < MAX_LENGTH
     * @post
     * myQ has an  element (X) placed to the back.
     * length = #length + 1
     * @param
     * /x is the character that will be placed to the back
     */

    //removes and returns the Character at the front of the deque
    public T dequeue();
    /**
     * @pre
     * length > 0
     * @post
     * myQ has an element (X) removed from the front.
     * length = #length - 1
     * @return
     * x is the character removed
     */

    // Adds x to the front of the deque
    public void inject(T X);
    /**
     * @pre
     * length < MAX_LENGTH
     * @post
     * myQ has an element (X) placed at the front
     * length = #length + 1
     * @param
     * /x is the character that will be injected into the front
     */

    //removes and returns the Character at the end of the deque
    public T removeLast();
    /**
     * @pre
     * length > 0
     * @post
     * X = the element at the very back of the list
     * myQ removes the element at the last index
     * @return
     * x is the character removed from end
     */

    //returns the number of Characters in the deque
    public int length();
    /**
     * @post
     * @return
     * the length of the deque is returned
     */

    //clears the entire deque
    public void clear();
    /**
     * @post
     * myQ is set back to NULL and all elements in deque are cleared.
     */

    @Override
    public String toString();

    default T peek() {
        T X = this.dequeue();
        this.inject(X);
        return X;
    }
    /**
     * @pre
     * length > 0
     * @post
     * @return
     * X is returned as the character at the front of the Deque
     */

    default T endOfDeque() {
        T X = this.removeLast();
        this.enqueue(X);
        return X;
    }
    /**
     * @pre
     * length > 0
     * @post
     * @return
     * X is returned as the character at the end of the Deque
     */

    default void insert(T c, int pos) {
        T X;

        for(int i = 1; i < pos; ++i) {
            X = this.dequeue();
            this.enqueue(X);
        }

        this.inject(c);

        for(int i = 1; i < pos; ++i) {
            X = this.removeLast();
            this.inject(X);
        }
    }
    /**
     * @pre
     * @param
     * /c is a valid character
     * pos < length
     * @post
     * length = #length + 1
     * myQ has new element (c) at position (pos)
     */

    default T remove(int pos) {
        T X, temp;

        for(int i = 1; i < pos; ++i) {
            temp = this.dequeue();
            this.enqueue(temp);
        }

        X = this.dequeue();

        for(int i = 1; i < pos; ++i) {
            temp = this.removeLast();
            this.inject(temp);
        }

        return X;
    }
    /**
     * @pre
     * pos < length
     * @post
     * @return
     * X is returned as the character that is removed from the Deque
     */

    default T get(int pos) {
        T X, temp;

        for(int i = 1; i < pos; ++i) {
            temp = this.dequeue();
            this.enqueue(temp);
        }

        X = this.peek();

        for(int i = 1; i < pos; ++i) {
            temp = this.removeLast();
            this.inject(temp);
        }

        return X;
    }
    /**
     * @pre
     * pos < length
     * @post
     * @return
     * X is returned as the character found at position (pos) in the Deque
     */
}
