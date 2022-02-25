package cpsc2150.extendedConnectX;

/**
 * This class is the controller for our setup screen. The processButtonClick method is called by
 * SetupView when someone clicks on the submit button. It is passed in the rows, cols, players and
 * the number to win by the view, but it still needs to validate that input. If there are any
 * errors it can use the displayError method in the SetupView class to inform the player of the
 * error, then wait for them to fix it and resubmit.
 * <p>
 * If there are no errors it will create a new IGameBoard object (the implementation will depend on
 * the size of the game board) to serve as the model, and the ConnectXController and ConnectXView.
 * Control is then passed over the the event dispatch thread that will wait for an event to occur
 * <p>
 * No changes need to be made to this class.
 */
public class SetupController {

    private SetupView view;
    private final int BOARD_CUTOFF = 100;

    public SetupController(SetupView v) {
        view = v;
    }

    public void processButtonClick(int rows, int cols, int players, int numWin) {
        String errorMsg = "";
        // Checks passed row precondition for GameBoard
        if (rows < GameBoard.MIN_DIM || rows > GameBoard.MAX_DIM) {
            errorMsg += "Rows must be between " + GameBoard.MIN_DIM + " and " + GameBoard.MAX_DIM;
            view.displayError(errorMsg);
            return;
        }

        // Checks passed col precondition for GameBoard
        if (cols < GameBoard.MIN_DIM || cols > GameBoard.MAX_DIM) {
            errorMsg += "Columns must be between " + GameBoard.MIN_DIM + " and " + GameBoard.MAX_DIM;
            view.displayError(errorMsg);
            return;
        }

        // Checks passed numWin (numWin < rows) precondition for GameBoard
        if (numWin > rows) {
            errorMsg += "Can't have more to win than the number of rows";
            view.displayError(errorMsg);
            return;
        }

        // Checks passed numWin (numWin < cols) precondition for GameBoard
        if (numWin > cols) {
            errorMsg += "Can't have more to win than the number of Columns";
            view.displayError(errorMsg);
            return;
        }

        // Checks passed numWin (numWin > MIN_WIN) precondition for GameBoard
        if (numWin < GameBoard.MIN_WIN) {
            errorMsg += "Number to win must be at least " + GameBoard.MIN_WIN;
            view.displayError(errorMsg);
            return;
        }

        IGameBoard model;
        view.closeScreen();
        //if the board is too big we'll want the memory efficient version
        if (rows * cols > BOARD_CUTOFF) {
            model = new GameBoardMem(rows, cols, numWin);
        } else {
            model = new GameBoard(rows, cols, numWin);
        }
        ConnectXView tview = new ConnectXView(rows, cols);
        ConnectXController tcontroller = new ConnectXController(model, tview, players);

        tview.registerObserver(tcontroller);
    }
}