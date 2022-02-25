package cpsc2150.myConnect;

import java.util.Scanner;
/** @author Jake Vickio */

/** @invariant
 * 0 <= input < BOARD_WIDTH
 */
public class GameScreen {
    int input;
    char playerX = 'X';
    char playerO = 'O';
    BoardPosition o;

    // Simply sets the value of the input based on which column a player wants to place a token in
    void collectInput() { }
    /** @post
     * 0 <= input < BOARD_WIDTH
     */

    // Sets board position based on where the token is being placed. This function will require functions from GameBoard
    void setBoardPosition() { }
    /**
     * @pre
     * 0 <= o.row < BOARD_HEIGHT && col < BOARD_WIDTH
     * @post
     * 0 <= o.row < BOARD_HEIGHT
     * 0 <= o.col < BOARD_WIDTH
     */

    public static void main(String[] args) { }
}
