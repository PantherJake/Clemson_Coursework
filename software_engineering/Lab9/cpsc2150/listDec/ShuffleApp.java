package cpsc2150.listDec;

import java.util.ArrayList;

// Jacob Vickio, Gibbs Robinson, Jimmy Martinez

public class ShuffleApp {

    /**
     * <p>
     * This method is our main entry point to our application.
     * </p>
     *
     * @param args
     *            Program arguments (not used)
     */
    public static void main(String[] args) {
        int max_in_list = 25;
        int num_swaps = 50;
        int num_shuffles = 10;
        IShuffleList<Integer> sl = new ShuffleList<>(new ArrayList<Integer>());

        for (int i = 1; i <= max_in_list; i++) {
            sl.add(i);
        }

        System.out.println("Unshuffled List:");
        System.out.println(sl.toString());

        for (int i = 1; i <= num_shuffles; i++) {
            sl.shuffle(num_swaps);
            System.out.println("Shuffled " + i + " times:");
            System.out.println(sl.toString());
        }
    }
}
