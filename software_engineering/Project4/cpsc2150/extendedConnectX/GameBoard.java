package cpsc2150.extendedConnectX;

/** @invariant
 * 0 <= tokenCount < maxTokens
 * board = new Character[boardHeight][boardWidth]
 * MIN_DIM <= boardHeight <= MAX_DIM
 * MIN_DIM <= boardWidth <= MAX_DIM
 * MIN_WIN <= win <= MAX_WIN
 *
 * Correspondence: self.tokenCount = tokenCount AND self.board = board AND self.boardHeight = boardHeight
 * AND self.boardWidth = boardWidth AND self.maxTokens = maxTokens AND self.win = win
 */
public class GameBoard extends AbsGameBoard implements IGameBoard {
    private Character[][] board;
    private int boardHeight;
    private int boardWidth;
    private int maxTokens;
    private int win;
    private int tokenCount;

    /**
     * This creates a new object that is the game board initializing the 2D character array
     * and making them all spaces
     *
     * @pre  [GameBoard implements each method (that is not default) from the interface IGameBoard]
     * @post tokenCount = 0 AND board = new Character[boardHeight][boardWidth]
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
     * This creates a new object that is the game board initializing the 2D character
     * array to the specific width and height of user input. User can also input
     * necessary win parameter tokens
     *
     * @param bh - Represents the height of the board
     * @param bw - Represents the width of the board
     * @param w -  Represents the win condition token length
     *
     * @pre MIN_DIM <= bh <= MAX_DIM AND MIN_DIM <= bw <= MAX_DIM AND MIN_WIN <= w <= MAX_WIN AND [GameBoard implements each
     * method (that is not default) from interface IGameBoard]
     * @post tokenCount = 0 AND boardHeight = bh AND boardWidth = bw AND maxTokens = bh*bw AND win = w AND
     * board = new Character[boardHeight][boardWidth]
     */
    public GameBoard(int bh, int bw, int w) {
        tokenCount = 0;
        boardHeight = bh;
        boardWidth = bw;
        maxTokens = bh * bw;
        win = w;
        board = new Character[getNumRows()][getNumColumns()];

        for(int i = 0; i < getNumRows(); ++i) {
            for(int j = 0; j < getNumColumns(); ++j) {
                board[i][j] = ' ';
            }
        }
    }

    public int getNumRows() { return boardHeight; }
    public int getNumColumns() { return boardWidth; }
    public int getNumToWin() { return win; }

    /**
     * This method is used to check if the game has resulted in a tie
     *
     * @return true if the game is a tie
     *
     * @pre    [the game board has been initialized]
     * @post   checkTie = true if tokenCount = maxTokens
     */
    // Kept because it is more efficient!
    public boolean checkTie() { return tokenCount == maxTokens; }

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
