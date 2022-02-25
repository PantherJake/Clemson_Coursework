package cpsc2150.extendedConnectX;
import static org.junit.Assert.*;
import org.junit.Test;

public class TestGameBoardMem {
    private IGameBoard MakeABoard(int bh, int bw, int w) { return new GameBoardMem(bh, bw, w); }

    private String CharToString(Character board[][]) {
        String r = "";
        for(int i = 0; i < board[0].length; ++i) {
            if (i < 10) r += "| ";
            else r += "|";
            r += i;
        }
        r += "|";
        r += "\n";
        for(int i = 0; i < board.length; ++i) {
            r += "|";
            for (int j = 0; j < board[0].length; ++j) {
                if (board[i][j] == null) r += " ";
                else r += board[i][j];
                r += " |";
            }
            r += "\n";
        }
        return r;
    }

    // Constructor
    @Test
    public void test_constructor_normal695() {
        Character[][] expected = new Character[6][9];
        IGameBoard M = MakeABoard(6, 9, 5);

        assertEquals(M.toString(), CharToString(expected));
    }

    @Test
    public void test_constructor_resize() {
        Character[][] expected = new Character[3][3];

        // Creates a IGameBoard but then resizes it checking the accuracy of resizing the board
        IGameBoard M = MakeABoard(6, 9, 5);
        M = MakeABoard(3, 3, 3);

        assertEquals(M.toString(), CharToString(expected));
    }

    @Test
    public void test_constructor_max10010025() {
        Character[][] expected = new Character[100][100];
        IGameBoard M = MakeABoard(100, 100, 25);

        assertEquals(M.toString(), CharToString(expected));
    }

    // Check If Free
    @Test
    public void test_checkIfFree_empty() {
        IGameBoard M = MakeABoard(6, 9, 5);

        assertTrue(M.checkIfFree(0));
        assertTrue(M.checkIfFree(8));
    }

    @Test
    public void test_checkIfFree_fullColumn() {
        IGameBoard M = MakeABoard(6, 7, 4);

        for(int i = 0; i < 3; ++i) {
            M.placeToken('X', 0);
            M.placeToken('O', 0);
        }

        assertFalse(M.checkIfFree(0));
    }

    @Test
    public void test_checkIfFree_halfColumn() {
        IGameBoard M = MakeABoard(6, 7, 4);

        for(int i = 0; i < 3; ++i) {
            M.placeToken('X', 2);
        }

        assertTrue(M.checkIfFree(2));
    }

    // Check Horizontal Win
    @Test
    public void test_horizWin_rightSide() {
        IGameBoard M = MakeABoard(6, 9, 5);
        BoardPosition P = new BoardPosition(5, 4);

        for(int i = 0; i < 5; ++i) {
            M.placeToken('X', i);
        }

        assertTrue(M.checkHorizWin(P, 'X'));
    }

    @Test
    public void test_horizWin_middle() {
        IGameBoard M = MakeABoard(12, 12, 7);
        BoardPosition P = new BoardPosition(11, 3);

        for(int i = 0; i < 3; ++i) {
            M.placeToken('?', i);
        }

        for(int i = 6; i > 3; --i) {
            M.placeToken('?', i);
        }
        M.placeToken('?', 3);

        assertTrue(M.checkHorizWin(P, '?'));
    }

    @Test
    public void test_horizWin_fullBoard() {
        IGameBoard M = MakeABoard(4, 4, 3);
        BoardPosition P = new BoardPosition(0, 3);

        for(int i = 0; i < 4; ++i) {
            for(int j = 0; j < 1; ++j) {
                M.placeToken('X', i);
                M.placeToken('O', i);
                M.placeToken('M', i);
            }
        }
        M.placeToken('X', 0);

        // Places 3 horizontal tokens side by side to make the win condition true (and fill up board)
        for(int i = 1; i <= 3; ++i) {
            M.placeToken('J', i);
        }

        assertTrue(M.checkHorizWin(P, 'J'));
    }

    @Test
    public void test_horizWin_leftSide() {
        IGameBoard M = MakeABoard(6, 9, 5);
        BoardPosition P = new BoardPosition(5, 0);

        for(int i = 4; i >= 0; --i) {
            M.placeToken('X', i);
        }

        assertTrue(M.checkHorizWin(P, 'X'));
    }

