package cpsc2150.extendedConnectX;

/** @invariant
 * 0 <= tokenCount < MAX_TOKENS
 * board[0 <= x < BOARD_HEIGHT][0 <= x < BOARD_WIDTH]
 *
 * Correspondence: self.tokenCount = tokenCount AND self.board = board
 */
public class GameBoard extends AbsGameBoard implements IGameBoard {
    private Character[][] board;
    private int tokenCount;

    /**
     * This creates a new object that is the game board initializing the 2D character array
     * and making them all spaces
     *
     * @pre  [GameBoard implements each method (that is not default) from the interface IGameBoard]
     * @post tokenCount = 0 AND board = new Character[BOARD_HEIGHT][BOARD_WIDTH]
     */
    public GameBoard() {
        tokenCount = 0;
        board = new Character[getNumRows()][getNumColumns()];

        for(int i = 0; i < getNumRows(); ++i) {
            for(int j = 0; j < getNumColumns(); ++j) {
                board[i][j] = ' ';
            }
        }
    }

    /**
     * This method is used to check if the game has resulted in a tie
     *
     * @return true if the game is a tie
     *
     * @pre    [the game board has been initialized]
     * @post   checkTie = true if tokenCount = MAX_TOKENS
     */
    // Kept because it is more efficient!
    public boolean checkTie() { return tokenCount == MAX_TOKENS; }

    public Character whatsAtPos(BoardPosition P) { return board[P.getRow()][P.getCol()]; }

    public void placeToken(Character a, int X) {
        int row = 0;

        // This loop searches the board in the selected column keeping track of the space for token placement
        for(int i = getNumRows()-1; i > 0; --i) {
            if(board[i][X] == ' ') {
                row = i;
                break;
            }
        }
        BoardPosition P = new BoardPosition(row, X);

        // Here is where the token is placed on the board
        if(board[P.getRow()][P.getCol()] == ' ') {
            board[P.getRow()][P.getCol()] = a;
            tokenCount++;
        }
    }
}
