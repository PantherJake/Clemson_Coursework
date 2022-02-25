package cpsc2150.sets;

public class ArraySet<T> extends SetAbs<T> implements ISet<T> {

    private T[] mySet;
    private int length;

    public ArraySet() {
        mySet = (T[]) new Object[MAX_SIZE];
        length = 0;
    }

    public void add(T val) {
        for(int i = length; i > 0; --i) {
            mySet[i] = mySet[i-1];
        }

        length++;
        mySet[0] = val;
    }

    public T remove() {
        T val = mySet[0];

        for(int i = 1; i <= length-1; i++){
            mySet[i-1] = mySet[i];
        }

        length--;
        return val;
    }

    public boolean contains(T val) {
        for(int i = 0; i < length-1; ++i) {
            if(mySet[i] == val) return true;
        }

        return false;
    }

    public int getSize() { return length; }
}
