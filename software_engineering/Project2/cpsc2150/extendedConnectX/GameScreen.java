package cpsc2150.extendedConnectX;
import java.util.Scanner;

/** @author Jacob Vickio, 02/27/2021, 5:11 PM */

/** @invariant
 * M = Character[BOARD_HEIGHT][BOARD_WIDTH]
 * playAgain = 'Y' OR playAgain = 'y' OR playAgain = 'N' OR playAgain = 'n'
 * 0 <= turn <= MAX_TOKENS
 * 0 <= chosenCol < BOARD_WIDTH
 */
public class GameScreen {
    public static void main(String[] args) {
        GameBoard M = new GameBoard();
        char playAgain;
        int turn = 0;
        int chosenCol;
        Scanner scanner;

        while (true) {
            // Prints the current board to the screen based on previous turn
            System.out.println(M.toString());

            if (turn % 2 == 0) {
                // Player X's turn
                System.out.println("Player X, what column do you want to place your marker in?");
                scanner = new Scanner(System.in);
                chosenCol = scanner.nextInt();

                // Checking input to make sure turn is within BOARD_WIDTH
                if (chosenCol < 0) {
                    System.out.println("Column cannot be less than 0");
                    continue;
                } else if (chosenCol > 8) {
                    System.out.println("Column cannot be greater than 8");
                    continue;
                }

                // Makes sure the chosen column has a ' ' left for the user to place a token and then places it
                if (M.checkIfFree(chosenCol)) {
                    M.placeToken('X', chosenCol);
                    turn++;
                } else {
                    System.out.println("Column is full");
                }
            } else {
                // Player O's turn
                System.out.println("Player O, what column do you want to place your marker in?");
                scanner = new Scanner(System.in);
                chosenCol = scanner.nextInt();

                // Checking input to make sure turn is within BOARD_WIDTH
                if (chosenCol < 0) {
                    System.out.println("Column cannot be less than 0");
                    continue;
                } else if (chosenCol > 8) {
                    System.out.println("Column cannot be greater than 8");
                    continue;
                }

                // Makes sure the chosen column has a ' ' left for the user to place a token and then places it
                if (M.checkIfFree(chosenCol)) {
                    M.placeToken('O', chosenCol);
                    turn++;
                } else {
                    System.out.println("Column is full");
                }
            }

            // The column is passed to check to see if the newest token has resulted in a win condition
            if (M.checkForWin(chosenCol)) {
                System.out.println(M.toString());
                if ((turn - 1) % 2 == 0) {
                    System.out.println("Player X Won!");
                } else {
                    System.out.println("Player O Won!");
                }

                // Asks the user if they want to play again
                while (true) {
                    System.out.println("Would you like to play again? Y/N");
                    scanner = new Scanner(System.in);
                    playAgain = scanner.next().charAt(0);
                    if (playAgain == 'Y' || playAgain == 'y') {
                        M = new GameBoard();
                        turn = 0;
                        break;
                    } else if (playAgain == 'N' || playAgain == 'n') return;
                }
            }

            // A tie condition will be checked to see if tokens have filled the board
            if (M.checkTie()) {
                System.out.println(M.toString());
                System.out.println("Game is a tie");

                // Asks user if they want to play again
                while (true) {
                    System.out.println("Would you like to play again? Y/N");
                    scanner = new Scanner(System.in);
                    playAgain = scanner.next().charAt(0);
                    if (playAgain == 'Y' || playAgain == 'y') {
                        M = new GameBoard();
                        turn = 0;
                        break;
                    } else if (playAgain == 'N' || playAgain == 'n') return;
                }
            }
        }
    }
}