package cpsc2150.extendedConnectX;

/** @invariant
 * 0 <= row < BOARD_HEIGHT
 * 0 <= col < BOARD_WIDTH
 *
 * Correspondence: self.row = row AND self.col = col
 */
public class BoardPosition {
    private int row;
    private int col;

    /**
     * This creates a new object to keep track of specific positions on the board.
     *
     * @param r is the passed in row value
     * @param c is the passed in column value
     *
     * @pre   0 <= r < BOARD_HEIGHT AND 0 <= c < BOARD_WIDTH
     * @post  row = r AND col = c
     */
    public BoardPosition(int r, int c) {
        row = r;
        col = c;
    }

    /**
     * This method returns the row in a specific board position
     *
     * @return the row of the board position in condition
     *
     * @pre    [the players have begun the game and there are board positions]
     * @post   getRow = row
     */
    public int getRow() { return row; }

    /**
     * This method returns the column in a specific board position
     *
     * @return the column of the board position in condition
     *
     * @pre    [the players have begun the game and there are board positions]
     * @post   getCol = col
     */
    public int getCol() { return col; }

    /**
     * This method allows for two board positions to be compared for equality
     *
     * @param  P is one of the board positions to be compared
     * @param  A is one of the board positions to be compared
     *
     * @return true if the row and column of board positions are equal
     *
     * @pre    [the players have begun the game and there are board positions]
     * @post   [equal if board positions have same values of row and col]
     */
    public boolean equals(BoardPosition P, BoardPosition A) {
        return P.getRow() == A.getRow() && P.getCol() == A.getCol();
    }

    /**
     * This method overrides {@link Object#toString()} to provide a string
     * representation of specific board positions.
     *
     * @return a string representation of a board position using the row and col
     *
     * @post   toString = <row>,<col> for a board position
     */
    public String toString() {
        return "<" + getRow() + ">,<" + getCol() + ">";
    }
}
