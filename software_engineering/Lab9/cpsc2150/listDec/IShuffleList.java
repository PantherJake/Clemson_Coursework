package cpsc2150.listDec;

import java.util.List;
import java.util.Random;

// Jacob Vickio, Gibbs Robinson, Jimmy Martinez

/**
 * This interface extends the list interface adding the methods 'shuffle' and 'swap'
 *
 * Initialization Ensures: The user will be working with an empty list.
 *
 * @param <T> - Data type of the list is passed as a generic
 */
public interface IShuffleList<T> extends List<T> {

    /**
     * This method allows for the user to shuffle the elements in the list *swaps* times.
     *
     * @param swaps - the number of times that positions in the list will be swapped
     *
     * @pre   0 <= swaps < myList.size()
     * @post  [Two random elements in myList are swapped with each other *swaps* times]
     */
    default void shuffle(int swaps) {
        Random r = new Random();

        for(int i = 0; i < swaps; ++i) {
            int rNum1 = r.nextInt(size());
            int rNum2 = r.nextInt(size());

            swap(rNum1, rNum2);
        }
    }

    /**
     * This method allows for the user to swap two elements in the list at positions i and j
     *
     * @param i - Position in the list that will be swapped with position j
     * @param j - Position in the list that will be swapped with position i
     *
     * @pre   0 <= i < myList.size() AND 0 <= j < myList.size()
     * @post  [The value at position i and the value at position j are swapped]
     */
    default void swap(int i, int j) {
        T a = get(i);
        set(i, get(j));
        set(j, a);
    }
}
