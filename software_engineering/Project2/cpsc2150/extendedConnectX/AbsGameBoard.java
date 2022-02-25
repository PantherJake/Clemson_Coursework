package cpsc2150.extendedConnectX;

public abstract class AbsGameBoard implements IGameBoard {

    /**
     * This method overrides {@link Object#toString()} to provide
     * a string representation of the current game board
     *
     * @return a string representation of the game board separated by '|' characters for organization
     *
     * @post   toString = [a string representation of the Connect 5 board
     */
    public String toString() {
        String r = "";
        for(int i = 0; i < BOARD_WIDTH; ++i) {
            r += "|";
            r += i;
        }
        r += "|";
        r += "\n";
        for(int i = 0; i < BOARD_HEIGHT; ++i) {
            r += "|";
            for(int j = 0; j < BOARD_WIDTH; ++j) {
                BoardPosition P = new BoardPosition(i, j);
                r += whatsAtPos(P);
                r += "|";
            }
            r += "\n";
        }
        return r;
    }
}