    // Check Vertical Win
    @Test
    public void test_vertWin_bottomBoard() {
        IGameBoard M = MakeABoard(8, 8, 4);
        BoardPosition P = new BoardPosition(4, 3);

        for(int i = 0; i < 4; ++i) {
            M.placeToken('4', 3);
        }

        assertTrue(M.checkVertWin(P, '4'));
    }

    @Test
    public void test_vertWin_fullBoard() {
        IGameBoard M = MakeABoard(6, 9, 5);
        BoardPosition P = new BoardPosition(0, 4);

        for(int i = 0; i < 6; ++i) {
            for(int j = 0; j < 9; ++j) {
                if(j == 4) continue;
                M.placeToken('X', j);
                M.placeToken('O', j);
            }
        }
        M.placeToken('O', 4);

        for(int i = 0; i < 5; ++i) {
            M.placeToken('?', 4);
        }

        assertTrue(M.checkVertWin(P, '?'));
    }

    @Test
    public void test_vertWin_moreTokens_thanW() {
        IGameBoard M = MakeABoard(6, 9, 5);
        BoardPosition P = new BoardPosition(0, 3);

        for(int i = 0; i < 9; ++i) {
            M.placeToken('+', 3);
        }

        assertTrue(M.checkVertWin(P, '+'));
    }

    @Test
    public void test_vertWin_topBoard() {
        IGameBoard M = MakeABoard(8, 8, 4);
        BoardPosition P = new BoardPosition(0, 3);

        for(int i = 0; i < 4; ++i) {
            M.placeToken('?', 3);
        }

        for(int i = 0; i < 4; ++i) {
            M.placeToken('4', 3);
        }

        assertTrue(M.checkVertWin(P, '4'));
    }

    // Check Diagonal Win
    @Test
    public void test_diagWin_downRight() {
        IGameBoard M = MakeABoard(6, 9, 5);

        // Board Position of the upmost left '?' token
        BoardPosition P = new BoardPosition(1, 3);

        for(int i = 0; i < 4; ++i) {
            M.placeToken('J', 3);
        }
        for(int i = 0; i < 3; ++i) {
            M.placeToken('A', 4);
        }
        for(int i = 0; i < 2; ++i) {
            M.placeToken('K', 5);
        }
        M.placeToken('E', 6);

        for(int i = 3; i < 8; ++i) {
            M.placeToken('?', i);
        }

        assertTrue(M.checkDiagWin(P, '?'));
    }

    @Test
    public void test_diagWin_upLeft() {
        IGameBoard M = MakeABoard(6, 9, 5);

        // Board Position of the bottom right '?' token
        BoardPosition P = new BoardPosition(5, 7);

        for(int i = 0; i < 4; ++i) {
            M.placeToken('J', 3);
        }
        for(int i = 0; i < 3; ++i) {
            M.placeToken('A', 4);
        }
        for(int i = 0; i < 2; ++i) {
            M.placeToken('K', 5);
        }
        M.placeToken('E', 6);

        for(int i = 3; i < 8; ++i) {
            M.placeToken('?', i);
        }

        assertTrue(M.checkDiagWin(P, '?'));
    }

    @Test
    public void test_diagWin_downLeft() {
        IGameBoard M = MakeABoard(6, 9, 5);

        // Board Position of the upmost right '?' token
        BoardPosition P = new BoardPosition(1, 4);

        for(int i = 4; i > 0; --i) {
            M.placeToken('J', 4);
        }
        for(int i = 3; i > 0; --i) {
            M.placeToken('A', 3);
        }
        for(int i = 2; i > 0; --i) {
            M.placeToken('K', 2);
        }
        M.placeToken('E', 1);

        for(int i = 0; i < 5; ++i) {
            M.placeToken('?', i);
        }

        assertTrue(M.checkDiagWin(P, '?'));
    }

    @Test
    public void test_diagWin_upRight() {
        IGameBoard M = MakeABoard(6, 9, 5);

        // Board Position of the bottom left '?' token
        BoardPosition P = new BoardPosition(5, 0);

        for(int i = 4; i > 0; --i) {
            M.placeToken('J', 4);
        }
        for(int i = 3; i > 0; --i) {
            M.placeToken('A', 3);
        }
        for(int i = 2; i > 0; --i) {
            M.placeToken('K', 2);
        }
        M.placeToken('E', 1);

        for(int i = 0; i < 5; ++i) {
            M.placeToken('?', i);
        }

        assertTrue(M.checkDiagWin(P, '?'));
    }

