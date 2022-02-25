package cpsc2150.extendedConnectX;

/**
 * Holds basic information about the GameBoard, allowing the user to place tokens based on column. Placement location is based on BoardPosition
 *
 * Defines: Board: [][] Character - Actual board of characters that users will play on
 *          OR
 *          Board: Map<Character, List<BoardPosition>> - Key of characters with list of each taken board position in a list
 *          tokenCount: Z - How many tokens are on the board at any given time
 *
 * Initialization Ensures: GameBoard will have initial token count set to 0, and all characters in board set to empty (also allocated if 2D array)
 *
 * Constraints: 0 <= tokenCount <= MAX_TOKENS
 *              MIN_DIM <= boardHeight <= MAX_DIM
 *              MIN_DIM <= boardWidth <= MAX_DIM
 *              MIN_WIN <= win <= MAX_WIN
 */
public interface IGameBoard {
    public static final int MAX_PLAYERS = 10;
    public static final int MIN_PLAYERS = 2;
    public static final int MAX_DIM = 100;
    public static final int MIN_DIM = 3;
    public static final int MAX_WIN = 25;
    public static final int MIN_WIN = 3;

    /**
     * This method returns the number of rows on the board
     *
     * @return the number of rows the board contains
     *
     * @pre [board constructor has been called]
     * @post getNumRows = boardHeight
     */
    int getNumRows();

    /**
     * This method returns the number of columns on the board
     *
     * @return the number of columns the board contains
     *
     * @pre [board constructor has been called]
     * @post getNumColumns = boardWidth
     */
    int getNumColumns();

    /**
     * This method returns the number of token connections needed to win
     *
     * @return the number of necessary token connections to win
     *
     * @pre [board constructor has been called]
     * @post getNumToWin = win
     */
    int getNumToWin();

    /**
     * This method is used to place a game token on the board based on whose turn it is
     *
     * @param a is the character that will be placed on the board
     * @param X is the column that the token will fall in
     *
     * @pre   a = *valid character* AND 0 <= X < boardWidth
     * @post  [Token is placed on board] board[free row][X] = a OR board<a, add(board position)>
     */
    void placeToken(Character a, int X);

    /**
     * This method is used to find the character at board position P
     *
     * @param  P is the board position passed in to check the value of the character there
     *
     * @return the character at the board position in question
     *
     * @pre    [a game board has been initialized and board positions declared]
     * @post   whatsAtPos = board[P.row][P.col] OR whatsAtPos = board<char at P, list P is in>
     */
    Character whatsAtPos(BoardPosition P);

    default boolean checkTie() {
        BoardPosition P;

        // This loop checks the top board position in each column to see if all are filled resulting in tie
        for(int i = 0; i < getNumColumns(); ++i) {
            P = new BoardPosition(0, i);
            if(whatsAtPos(P) == ' ') return false;
        }
        return true;
    }

    /**
     * This method is used to check if a column is free for token placement
     *
     * @param  X is the column that will be checked for placement
     *
     * @return true if a space is open in the column for placement
     *
     * @pre    0 <= X < boardWidth
     * @post   checkIfFree = true if board position P hits a position in the column that is a ' ' character
     */
    default boolean checkIfFree(int X) {
        BoardPosition P;

        // This loop is used to find a free space in a passed in column X
        for(int i = 0; i < getNumRows(); ++i) {
            P = new BoardPosition(i, X);
            if(whatsAtPos(P) == ' ') return true;
        }
        return false;
    }

    /**
     * This method is used to check if the game has resulted in a win condition
     *
     * @param  X is the column of the most recent token placement that will be checked for its board position
     *
     * @return true if one of the 3 win conditions check out
     *
     * @pre    0 <= X < boardWidth
     * @post   checkForWin = true if 5 of the same token are connected in any of the 3 ways
     */
    default boolean checkForWin(int X) {
        int row = 0;
        BoardPosition temp;

        // This loop is used to find the proper row of the most recent token placed
        for(int i = getNumRows()-1; i >= 0; --i) {
            temp = new BoardPosition(i, X);
            if(whatsAtPos(temp) == ' ') {
                row = i+1;
                break;
            }
        }

        // P is the board position of the most recently placed token
        BoardPosition P = new BoardPosition(row, X);
        Character a = whatsAtPos(P);

        // Check all three win conditions based on the most recent placed token
        return checkHorizWin(P, a) || checkDiagWin(P, a) || checkVertWin(P, a);
    }

