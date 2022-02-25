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
        for(int i = 0; i < getNumColumns(); ++i) {
            if(i < 10) r += "| ";
            else r += "|";
            r += i;
        }
        r += "|";
        r += "\n";
        for(int i = 0; i < getNumRows(); ++i) {
            r += "|";
            for(int j = 0; j < getNumColumns(); ++j) {
                BoardPosition P = new BoardPosition(i, j);
                if(whatsAtPos(P) == null) r += " ";
                else r += whatsAtPos(P);
                r += " |";
            }
            r += "\n";
        }
        return r;
    }
}

