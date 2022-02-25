package cpsc2150.myConnect;

/** @invariant
 * BOARD_HEIGHT = 6
 * BOARD_WIDTH = 9
 * tokenCounter initialized to 0
 */
public class GameBoard {
    public static final int BOARD_HEIGHT = 6;
    public static final int BOARD_WIDTH = 9;
    int tokenCounter = 0;

    // Checks if the column player wants to place token in has any room left
    public boolean checkIfFree(int c) { }
    /**
     * @pre
     * 0 <= c < BOARD_WIDTH (x is chosen column for token)
     * @post
     * return true if tokens in column is less than BOARD_HEIGHT
     * return false if tokens in columns is equal to BOARD_HEIGHT
     */

    // Checks to see if user has 5 tokens in a row for a win condition
    public boolean checkForWin(int c) { }
    /**
     * @pre
     * 0 <= c < BOARD_WIDTH (x is column where token will be checked for win)
     * @post
     * return true if token completes a 5 token run horizontally, diagonally or vertically
     * return false if token did not create a win scenario
     */

    // Checks the condition necessary to end the game in a tie
    public boolean checkTie() { }
    /**
     * @pre
     * tokenCounter = 54
     * @post
     * return true if placeToken can no longer result in win.
     * return false if a tie is not inevitable.
     */

    // Places a token on the game board inside of the Board array
    public void placeToken(char p, int c) { }
    /**
     * @pre
     * 0 <= c < BOARD_WIDTH
     * p = 'X' or p = 'O'
     * tokenCounter != 54
     * @post
     * p is placed in the lowest available column in c
     */

    // Checks to see if the user has a win condition that is horizontal (5 in a row)
    public boolean checkHorizWin(BoardPosition pos, char p) { }
    /**
     * @pre
     * p = 'X' or p = 'O' (this is used to see which player wins horizontally if returns true)
     * 0 <= pos.row < BOARD_HEIGHT && 0 <= pos.col < BOARD_WIDTH
     * @post
     * returns true if 5 of the same token are placed horizontally next to each other.
     * returns false if 5 horizontally in a row condition is not met.
     */

    // Checks to see if the user has a win condition that is vertical (5 in a row)
    public boolean checkVertWin(BoardPosition pos, char p) { }
    /**
     * @pre
     * p = 'X' or p = 'O' (this is used to see which player wins vertically if returns true)
     * 0 <= pos.row < BOARD_HEIGHT && 0 <= pos.col < BOARD_WIDTH
     * @post
     * returns true if 5 of the same token are placed vertically above or below each other.
     * returns false if 5 vertically in a row condition is not met.
     */

    // Checks to see if the user has a win condition that is diagonal (5 in a row)
    public boolean checkDiagWin(BoardPosition pos, char p) { }
    /**
     * @pre
     * p = 'X' or p = 'O' (this is used to see which player wins diagonally if returns true)
     * 0 <= pos.row < BOARD_HEIGHT && 0 <= pos.col < BOARD_WIDTH
     * @post
     * returns true if 5 of the same token are placed diagonally of each other.
     * returns false if 5 diagonally in a row condition is not met.
     */

    // Returns the character that is at the position based on pos
    public char whatsAtPos(BoardPosition pos) { }
    /**
     * @pre
     * 0 <= pos.row < BOARD_HEIGHT
     * 0 <= pos.col < BOARD_WIDTH
     * (pos is valid on the board)
     * @post
     * returns token that is at the position indicated by pos
     * return will either be 'X' or 'O' or ' ' (If token has not been placed there yet)
     */

    // Returns a true or false based on whether or not p is at pos
    public boolean isPlayerAtPos(BoardPosition pos, char p) { }
    /**
     * @pre
     * 0 <= pos.row < BOARD_HEIGHT && 0 <= pos.col < BOARD_WIDTH
     * p = 'X' || p = 'O'
     * @post
     * returns true if p = token that is currently at pos on the board
     * returns false if p /= token or there is not a token at pos
     */

    // Returns a string that is the game board to be printed out
    public String toString() { }
    /** @post
     * returns a string variable representing the game board at the state that it is called.
     */
}
