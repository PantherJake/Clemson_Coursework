package cpsc2150.banking.models;

public class Customer extends AbsCustomer implements ICustomer {

    /**
     * @invariant name != "" AND monthlyDeptPayments >= 0 AND income >= 0 AND 0 <= creditScore <= MAX_CREDIT_SCORE
     * Correspondence self.CreditScore = creditScore AND self.monthlyDebt = monthlyDebtPayments AND
     * self.Loan = loan AND self.Income = income AND self.Name = name
     */
    private String name;
    private double monthlyDebtPayments;
    private double income;
    private int creditScore;

    /**
     * This creates a new object to keep track information for a bank customer.
     *
     * @param debt  the customer's monthly debt payments
     * @param inc   the customer's yearly income
     * @param score the customers credit score
     * @param n     the customers name
     * @pre debt >= 0 AND inc >= 0 AND 0 <= score <= MAX_CREDIT_SCORE AND n != ""
     * @post monthlyDebtPayments = debt AND income = inc AND creditScore = score AND name = n
     */
    public Customer(double debt, double inc, int score, String n) {
        monthlyDebtPayments = debt;
        income = inc;
        creditScore = score;
        name = n;
    }

    @Override
    public boolean applyForLoan(double downPayment, double houseCost, int years) {
        loan = new Mortgage(houseCost, downPayment, years, this);

        return loan.loanApproved();
    }

    @Override
    public double getRate() {
        return loan.getRate();
    }

    @Override
    public double getMonthlyPay() {
        return loan.getPayment();
    }

    @Override
    public double getMonthlyDebtPayments() {
        return monthlyDebtPayments;
    }

    @Override
    public double getIncome() {
        return income;
    }

    @Override
    public int getCreditScore() {
        return creditScore;
    }

    @Override
    public String getName() {
        return name;
    }

    @Override
    public boolean appliedForLoan() {
        return loan != null;
    }
}