package cpsc2150.banking.models;

/**
 * Holds information about their customer and allows them to apply for a loan. The actual work for the loan is handled by IMortgage
 *
 * Defines: CreditScore: Z
 *          MonthlyDebt: R - How much they pay per moth towards other forms of debt (car payments, student loans, etc)
 *          Loan: The customer's mortgage they are applying for
 *          Income: R - Yearly income
 *          Name: Customer must have a name
 *
 * Initialization Ensures: Customer will have a Name, a CreditScore, MonthlyDebt, and Income
 *
 * Constraints 0 <= CreditScore <= MAX_CREDIT_SCORE AND
 *             0 <= MonthlyDebt AND
 *             0 <= Income
 */
public interface ICustomer {

    int MAX_CREDIT_SCORE = 850;

    /**
     * This method allow us to apply for a loan.
     *
     * @param downPayment the down payment on the loan
     * @param houseCost the cost of the house they want to buy
     * @param years the number of years they will take to repay the loan
     *
     * @return true if the loan was approved
     *
     * @pre 0 <= downPayment < houseCost AND houseCost > 0 AND IMortgage.MIN_YEARS <= y <= IMortgage.MAX_YEARS
     * @post [applyForLoan iff the loan was approved with those terms]
     */
    boolean applyForLoan(double downPayment, double houseCost, int years);

    /**
     * This method returns the interest rate (APR).
     *
     * @return the interest rate (APR) on the customer's loan
     *
     * @pre [the customer has applied for AND received a loan]
     * @post getRate = [interest rate of the approved loan] AND 0 <= getRate <= 1
     */
    double getRate();

    /**
     * This method returns the loan amount that needs to be paid each month.
     *
     * @return the monthly payment on the customer's loan
     *
     * @pre [the customer has applied for AND received a loan]
     * @post getMonthlyPay = [the monthly payment on the customer's loan] AND 0 < getMonthlyPay
     */
    double getMonthlyPay();

    /**
     * This method returns the amount of debt that needs to be paid each month.
     *
     * @return the customer's monthly debt payments not including the loan
     *
     * @post getMonthlyDebtPayments = MonthlyDebt
     */
    double getMonthlyDebtPayments();

    /**
     * This method returns the customer's yearly income.
     *
     * @return the customer's yearly income
     *
     * @post getIncome = income
     */
    double getIncome();

    /**
     * This method returns the customer's credit score.
     *
     * @return the customer's credit score
     *
     * @post getCreditScore = creditScore
     */
    int getCreditScore();

    /**
     * This method returns the customer's name.
     *
     * @return the customer's name
     *
     * @post getName = Name
     */
    String getName();

    /**
     * This method returns whether or not the customer applied for a mortgage loan.
     *
     * @return true if the customer applied for one, false otherwise.
     *
     * @post appliedForLoan = (loan != null)
     */
    boolean appliedForLoan();

}