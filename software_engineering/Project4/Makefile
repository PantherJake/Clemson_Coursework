default: cpsc2150/extendedConnectX/GameBoard.java cpsc2150/extendedConnectX/AbsGameBoard.java cpsc2150/extendedConnectX/IGameBoard.java cpsc2150/extendedConnectX/GameBoardMem.java cpsc2150/extendedConnectX/GameScreen.java cpsc2150/extendedConnectX/BoardPosition.java
	javac -Xlint cpsc2150/extendedConnectX/GameBoard.java cpsc2150/extendedConnectX/AbsGameBoard.java cpsc2150/extendedConnectX/IGameBoard.java cpsc2150/extendedConnectX/GameBoardMem.java cpsc2150/extendedConnectX/GameScreen.java cpsc2150/extendedConnectX/BoardPosition.java

run: cpsc2150/extendedConnectX/GameBoard.class cpsc2150/extendedConnectX/AbsGameBoard.class cpsc2150/extendedConnectX/IGameBoard.class cpsc2150/extendedConnectX/GameBoardMem.class cpsc2150/extendedConnectX/GameScreen.class cpsc2150/extendedConnectX/BoardPosition.class
	java cpsc2150.extendedConnectX.GameScreen

test: cpsc2150/extendedConnectX/TestGameBoard.java cpsc2150/extendedConnectX/TestGameBoardMem.java cpsc2150/extendedConnectX/IGameBoard.java cpsc2150/extendedConnectX/AbsGameBoard.java cpsc2150/extendedConnectX/GameBoard.java cpsc2150/extendedConnectX/GameBoardMem.java
	javac -cp .:/usr/share/java/junit4.jar cpsc2150/extendedConnectX/TestGameBoard.java cpsc2150/extendedConnectX/TestGameBoardMem.java cpsc2150/extendedConnectX/IGameBoard.java cpsc2150/extendedConnectX/AbsGameBoard.java cpsc2150/extendedConnectX/GameBoard.java cpsc2150/extendedConnectX/GameBoardMem.java

testGB: cpsc2150/extendedConnectX/TestGameBoard.java cpsc2150/extendedConnectX/IGameBoard.java cpsc2150/extendedConnectX/AbsGameBoard.java cpsc2150/extendedConnectX/GameBoard.java
	java -cp .:/usr/share/java/junit4.jar org.junit.runner.JUnitCore cpsc2150.extendedConnectX.TestGameBoard

testGBmem: cpsc2150/extendedConnectX/TestGameBoardMem.java cpsc2150/extendedConnectX/IGameBoard.java cpsc2150/extendedConnectX/AbsGameBoard.java cpsc2150/extendedConnectX/GameBoardMem.java
	java -cp .:/usr/share/java/junit4.jar org.junit.runner.JUnitCore cpsc2150.extendedConnectX.TestGameBoardMem

clean:
	rm -f cpsc2150/extendedConnectX/*.class