    @Test
    public void test_diagWin_middle() {
        IGameBoard M = MakeABoard(6, 9, 5);

        // Board Position of the middle '?' token in the diagonal
        BoardPosition P = new BoardPosition(3, 2);

        for(int i = 4; i > 0; --i) {
            M.placeToken('J', 4);
        }
        for(int i = 3; i > 0; --i) {
            M.placeToken('A', 3);
        }
        for(int i = 2; i > 0; --i) {
            M.placeToken('K', 2);
        }
        M.placeToken('E', 1);

        for(int i = 0; i < 2; ++i) {
            M.placeToken('?', i);
        }
        for(int i = 4; i > 2; --i) {
            M.placeToken('?', i);
        }
        M.placeToken('?', 2);

        assertTrue(M.checkDiagWin(P, '?'));
    }

    @Test
    public void test_diagWin_moreTokens_thanW() {
        IGameBoard M = MakeABoard(6, 9, 5);

        // Board Position of the bottom right '?' token
        BoardPosition P = new BoardPosition(5, 7);

        for(int i = 0; i < 5; ++i) {
            M.placeToken('J', 2);
        }
        for(int i = 0; i < 4; ++i) {
            M.placeToken('A', 3);
        }
        for(int i = 0; i < 3; ++i) {
            M.placeToken('C', 4);
        }
        for(int i = 0; i < 2; ++i) {
            M.placeToken('O', 5);
        }
        M.placeToken('B', 6);

        for(int i = 2; i < 8; ++i) {
            M.placeToken('?', i);
        }

        assertTrue(M.checkDiagWin(P, '?'));
    }

    @Test
    public void test_diagWin_fullBoard() {
        IGameBoard M = MakeABoard(8, 8, 3);
        BoardPosition P = new BoardPosition(0, 0);

        for(int i = 0; i < 4; ++i) {
            M.placeToken('?', 7);
            M.placeToken('P', 7);
        }
        for(int i = 0; i < 4; ++i) {
            M.placeToken('O', 6);
            M.placeToken('X', 6);
        }
        for(int i = 0; i < 4; ++i) {
            M.placeToken('?', 5);
            M.placeToken('P', 5);
        }
        for(int i = 0; i < 4; ++i) {
            M.placeToken('O', 4);
            M.placeToken('X', 4);
        }
        for(int i = 0; i < 4; ++i) {
            M.placeToken('?', 3);
            M.placeToken('P', 3);
        }

        for(int i = 0; i < 2; ++i) {
            M.placeToken('O', 2);
            M.placeToken('X', 2);
        }
        for(int i = 0; i < 2; ++i) {
            M.placeToken('?', 1);
            M.placeToken('P', 1);
        }
        for(int i = 0; i < 2; ++i) {
            M.placeToken('O', 0);
            M.placeToken('X', 0);
        }

        for(int i = 0; i < 3; ++i) {
            M.placeToken('X', i);
        }

        // This is used for placing tokens so that a win condition is met
        M.placeToken('C', 2);
        M.placeToken('X', 1);
        M.placeToken('X', 2);
        M.placeToken('X', 2);
        M.placeToken('C', 1);
        M.placeToken('X', 0);
        M.placeToken('X', 0);
        M.placeToken('X', 1);
        M.placeToken('C', 0);

        assertTrue(M.checkDiagWin(P, 'C'));
    }

    // Check Tie
    @Test
    public void test_checkTie_fullBoard() {
        IGameBoard M = MakeABoard(6, 9, 5);

        for(int i = 0; i < 6; ++i) {
            for(int j = 0; j < 9; ++j) {
                // Used to ensure that the win condition is not violated
                if(j == 4) continue;
                if(M.checkIfFree(j)) M.placeToken('?', j);
                if(M.checkIfFree(j)) M.placeToken('X', j);
            }
        }

        for(int i = 0; i < 3; ++i) {
            if(M.checkIfFree(4)) M.placeToken('X', 4);
            if(M.checkIfFree(4)) M.placeToken('?', 4);
        }

        assertFalse(M.checkForWin(4));
        assertTrue(M.checkTie());
    }

