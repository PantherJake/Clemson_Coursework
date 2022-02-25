package cpsc2150.sets;

import java.util.*;

public class ListSet<T> extends SetAbs<T> implements ISet<T> {

    /**
     * Correspondences size = mySet.size() and self = mySet
     *
     * @invariants [set contains no duplicate values]
     */
    private final List<T> mySet;

    /**
     * @post [Set is empty]
     */
    public ListSet() {
        mySet = new ArrayList<>();
    }

    public void add(T val) {
        mySet.add(val);
    }

    public T remove() {
        /*Sets are unordered, so removing from a particular position is meaningless
        To make sure you don't assume that remove removes from a particular position
        I am using random numbers. There is no "real" reason to do this, but it will
        help you identify issues in your code that could pop up with a different implementation
        I am forcing you to consider what would happen if you had no idea which
        position would be removed by the remove method
        YOU MAY NOT DELETE THE RANDOMIZATION CODE TO MAKE YOUR DEFAULT METHODS WORK
        */
        Random rand = new Random();
        int r_num = rand.nextInt(this.getSize());

        return mySet.remove(r_num);
    }

    public boolean contains(T val) {
        return mySet.contains(val);
    }

    public int getSize() {
        return mySet.size();
    }
}