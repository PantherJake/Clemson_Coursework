default: cpsc2150/MyDeque/ArrayDeque.java cpsc2150/MyDeque/AbsDeque.java cpsc2150/MyDeque/ListDeque.java cpsc2150/MyDeque/IDeque.java cpsc2150/MyDeque/DequeApp.java cpsc2150/MyDeque/IntegerDequeApp.java
	javac -Xlint cpsc2150/MyDeque/ArrayDeque.java cpsc2150/MyDeque/AbsDeque.java cpsc2150/MyDeque/ListDeque.java cpsc2150/MyDeque/IDeque.java cpsc2150/MyDeque/DequeApp.java cpsc2150/MyDeque/IntegerDequeApp.java

runChar: cpsc2150/MyDeque/ArrayDeque.class cpsc2150/MyDeque/AbsDeque.java cpsc2150/MyDeque/ListDeque.class cpsc2150/MyDeque/IDeque.class cpsc2150/MyDeque/DequeApp.class
	java cpsc2150.MyDeque.DequeApp

runInt: cpsc2150/MyDeque/ArrayDeque.class cpsc2150/MyDeque/AbsDeque.java cpsc2150/MyDeque/ListDeque.class cpsc2150/MyDeque/IDeque.class cpsc2150/MyDeque/DequeApp.class
	java cpsc2150.MyDeque.IntegerDequeApp

clean:
	rm -f cpsc2150/MyDeque/*.class