    /**
     * This method checks for a horizontal win condition given a character and board position
     *
     * @param  P is the board position of the most recent placed token
     * @param  a is the character at the board position of the most recent token
     *
     * @return true if 5 of the same token are connected horizontally (left->right) OR (right->left)
     *
     * @pre    0 <= P.row < boardHeight AND 0 <= P.col < boardWidth AND a = *valid character*
     * @post   checkHorizWin = true if 5 of the same token are connected horizontally
     */
    default boolean checkHorizWin(BoardPosition P, Character a) {
        int count = 0;
        BoardPosition Pf = P;
        BoardPosition Pb = P;
        if(a == ' ') return false;

        // Find board positions with same character to the left
        for(int i = 0; i < getNumToWin(); ++i) {
            if(!isPlayerAtPos(Pf, a)) break;
            count++;
            if(Pf.getCol()-1 >= 0) Pf = new BoardPosition(Pf.getRow(), Pf.getCol()-1);
            else break;
        }

        if(count >= getNumToWin()) return true;
        // Count is decremented here to account for the original board position
        count--;

        // Find board positions with same character to the right
        for(int i = 0; i < getNumToWin(); ++i) {
            if(!isPlayerAtPos(Pb, a)) break;
            count++;
            if(Pb.getCol()+1 <= getNumColumns()-1) Pb = new BoardPosition(Pb.getRow(), Pb.getCol()+1);
            else break;
        }

        return count >= getNumToWin();
    }

    /**
     * This method checks for a vertical win condition given a character and board position
     *
     * @param  P is the board position of the most recent placed token
     * @param  a is the character at the board position of the most recent token
     *
     * @return true if 5 of the same token are connected vertically (down->up)
     *
     * @pre    0 <= P.row < boardHeight AND 0 <= P.col < boardWidth AND a = *valid character*
     * @post   checkVertWin = true if 5 of the same token are connected vertically
     */
    default boolean checkVertWin(BoardPosition P, Character a) {
        int count = 0;
        BoardPosition Pu = P;
        if(a == ' ') return false;

        // Vertical win can only occur with the top placed token, which needs only one loop
        // for success. Using a similar algorithm as before (using BOARD_HEIGHT instead)
        for(int i = 0; i < getNumToWin(); ++i) {
            if(!isPlayerAtPos(Pu, a)) break;
            count++;
            if(Pu.getRow()+1 <= getNumRows()-1) Pu = new BoardPosition(Pu.getRow()+1, Pu.getCol());
            else break;
        }

        return count >= getNumToWin();
    }

    /**
     * This method checks for a diagonal win condition given a character and board position
     *
     * @param  P is the board position of the most recent placed token
     * @param  a is the character at the board position of the most recent token
     *
     * @return true if 5 of the same token are connected diagonally (DL->UR) OR (UR->DL) OR (UL->DR) OR (DR->UL)
     *
     * @pre    0 <= P.row < boardHeight AND 0 <= P.col < boardWidth AND a = *valid character*
     * @post   checkDiagWin = true if 5 of the same token are connected diagonally
     */
    default boolean checkDiagWin(BoardPosition P, Character a) {
        int count = 0;

        // Board positions named for each movement
        BoardPosition Pur = P;
        BoardPosition Pdr = P;
        BoardPosition Pul = P;
        BoardPosition Pdl = P;
        if(a == ' ') return false;

        // Find board positions with same character to the up-left
        for(int i = 0; i < getNumToWin(); ++i) {
            if(!isPlayerAtPos(Pul, a)) break;
            count++;
            if(Pul.getCol()-1 >= 0 && Pul.getRow()+1 <= getNumRows()-1) Pul = new BoardPosition(Pul.getRow()+1, Pul.getCol()-1);
            else break;
        }

        if(count >= getNumToWin()) return true;
        count--;

        // Find board positions with same character to the down-right
        for(int i = 0; i < getNumToWin(); ++i) {
            if(!isPlayerAtPos(Pdr, a)) break;
            count++;
            if(Pdr.getCol()+1 <= getNumColumns()-1 && Pdr.getRow()-1 >= 0) Pdr = new BoardPosition(Pdr.getRow()-1, Pdr.getCol()+1);
            else break;
        }

        if(count >= getNumToWin()) return true;
        // Count = 0 here because now the test will calculate for possible other type of diagonal
        count = 0;

        // Find board positions with same character to the up-right
        for(int i = 0; i < getNumToWin(); ++i) {
            if(!isPlayerAtPos(Pur, a)) break;
            count++;
            if(Pur.getCol()+1 <= getNumColumns()-1 && Pur.getRow()+1 <= getNumRows()-1) Pur = new BoardPosition(Pur.getRow()+1, Pur.getCol()+1);
            else break;
        }

        if(count >= getNumToWin()) return true;
        count--;

        // Find board positions with same character to the down-left
        for(int i = 0; i < getNumToWin(); ++i) {
            if(!isPlayerAtPos(Pdl, a)) break;
            count++;
            if(Pdl.getCol()-1 >= 0 && Pdl.getRow()-1 >= 0) Pdl = new BoardPosition(Pdl.getRow()-1, Pdl.getCol()-1);
            else break;
        }

        // Count can be greater than 5 since it is still 5 connected if 6,7,8... are connected
        return count >= getNumToWin();
    }

    /**
     * This method checks a specific board position to see if a particular character is there
     *
     * @param  P is the board position that will be checked for its character
     * @param  a is the character that will be tested to see if it is at P
     *
     * @return true if a is at board position P
     *
     * @pre    0 <= P.row < boardHeight AND 0 <= P.col < boardWidth AND a = *valid character*
     * @post   isPlayerAtPos = true if the character at P is equal to a
     */
    default boolean isPlayerAtPos(BoardPosition P, Character a) {
        Character A = whatsAtPos(P);
        return A == a;
    }
}
