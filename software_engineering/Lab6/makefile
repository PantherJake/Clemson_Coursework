default: cpsc2150/banking/MortgageApp.java cpsc2150/banking/models/IMortgage.java cpsc2150/banking/models/ICustomer.java cpsc2150/banking/models/AbsMortgage.java cpsc2150/banking/models/AbsCustomer.java cpsc2150/banking/models/Mortgage.java cpsc2150/banking/models/Customer.java
	javac cpsc2150/banking/MortgageApp.java cpsc2150/banking/models/IMortgage.java cpsc2150/banking/models/ICustomer.java cpsc2150/banking/models/AbsMortgage.java cpsc2150/banking/models/AbsCustomer.java cpsc2150/banking/models/Mortgage.java cpsc2150/banking/models/Customer.java
	
run: cpsc2150/banking/MortgageApp.class cpsc2150/banking/models/IMortgage.class cpsc2150/banking/models/ICustomer.class cpsc2150/banking/models/AbsMortgage.class cpsc2150/banking/models/AbsCustomer.class cpsc2150/banking/models/Mortgage.class cpsc2150/banking/models/Customer.class
	java cpsc2150.banking.MortgageApp

test: cpsc2150/banking/models/TestMortgage.java cpsc2150/banking/models/IMortgage.java cpsc2150/banking/models/ICustomer.java cpsc2150/banking/models/AbsMortgage.java cpsc2150/banking/models/AbsCustomer.java cpsc2150/banking/models/Mortgage.java cpsc2150/banking/models/Customer.java
	javac -cp .:/usr/share/java/junit4.jar cpsc2150/banking/models/TestMortgage.java cpsc2150/banking/models/IMortgage.java cpsc2150/banking/models/ICustomer.java cpsc2150/banking/models/AbsMortgage.java cpsc2150/banking/models/AbsCustomer.java cpsc2150/banking/models/Mortgage.java cpsc2150/banking/models/Customer.java

runtest: cpsc2150/banking/models/TestMortgage.class cpsc2150/banking/models/IMortgage.class cpsc2150/banking/models/ICustomer.class cpsc2150/banking/models/AbsMortgage.class cpsc2150/banking/models/AbsCustomer.class cpsc2150/banking/models/Mortgage.class cpsc2150/banking/models/Customer.class
	java -cp .:/usr/share/java/junit4.jar org.junit.runner.JUnitCore cpsc2150.banking.models.TestMortgage
	
clean: 
	rm -f cpsc2150/banking/models/*.class
	rm -f cpsc2150/banking/*.class