package cpsc2150.extendedConnectX;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/** @invariant
 * 0 <= tokenCount < maxTokens
 * board = new Map<Character, List<BoardPosition>>
 * MIN_DIM <= boardHeight <= MAX_DIM
 * MIN_DIM <= boardWidth <= MAX_DIM
 * MIN_WIN <= win <= MAX_WIN
 *
 * Correspondence: self.tokenCount = tokenCount AND self.board = board AND self.boardHeight = boardHeight
 * AND self.boardWidth = boardWidth AND self.maxTokens = maxTokens AND self.win = win
 */
public class GameBoardMem extends AbsGameBoard implements IGameBoard {
    Map<Character, List<BoardPosition>> board;
    private int boardHeight;
    private int boardWidth;
    private int maxTokens;
    private int win;
    private int tokenCount;

    /**
     * This creates a new object that is initializing a new HashMap that will contain the tokens
     * on the board. It also specifies the width, height and win condition of the board that will
     * be used for placing tokens on the Map
     *
     * @param bh - Represents the height of the board
     * @param bw - Represents the width of the board
     * @param w -  Represents the win condition token length
     *
     * @pre MIN_DIM <= bh <= MAX_DIM AND MIN_DIM <= bw <= MAX_DIM AND MIN_WIN <= w <= MAX_WIN AND  AND [GameBoardMem implements each
     * method (that is not default) from interface IGameBoard]
     * @post tokenCount = 0 AND boardHeight = bh AND boardWidth = bw AND maxTokens = bw*bh AND win = w
     * AND board = new HashMap<Character, List<BoardPosition>>
     */
    public GameBoardMem(int bh, int bw, int w) {
        tokenCount = 0;
        boardHeight = bh;
        boardWidth = bw;
        maxTokens = bh * bw;
        win = w;
        board = new HashMap<>();
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

    // Kept because it is more efficient!
    public boolean isPlayerAtPos(BoardPosition P, Character a) {
        // Loop through map of lists and keys, keeping track of both
        for (Map.Entry<Character, List<BoardPosition>> entry : board.entrySet()) {
            Character b = entry.getKey();
            List<BoardPosition> A = entry.getValue();
            // If character looking for is found as a key, execute loop
            if (b == a) {
                for (int i = 0; i < A.size(); ++i) {
                    BoardPosition B = A.get(i);
                    // If B is equal to the position we are trying to find for specific player
                    if (B.equals(P)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    public Character whatsAtPos(BoardPosition P) {
        // Loop through map of lists and keys, keeping track of both
        for(Map.Entry<Character, List<BoardPosition>> entry : board.entrySet()) {
            Character a = entry.getKey();
            List<BoardPosition> A = entry.getValue();
            // Loop through each list to find board position desired
            for(int i = 0; i < A.size(); ++i) {
                BoardPosition B = A.get(i);
                // If found position equals P then return the character (key) at that position
                if(B.equals(P)) {
                    return a;
                }
            }
        }
        // If position is not found and the area is out of bounds, the space is not free, so return null
        if(P.getRow() > getNumRows()-1 || P.getCol() > getNumColumns()-1 || P.getRow() < 0 || P.getCol() < 0) return null;
        // If position is not found but the area is in bounds, the space is free, so return a ' ' character
        return ' ';
    }

    public void placeToken(Character a, int X) {
        // Initial row value will be the bottom of the board
        int row = getNumRows()-1;
        // Loop through map of lists and keys, keeping track of lists
        for(Map.Entry<Character, List<BoardPosition>> entry : board.entrySet()) {
            List<BoardPosition> P = entry.getValue();
            // Loop through each list and everytime a position in the same column is found, row is decremented
            for(int i = 0; i < P.size(); ++i) {
                BoardPosition B = P.get(i);
                if(B.getCol() == X) {
                    row--;
                }
            }
        }

        // If first token, add the key to the map and add the position to the map, otherwise just add the position
        BoardPosition A = new BoardPosition(row, X);
        if(board.get(a) == null) board.put(a, new ArrayList<>());
        board.get(a).add(A);
        tokenCount++;
    }
}
