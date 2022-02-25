package cpsc2150.myDeque;

public interface IDeque {
    /**
     * A deque containing characters.
     * A deque is a data structure a double-ended queue that allows you
     * to insert and remove from both ends.
     * This deque is bounded by MAX_LENGTH
     */
        public static final int MAX_LENGTH = 100;
        // Adds x to the end of the deque
        public void enqueue(Character x);
        //removes and returns the Character at the front of the deque
        public Character dequeue();
        // Adds x to the front of the deque
        public void inject(Character x);
        //removes and returns the Character at the end of the deque
        public Character removeLast();
        //returns the number of Characters in the deque
        public int length();
        //clears the entire deque
        public void clear();
    }
