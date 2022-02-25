package cpsc2150.MyDeque;

/*
Jacob Vickio
Jimmy Martinez
*/

import java.util.Scanner;

public class DequeApp {
    public static void main(String[] args) {
        IDeque q;
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

        int pos;
        Character X;
        int choice;

        while (true) {
            System.out.println("Select an option:");
            System.out.print("1. Add to the end of the Deque\n2. Add to the front of the Deque\n3. Remove from the front of the Deque" +
                    "\n4. Remove from the end of the Deque\n5. Peek from the front of the Deque\n6. Peek from the end of the Deque" +
                    "\n7. Insert to a position in the Deque\n8. Remove from a position in the Deque\n9. Get a position in the Deque" +
                    "\n10. Get the length of the Deque\n11. Clear the deque\n12. Quit\n");
            scanner = new Scanner(System.in);
            choice = Integer.parseInt(scanner.nextLine());

            Scanner o = new Scanner(System.in);
            switch (choice) {
                case 1:
                    System.out.println("What character to enqueue to the end of the Deque?");
                    X = o.next().charAt(0);
                    q.enqueue(X);
                    break;
                case 2:
                    System.out.println("What character to inject to the front of the Deque?");
                    X = o.next().charAt(0);
                    q.inject(X);
                    break;
                case 3:
                    X = q.dequeue();
                    System.out.println("Character at the front: " + X);
                    break;
                case 4:
                    X = q.removeLast();
                    System.out.println("Character at the end: " + X);
                    break;
                case 5:
                    X = q.peek();
                    System.out.println("Peek: " + X);
                    break;
                case 6:
                    X = q.endOfDeque();
                    System.out.println("Peek: " + X);
                    break;
                case 7:
                    System.out.println("What character to insert to the Deque?");
                    X = o.next().charAt(0);
                    System.out.println("What position to insert in?");
                    scanner = new Scanner(System.in);
                    pos = Integer.parseInt(scanner.nextLine());

                    while (q.length() < pos) {
                        System.out.println("Not a valid position in the Deque!");
                        System.out.println("What position to insert in?");
                        scanner = new Scanner(System.in);
                        pos = Integer.parseInt(scanner.nextLine());
                    }
                    q.insert(X, pos);
                    break;
                case 8:
                    System.out.println("What position to remove from the Deque?");
                    pos = Integer.parseInt(scanner.nextLine());

                    while (q.length() < pos) {
                        System.out.println("Not a valid position in the Deque!");
                        System.out.println("What position to remove from the Deque?");
                        scanner = new Scanner(System.in);
                        pos = Integer.parseInt(scanner.nextLine());
                    }
                    q.remove(pos);
                    break;
                case 9:
                    System.out.println("What position to get from the Deque?");
                    pos = Integer.parseInt(scanner.nextLine());

                    while (q.length() < pos) {
                        System.out.println("Not a valid position in the Deque!");
                        System.out.println("What position to get from the Deque?");
                        scanner = new Scanner(System.in);
                        pos = Integer.parseInt(scanner.nextLine());
                    }
                    X = q.get(pos);
                    System.out.println(X + " is at position " + pos + " in the Deque.");
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
