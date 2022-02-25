package cpsc2150.MyDeque;

import java.util.Scanner;

public class IntegerDequeApp {
    public static void main(String[] args) {
        IDeque<Integer> q;
    /*
    You will add in code here to ask the user whether they want an
    array implementation or a list implementation. Then use their
    answer to initialize q appropriately
    */
        Scanner scanner = new Scanner(System.in);
        System.out.println("What implementation would you like to use: Array(Type 1) or List(Type 2)?");
        int option = Integer.parseInt(scanner.nextLine());

        if (option == 1) {
            q = new ArrayDeque();
        } else if (option == 2) {
            q = new ListDeque();
        } else {
            System.out.println("Error: Input failure. Please input 1 for array or 2 for list.");
            return;
        }

        int choice;

        while (true) {
            System.out.println("Select an option:");
            System.out.print("1. Add to the end of the Deque\n2. Add to the front of the Deque\n3. Remove from the front of the Deque" +
                    "\n4. Remove from the end of the Deque\n5. Peek from the front of the Deque\n6. Peek from the end of the Deque" +
                    "\n7. Insert to a position in the Deque\n8. Remove from a position in the Deque\n9. Get a position in the Deque" +
                    "\n10. Get the length of the Deque\n11. Clear the deque\n12. Quit\n");
            scanner = new Scanner(System.in);
            choice = scanner.nextInt();

            Scanner o = new Scanner(System.in);
            switch (choice) {
                case 1:
                    System.out.println("What integer to enqueue to the end of the Deque?");
                    Integer X = o.nextInt();
                    q.enqueue(X);
                    break;
                case 2:
                    System.out.println("What integer to inject to the front of the Deque?");
                    Integer A = o.nextInt();
                    q.inject(A);
                    break;
                case 3:
                    if (q.length() == 0) {
                        System.out.println("Deque is empty!");
                        break;
                    }

                    System.out.println("Integer at the front: " + q.dequeue());
                    break;
                case 4:
                    if (q.length() == 0) {
                        System.out.println("Deque is empty!");
                        break;
                    }

                    System.out.println("Integer at the end: " + q.removeLast());
                    break;
                case 5:
                    System.out.println("Peek: " + q.peek());
                    break;
                case 6:
                    System.out.println("Peek: " + q.endOfDeque());
                    break;
                case 7:
                    System.out.println("What integer to insert to the Deque?");
                    Integer B = o.nextInt();
                    System.out.println("What position to insert in?");
                    scanner = new Scanner(System.in);
                    int pos = Integer.parseInt(scanner.nextLine());

                    while (q.length() < pos || 0 > pos) {
                        System.out.println("Not a valid position in the Deque!");
                        System.out.println("What position to insert in?");
                        scanner = new Scanner(System.in);
                        pos = Integer.parseInt(scanner.nextLine());
                    }
                    q.insert(B, pos);
                    break;
                case 8:
                    if (q.length() == 0) {
                        System.out.println("Deque is empty!");
                        break;
                    }

                    System.out.println("What position to remove from the Deque?");
                    scanner = new Scanner(System.in);
                    int poss = Integer.parseInt(scanner.nextLine());

                    while (q.length() < poss) {
                        System.out.println("Not a valid position in the Deque!");
                        System.out.println("What position to remove from the Deque?");
                        scanner = new Scanner(System.in);
                        poss = Integer.parseInt(scanner.nextLine());
                    }
                    Integer temp = q.remove(poss);
                    System.out.println(temp + " was at position " + poss + " in the Deque.");
                    break;
                case 9:
                    if (q.length() == 0) {
                        System.out.println("Deque is empty!");
                        break;
                    }

                    System.out.println("What position to get from the Deque?");
                    scanner = new Scanner(System.in);
                    int possy = Integer.parseInt(scanner.nextLine());

                    while (q.length() < possy) {
                        System.out.println("Not a valid position in the Deque!");
                        System.out.println("What position to get from the Deque?");
                        scanner = new Scanner(System.in);
                        possy = Integer.parseInt(scanner.nextLine());
                    }

                    System.out.println(q.get(possy) + " is at position " + possy + " in the Deque.");
                    break;
                case 10:
                    int length;
                    length = q.length();
                    System.out.println("Length of Deque: " + length);
                    break;
                case 11:
                    q.clear();
                    System.out.println("Deque is now empty!");
                    break;
                case 12:
                    return;
                default:
                    System.out.println("Not a valid option!");
                    break;
            }

            System.out.println("Deque is:");
            String f = q.toString();
            System.out.println(f);
        }
    }
}