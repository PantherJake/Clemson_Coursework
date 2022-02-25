package cpsc2150.extendedConnectX;
import java.util.Scanner;

/** @author Jacob Vickio, 03/23/2021, 3:14 PM */

/** @invariant
 * M = Character[BOARD_HEIGHT][BOARD_WIDTH]
 * OR
 * M = Map<Character, List<BoardPosition>>
 * playAgain = 'Y' OR playAgain = 'y' OR playAgain = 'N' OR playAgain = 'n'
 * 0 <= turnCount <= numPlayers
 * 0 <= chosenCol < BOARD_WIDTH
 * MIN_DIM <= numCols <= MAX_DIM
 * MIN_DIM <= numRows <= MAX_DIM
 * fastOrMem = 'F' OR fastOrMem = 'f' OR fastOrMem = 'M' OR fastOrMem = 'm'
 * MIN_WIN <= numWin <= MAX_WIN
 * 2 <= numPlayers <= 10
 */
public class GameScreen {
    public static void main(String[] args) {
        IGameBoard M = new GameBoard();
        char fastOrMem;
        int numRows;
        int numWin;
        int numPlayers;
        int numCols;
        int turnCount = 0;
        char playAgain;
        int chosenCol;
        Scanner scanner;

        while (true) {
            // How many players user input
            System.out.println("How many players?");
            scanner = new Scanner(System.in);
            numPlayers = scanner.nextInt();
            while (numPlayers > GameBoard.MAX_PLAYERS || numPlayers < GameBoard.MIN_PLAYERS) {
                if (numPlayers > GameBoard.MAX_PLAYERS) System.out.println("Must be 10 players or fewer");
                else System.out.println("Must be at least 2 players");

                System.out.println("How many players?");
                scanner = new Scanner(System.in);
                numPlayers = scanner.nextInt();
            }

            // Array created to hold all of the characters players decide to play as
            Character players[] = new Character[numPlayers];
            Character temp;

            // Loop that fills array with the chosen characters
            for (int i = 0; i < numPlayers; ++i) {
                System.out.println("Enter the character to represent player " + (i + 1));
                scanner = new Scanner(System.in);
                temp = scanner.next().charAt(0);
                temp = Character.toUpperCase(temp);
                for (int j = 0; j < i; ++j) {
                    while (players[j] == temp || players[j] == Character.toUpperCase(temp) ||
                    players[j] == Character.toLowerCase(temp)) {
                        System.out.println(temp + " is already taken as a player token!");
                        System.out.println("Enter the character to represent player " + (i + 1));
                        scanner = new Scanner(System.in);
                        temp = scanner.next().charAt(0);
                    }
                }
                players[i] = Character.toUpperCase(temp);
            }

            // How many columns user input
            System.out.println("How many columns should be on the board?");
            scanner = new Scanner(System.in);
            numCols = scanner.nextInt();
            while (numCols > GameBoard.MAX_DIM || numCols < GameBoard.MIN_DIM) {
                if (numCols > GameBoard.MAX_DIM)
                    System.out.println("Must be " + GameBoard.MAX_DIM + " columns or fewer");
                else System.out.println("Must be at least " + GameBoard.MIN_DIM + " columns");
                System.out.println("How many rows should be on the board?");
                scanner = new Scanner(System.in);
                numCols = scanner.nextInt();
            }

            // How many rows user input
            System.out.println("How many rows should be on the board?");
            scanner = new Scanner(System.in);
            numRows = scanner.nextInt();
            while (numRows > GameBoard.MAX_DIM || numRows < GameBoard.MIN_DIM) {
                if (numRows > GameBoard.MAX_DIM) System.out.println("Must be " + GameBoard.MAX_DIM + " rows or fewer");
                else System.out.println("Must be at least " + GameBoard.MIN_DIM + " rows");
                System.out.println("How many rows should be on the board?");
                scanner = new Scanner(System.in);
                numRows = scanner.nextInt();
            }

            // How many to win user input
            System.out.println("How many in a row to win?");
            scanner = new Scanner(System.in);
            numWin = scanner.nextInt();
            while (numWin > GameBoard.MAX_WIN || numWin < GameBoard.MIN_WIN || numWin > numCols || numWin > numRows) {
                if (numWin > GameBoard.MAX_WIN) System.out.println("Win amount must be less than " + GameBoard.MAX_WIN);
                else if(numWin < GameBoard.MIN_WIN) System.out.println("Win amount must be more than " + GameBoard.MIN_WIN);
                else if(numWin > numCols) System.out.println("Win amount cannot be greater than " + numCols);
                else System.out.println("Win amount cannot be greater than" + numRows);
                System.out.println("How many in a row to win?");
                scanner = new Scanner(System.in);
                numWin = scanner.nextInt();
            }

            // Which implementation user input
            System.out.println("Would you like a Fast Game (F/f) or a Memory Efficient Game (M/m)?");
            scanner = new Scanner(System.in);
            fastOrMem = scanner.next().charAt(0);
            if (fastOrMem == 'f' || fastOrMem == 'F') M = new GameBoard(numRows, numCols, numWin);
            else if (fastOrMem == 'm' || fastOrMem == 'M') M = new GameBoardMem(numRows, numCols, numWin);

            while (fastOrMem != 'f' && fastOrMem != 'F' && fastOrMem != 'm' && fastOrMem != 'M') {
                System.out.println("Please enter F or M");
                System.out.println("Would you like a Fast Game (F/f) or a Memory Efficient Game (M/m)?");
                scanner = new Scanner(System.in);
                fastOrMem = scanner.next().charAt(0);
                if (fastOrMem == 'f' || fastOrMem == 'F') M = new GameBoard(numRows, numCols, numWin);
                else if (fastOrMem == 'm' || fastOrMem == 'M') M = new GameBoardMem(numRows, numCols, numWin);
            }

            // This loop signifies the actual game beginning
               while(true) {
                   // Prints the current state of GameBoard at every turn
                    System.out.println(M.toString());
                    System.out.println("Player " + players[turnCount] + ", what column do you want to place your marker in?");
                    scanner = new Scanner(System.in);
                    chosenCol = scanner.nextInt();

                    // Checking input to make sure turn is within BOARD_WIDTH
                    if (chosenCol < 0) {
                        System.out.println("Column cannot be less than 0");
                        continue;
                    } else if (chosenCol > M.getNumColumns()-1) {
                        System.out.println("Column cannot be greater than " + M.getNumColumns());
                        continue;
                    }

                    // Makes sure the chosen column has a ' ' left for the user to place a token and then places it
                    if (M.checkIfFree(chosenCol)) {
                        M.placeToken(players[turnCount], chosenCol);
                    } else {
                        System.out.println("Column is full");
                        continue;
                    }

                    // The column is passed to check to see if the newest token has resulted in a win condition
                    if (M.checkForWin(chosenCol)) {
                        System.out.println(M.toString());
                        System.out.println("Player " + players[turnCount] + " won!");

                        // Asks the user if they want to play again
                        while (true) {
                            System.out.println("Would you like to play again? Y/N");
                            scanner = new Scanner(System.in);
                            playAgain = scanner.next().charAt(0);
                            if (playAgain == 'Y' || playAgain == 'y') {
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
                                break;
                            } else if (playAgain == 'N' || playAgain == 'n') return;
                        }
                    }

                    // turnCount is incremented signifying the next players turn
                    turnCount++;
                    // if a win condition is met, reset turnCounter and return to loop
                    if(M.checkTie() || M.checkForWin(chosenCol)) {
                        turnCount = 0;
                        break;
                    }
                    else if(turnCount == numPlayers) turnCount = 0;
            }
        }
    }
}
