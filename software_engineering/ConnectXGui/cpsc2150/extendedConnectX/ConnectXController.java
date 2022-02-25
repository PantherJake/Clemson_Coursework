package cpsc2150.extendedConnectX;

/**
 * The controller class will handle communication between our View and our Model (IGameBoard)
 * <p>
 * This is where you will write code
 * <p>
 * You will need to include your IGameBoard interface
 * and both of the IGameBoard implementations from Project 4
 * If your code was correct you will not need to make any changes to your IGameBoard implementation class
 */
public class ConnectXController {

    //our current game that is being played
    private IGameBoard curGame;

    //The screen that provides our view
    private ConnectXView screen;

    public static final int MAX_PLAYERS = 10;
    //our play tokens are hard coded. We could make a screen to get those from the user, but

    private int numPlayers;
    private static int turnCount;
    private static int tokenCount;
    private int prevCol;

    private Character[] Players;

    /**
     * @param model the board implementation
     * @param view  the screen that is shown
     * @post the controller will respond to actions on the view using the model.
     */
    ConnectXController(IGameBoard model, ConnectXView view, int np) {
        this.curGame = model;
        this.screen = view;
        numPlayers = np;
        turnCount = 0;
        Players = new Character[MAX_PLAYERS];
        screen.setMessage("It is X's turn.");

        Players[0] = 'X';
        Players[1] = 'O';
        Players[2] = '?';
        Players[3] = 'A';
        Players[4] = 'P';
        Players[5] = 'Z';
        Players[6] = '4';
        Players[7] = '$';
        Players[8] = '@';
        Players[9] = 'G';
    }

    /**
     * @param col the column of the activated button
     * @post will allow the player to place a token in the column if it is not full, otherwise it will display an error
     * and allow them to pick again. Will check for a win as well. If a player wins it will allow for them to play another
     * game hitting any button
     */
    public void processButtonClick(int col) {
        // If a win condition is present and the user has clicked a button, newGame is executed.
        if(tokenCount > 0)
        if(curGame.checkTie() || curGame.checkForWin(prevCol)) {
            tokenCount = 0;
            turnCount = 0;
            newGame();
            return;
        }

        BoardPosition temp;
        int row = 0;

        // Checks preconditions of placeToken
        if(col > curGame.getNumColumns()-1 || col < 0) {
            screen.setMessage("Column must be greater than 0 but less than " + curGame.getNumColumns() + ".");
            return;
        }
        if(!curGame.checkIfFree(col)) {
            screen.setMessage("Column is full.");
            return;
        }

        // Increment turnCount and tokenCount since preconditions passed and placeToken in col
        turnCount++;
        curGame.placeToken(Players[turnCount-1], col);
        tokenCount++;

        // Finds the row on the GUI that is needed to place a marker
        for(int i = curGame.getNumRows()-1; i >= 0; --i) {
            temp = new BoardPosition(i, col);
            if(curGame.whatsAtPos(temp) == Players[turnCount-1]) {
                row = (curGame.getNumRows() - i) - 1;
            }
        }

        // Sets marker on the GUI
        screen.setMarker(row, col, Players[turnCount-1]);

        // Checks win and tie condition after each token placement
        if(curGame.checkForWin(col)) {
            screen.setMessage("Player " + Players[turnCount-1] + " won! Click any button to play again.");
        }
        else if(curGame.checkTie()) {
            screen.setMessage("Game is a tie. Click any button to play again.");
        }

        // Need this to check for win on next click
        prevCol = col;

        // If the turnCount has reached the number of players playing, set it back to 0
        if(turnCount == numPlayers) turnCount = 0;
        // Set message for what player's turn it is
        if(!curGame.checkTie() && !curGame.checkForWin(col)) screen.setMessage("It is " + Players[turnCount] + "'s turn.");
    }

    /**
     * This method will start a new game by returning to the setup screen and controller
     */
    private void newGame() {
        //close the current screen
        screen.dispose();
        //start back at the set up menu
        SetupView screen = new SetupView();
        SetupController controller = new SetupController(screen);
        screen.registerObserver(controller);
    }
}