    @Test
    public void test_checkTie_finalTokenPlaced_minBoard() {
        IGameBoard M = MakeABoard(3, 3, 3);

        for(int i = 0; i < 3; ++i) {
            if(i == 1) {
                M.placeToken('O', 1);
                M.placeToken('X', 1);
            }
            else {
                M.placeToken('X', i);
                M.placeToken('O', i);
                M.placeToken('X', i);
            }
        }
        M.placeToken('O', 1);

        assertTrue(M.checkTie());
    }

    @Test
    public void test_checkTie_maxBoard() {
        IGameBoard M = MakeABoard(100, 100, 80);

        for(int i = 0; i < 100; ++i) {
            for(int j = 0; j < 20; ++j) {
                M.placeToken('A', i);
                M.placeToken('B', i);
                M.placeToken('C', i);
                M.placeToken('D', i);
                M.placeToken('E', i);
            }
        }

        assertTrue(M.checkTie());
    }

    @Test
    public void test_checkTie_emptyBoard() {
        IGameBoard M = MakeABoard(25, 25, 12);

        assertFalse(M.checkTie());
    }

    // Whats At Position
    @Test
    public void test_whatsAtPos_space() {
        Character expected = ' ';
        IGameBoard M = MakeABoard(6, 9, 5);
        BoardPosition P = new BoardPosition(3, 4);

        Character result = M.whatsAtPos(P);

        assertEquals(result, expected);
    }

    @Test
    public void test_whatsAtPos_character() {
        Character expected = 'J';
        IGameBoard M = MakeABoard(6, 9, 5);
        M.placeToken('J', 3);

        // Board Position that 'j' is anticipated to be at
        BoardPosition P = new BoardPosition(5, 3);

        Character result = M.whatsAtPos(P);

        assertEquals(expected, result);
    }

    @Test
    public void test_whatsAtPos_fullBoard() {
        IGameBoard M = MakeABoard(6, 9, 5);
        Character expected = '?';
        BoardPosition P = new BoardPosition(5, 3);

        for(int i = 0; i < 6; ++i) {
            for(int j = 0; j < 9; ++j) {
                if(j == 4) continue;
                M.placeToken('?', j);
                M.placeToken('X', j);
            }
        }

        for(int i = 0; i < 3; ++i) {
            M.placeToken('X', 4);
            M.placeToken('?', 4);
        }

        Character result = M.whatsAtPos(P);

        assertEquals(expected, result);
    }

    @Test
    public void test_whatsAtPos_bottomRight() {
        IGameBoard M = new GameBoard(6, 7, 4);
        Character expected = 'X';
        BoardPosition P = new BoardPosition(5,6);

        M.placeToken('X', 6);
        M.placeToken('O', 6);
        M.placeToken('X', 5);

        Character result = M.whatsAtPos(P);

        assertEquals(expected, result);
    }

    @Test
    public void test_whatsAtPos_bottomLeft() {
        IGameBoard M = new GameBoard(6, 7, 4);
        Character expected = 'X';
        BoardPosition P = new BoardPosition(5,0);

        M.placeToken('X', 0);
        M.placeToken('O', 0);
        M.placeToken('X', 1);

        Character result = M.whatsAtPos(P);

        assertEquals(expected, result);
    }

    // Is Player At Position
    @Test
    public void test_isPlayerAtPos_emptyBoard() {
        IGameBoard M = new GameBoard(3, 3, 3);
        BoardPosition P = new BoardPosition(2,2);

        boolean result = M.isPlayerAtPos(P, '?');

        assertFalse(result);
    }

    @Test
    public void test_isPlayerAtPos_correctChar() {
        IGameBoard M = new GameBoard(6, 7, 4);
        BoardPosition P = new BoardPosition(5, 0);

        M.placeToken('K', 0);
        M.placeToken('A', 0);
        M.placeToken('R', 0);
        M.placeToken('I', 0);
        M.placeToken('S', 0);

        boolean result = M.isPlayerAtPos(P, 'K');

        assertTrue(result);
    }

