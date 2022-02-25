package cpsc2150.myConnect;

/** @invariant
 * 0 <= row < BOARD_HEIGHT
 * 0 <= col < BOARD_WIDTH
 */
public class BoardPosition {
    int row;
    int col;

    // Getter function used to access the row
    public int getRow() { return row; }
    /** @post
     * private int row is returned
     */

    // Getter function used to access the column
    public int getCol() { return col; }
    /** @post
     * private int col is returned
     */

    // Used to see if two board positions are equal to one another
    public boolean equals(BoardPosition pos) { }
    /**
     * @pre
     * 0 <= pos.row < BOARD_HEIGHT
     * @post
     * returns true if pos is equal to chosen board position
     * returns false if pos is not equal to chosen board position
     */

    // Returns a formatted string that represents a specific board position
    public String toString() { }
    /** @post
     * returns a string of a specific board position in the format "<row>,<column>"
     */
}
