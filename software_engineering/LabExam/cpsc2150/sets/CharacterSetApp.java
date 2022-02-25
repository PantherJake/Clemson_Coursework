package cpsc2150.sets;

import java.util.*;

import static java.lang.System.exit;

public class CharacterSetApp {

    private static final int EXIT_CHOICE = 2;

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        //Print a menu of options
        printMenu();
        int input = Integer.parseInt(in.nextLine());
        while (input != EXIT_CHOICE) {
            if (input == 1) {
                //Make each set
                System.out.println("Make set 1");
                ISet<Character> set1 = getSet(in);
                System.out.println("Make set 2");
                ISet<Character> set2 = getSet(in);

                //print the sets
                System.out.println("Set 1 is:");
                System.out.println(set1.toString());
                System.out.println("Set 2 is:");
                System.out.println(set2.toString());

                //get the difference
                // CHECKS PRECONDITIONS
                while(set1.getSize() <= 0 || set1.getSize() >= set1.MAX_SIZE) {
                    System.out.println("Too many or too little elements in set 1.");
                    set1 = getSet(in);
                }
                while(set2.getSize() <= 0 || set2.getSize() >= set2.MAX_SIZE) {
                    System.out.println("Too many or too little elements in set 2.");
                    set2 = getSet(in);
                }
                set1.difference(set2);

                //print the difference
                System.out.println("The difference is:");
                System.out.println(set1.toString());
            } else {
                System.out.println("That was not an option");
            }

            //print the menu and get the next option
            printMenu();
            input = Integer.parseInt(in.nextLine());
        }
    }

    /**
     * This method will print the options menu
     *
     * @pre none
     * @post [menu will be displayed to user]
     */
    private static void printMenu() {
        System.out.println("\nMake a selection");
        System.out.println("1. Find the DIFFERENCE of Two Sets");
        System.out.println(EXIT_CHOICE + ". Exit");
    }

    /**
     * This method will get the values from a user and build a set
     *
     * @param in a scanner object to use to get data from the user
     * @return a set that the user built
     * @pre in is open and connected to the user
     * @post getSet = [set containing the user provided values]
     */
    private static ISet getSet(Scanner in) {
        ISet s = new ArraySet();
        int input;
        //replace this so the user can choose between ListSet and ArraySet
        while(true) {
            // 2nd Menu Print
            System.out.println("\nHello user\n1: List Set\n2: Array Set");
            in = new Scanner(System.in);
            input = in.nextInt();

            // Switch statement used to determine which data structure user will use.
            switch(input) {
                case 1:
                    s = new ListSet();
                    break;
                case 2:
                    s = new ArraySet();
                    break;
                default:
                    System.out.println("Invalid entry. Try again.\n");
                    break;
            }
            if(input == 1 || input == 2) break;
        }

        // add values to the set until user enters "qt" to stop entering values
        System.out.println("Enter a value to add to the set. Enter qt to stop adding to the set");
        in = new Scanner(System.in);
        String val = in.nextLine();
        while (!val.equals("qt")) {
            //we can assume if they did not enter "qt", they did enter a character
            char addVal = val.charAt(0);

            //add the value to our set
            // CHECKS PRECONDITIONS
            if(s.getSize() >= s.MAX_SIZE) System.out.println("Max capacity of data.");
            else if(s.contains(addVal)) System.out.println("Value is already in set.");
            else s.add(addVal);

            //get the next value before looping
            System.out.println("Enter a value to add to the set. Enter qt to stop adding to the set");
            in = new Scanner(System.in);
            val = in.nextLine();
        }

        //we have filled our set, so we can return it
        return s;
    }
}