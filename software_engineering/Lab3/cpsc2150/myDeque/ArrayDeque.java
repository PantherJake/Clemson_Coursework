package cpsc2150.myDeque;


import java.lang.reflect.Array;

/** @invariant
 * myQ consists of valid characters only
 * myLength <= MAX_LENGTH
 */
public class ArrayDeque implements IDeque {
        // where the data is stored. myQ[0] is the front of the deque
        private Character[] myQ;
        // tracks how many items in the deque
        // also used to find the end of the deque
        private int myLength;
        // complete the class

        /** @pre
         * myLength = 0
         * myQ is a new ArrayList with MAX_LENGTH indices
         */
        public ArrayDeque() {
                myLength = 0;
                myQ = new Character[MAX_LENGTH];
        }

        @Override
        public void enqueue(Character X) {
                if(myLength > MAX_LENGTH) {
                        System.out.println("Error: List is full!");
                        return;
                }

                myLength++;
                myQ[myLength-1] = X;
        }
        /** @post
         * myLength = #myLength + 1
         * myQ[myLength] = X
         */

        @Override
        public Character dequeue() {
                Character X = myQ[0];

                for(int i = 0; i < myLength-1; ++i) {
                        myQ[i] = myQ[i+1];
                }

                myLength--;
                return X;
        }
        /** @post
         * X = myQ[0]
         * myLength = #myLength - 1
         */

        @Override
        public void inject(Character X) {
                if(myLength > MAX_LENGTH) {
                        System.out.println("Error: List is full!");
                        return;
                }

                myLength++;

                for(int i = 0; i < myLength-1; ++i) {
                        myQ[i] = myQ[i+1];
                }

                myQ[0] = X;
        }
        /** @post
         * myQ[0] = X
         * myLength = #myLength + 1
         * @return
         */

        @Override
        public Character removeLast() {
                Character X = myQ[myLength-1];
                myLength--;
                return X;
        }
        /** @post
         * X = myQ[myLength]
         * myLength = #myLength - 1
         */

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
        /** @post
         * myQ is set to NULL at each index
         * myLength = 0
         */
}
