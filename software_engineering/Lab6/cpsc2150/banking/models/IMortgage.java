package cpsc2150.banking.models;

/**
 * This object will hold the information about a mortgage, and will handle all calculations for interest rate and monthly payments
 *
 * Defines: Payment: R - The monthly payment on the mortgage
 *          Rate: R - the interest rate per monthly period on the loan
 *          Customer: - Every loan must have an associated customer
 *          DebtToIncomeRatio: R - The ratio of the customer's total monthly debt payments (including mortgage) to their monthly income
 *          Principal: R - The amount of the loan
 *          NumberOfPayments: Z - total number of payments the customer will make on the loan
 *          PercentDown : R - The percent of the house cost covered by the down payment
 *
 * Initialization Ensures: [Rate is calculated based on the BASERATE, the years for the loan, and the PercentDown]
 *                         [Payment is calculated]
 *
 * Constraints: Payment = (Rate * Principal) / (1-(1+Rate)^ -NumberOfPayments) AND
 *              0 <= Rate <= 1 AND
 *              0 < DebtToIncomeRatio AND
 *              MIN_YEARS * 12 <= NumberOfPayments <= MAX_YEARS * 12 AND
 *              0 < Principal AND
 *              0 <= PercentDown < 1
 */
public interface IMortgage {

    // Helpful comparisons for credit scores
    int BADCREDIT = 500;
    int FAIRCREDIT = 600;
    int GOODCREDIT = 700;
    int GREATCREDIT = 750;

    // These rates are all APR (Annual Percentage Rates)
    double BASERATE = .025;
    double GOODRATEADD = .005;
    double NORMALRATEADD = .01;
    double BADRATEADD = .05;
    double VERYBADRATEADD = .1;
    double RATETOOHIGH = .1;

    // Other helpful constants
    double DTOITOOHIGH = .4;
    int MIN_YEARS = 15;
    int MAX_YEARS = 30;
    double PREFERRED_PERCENT_DOWN = .2;
    double MIN_PERCENT_DOWN = .035; // not a constraint, affects loan approval

    /**
     * This method checks to see if the mortgage loan has been approved or not.
     *
     * @return true if the loan is approved, false otherwise.
     * @post loanApproved iff (Rate*12 < RATE_TOO_HIGH AND PercentDown >= MIN_PERCENT_DOWN AND DebtToIncomeRatio <= DTOITOOHIGH)
     */
    boolean loanApproved();

    /**
     * This method returns the amount that must be paid per month for the mortgage loan.
     *
     * @return the monthly payment on the loan
     * @post getPayment = Payment
     */
    double getPayment();

    /**
     * This method returns the interest rate (APR).
     *
     * @return the interest rate (APR) for this customer
     * @post getRate = Rate * 12
     */
    double getRate();

    /**
     * This method returns the customer's principal amount for the mortgage loan.
     *
     * @return the principal amount of the loan
     * @post getPrincipal = Principal
     */
    double getPrincipal();

    /**
     * This method returns the amount of years the customer applied the mortgage loan for.
     *
     * @return the number of years the loan is for
     * @post getYears = Years
     */
    int getYears();
}
