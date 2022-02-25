package cpsc2150.myDeque;

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

        Character x = 'a';
        q.enqueue(x);
        x = 'k';
        q.enqueue(x);
        x = 'j';
        q.enqueue(x);
        x = '1';
        q.enqueue(x);
        x = 'f';
        q.enqueue(x);

/*
Add the code to print the deque. After the code is finished,
the deque should still contain all its values in order
*/

        System.out.println("Deque:");
        while(q.length() != 0) {
            System.out.print(q.dequeue());
            System.out.print("\n");
        }
    }
}
