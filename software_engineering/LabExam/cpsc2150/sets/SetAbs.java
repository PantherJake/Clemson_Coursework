package cpsc2150.sets;

import java.util.*;

public abstract class SetAbs<T> implements ISet<T> {

    /**
     * This method overrides the default implementation of {@link Object#toString()}.
     *
     * @return a string representation of the set
     * @pre none
     * @post [a string representation of the set]
     */
    @Override
    public String toString() {
        StringBuilder s = new StringBuilder();

        List<T> temp = new ArrayList<>();
        //fill intermediate list with everything in this set
        //We have to do this because there is no guarantee where remove will get the value from
        int size = getSize();
        for (int i = 0; i < size; i++) {
            temp.add(remove());
        }

        //make string and refill this
        s.append("{");
        for (int i = 0; i < size; i++) {
            s.append(temp.get(i));

            //add a comma except the last element
            if (i < size - 1) {
                s.append(", ");
            }

            //add the value back into the set
            add(temp.get(i));
        }
        s.append("}");

        return s.toString();
    }
}