    @Test
    public void test_isPlayerAtPos_wrongChar() {
        IGameBoard M = new GameBoard(6, 7, 4);
        BoardPosition P = new BoardPosition(5, 0);

        M.placeToken('?', 0);

        boolean result = M.isPlayerAtPos(P, '!');

        assertFalse(result);
    }

    @Test
    public void test_isPlayerAtPos_fullBoard() {
        IGameBoard M = MakeABoard(6, 9, 5);
        BoardPosition P = new BoardPosition(5, 3);

        for (int i = 0; i < 6; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (j == 4) continue;
                M.placeToken('?', j);
                M.placeToken('X', j);
            }
        }

        for (int i = 0; i < 3; ++i) {
            M.placeToken('X', 4);
            M.placeToken('?', 4);
        }

        boolean result = M.isPlayerAtPos(P, '?');

        assertTrue(result);
    }

    @Test
    public void test_isPlayerAtPos_onlyChar() {
        IGameBoard M = MakeABoard(3, 3, 3);
        BoardPosition P = new BoardPosition(2, 1);

        M.placeToken('?', 1);

        boolean result = M.isPlayerAtPos(P, '?');

        assertTrue(result);
    }

    // Place Token
    @Test
    public void test_placeToken_emptyBoard() {
        IGameBoard M = MakeABoard(6, 9, 5);
        Character[][] expected = new Character[6][9];

        M.placeToken('X', 4);
        expected[5][4] = 'X';

        assertEquals(M.toString(), CharToString(expected));
    }

    @Test
    public void test_placeToken_fullColumn() {
        IGameBoard M = MakeABoard(4,9,3);
        Character[][] expected = new Character[4][9];

        for(int i = 0; i < 50; ++i) {
            M.placeToken('?', 3);
            if(i > 3) continue;
            else expected[i][3] = '?';
        }

        assertEquals(M.toString(), CharToString(expected));
    }

    @Test
    public void test_placeToken_fullBoard() {
        IGameBoard M = MakeABoard(6, 9, 5);
        Character[][] expected = new Character[6][9];

        for (int i = 0; i < 6; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (j == 4) continue;
                M.placeToken('?', j);
                M.placeToken('X', j);
            }
        }

        for(int k = 0; k < 6; ++k) {
            for(int q = 0; q < 9; ++q) {
                expected[k][q] = 'X';
                if((k % 2) == 1) expected[k][q] = '?';
            }
        }

        for(int i = 0; i < 6; i += 2) {
            expected[i][4] = '?';
            expected[i+1][4] = 'X';
        }

        for (int i = 0; i < 3; ++i) {
            M.placeToken('X', 4);
            M.placeToken('?', 4);
        }

        // Attempt to place a token in each column while each should be full
        for(int i = 0; i < 9; ++i) {
            M.placeToken('e', i);
        }

        assertEquals(M.toString(), CharToString(expected));
    }

    @Test
    public void test_placeToken_lastToken_inColumn() {
        IGameBoard M = MakeABoard(7, 10, 6);
        Character[][] expected = new Character[7][10];

        for(int i = 0; i < 2; ++i) {
            M.placeToken('?', 5);
            M.placeToken('!', 5);
            M.placeToken('J', 5);
        }

        expected[6][5] = '?';
        expected[5][5] = '!';
        expected[4][5] = 'J';
        expected[3][5] = '?';
        expected[2][5] = '!';
        expected[1][5] = 'J';

        // Final token placed at the top of the column (last available position in col 5)
        M.placeToken('A', 5);
        expected[0][5] = 'A';

        assertEquals(M.toString(), CharToString(expected));
    }

    @Test
    public void test_placeToken_4corners() {
        IGameBoard M = MakeABoard(6, 6, 3);
        Character[][] expected = new Character[6][6];

        for(int i = 0; i < 3; ++i) {
            M.placeToken('A', 0);
            M.placeToken('B', 0);
            M.placeToken('A', 5);
            M.placeToken('B', 5);
        }

        for(int i = 0; i < 6; ++i) {
            if((i % 2) == 0) {
                expected[i][0] = 'B';
                expected[i][5] = 'B';
            }
            else {
                expected[i][0] = 'A';
                expected[i][5] = 'A';
            }
        }

        assertEquals(M.toString(), CharToString(expected));
    }
}
