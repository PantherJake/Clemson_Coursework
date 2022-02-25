package cpsc2150.banking.models;
import java.lang.Math;

/*
Jacob Vickio
Jimmy Martinez
*/

/**
 * @invariant
 * 0 <= percentDown < 1
 * 0 < payment < principal
 * 0 <= downPayment < cost
 * 0 < debtToIncomeRatio
 * MIN_YEARS * 12 <= numberOfPayments <= MAX_YEARS * 12
 * 0 <= rate <= 1
 * 0 < cost
 * 0 < principal
 * 0 < APR
 * MIN_YEARS < years < MAX_YEARS
 * Customer = valid ICustomer
 *
 * Correspondence
 * self.percentDown = percentDown AND self.payment = payment AND self.debtToIncomeRatio = debtToIncomeRatio
 * AND self.NumberOfPayments = numberOfPayments AND self.interestRate = rate AND self.APR = APR AND
 * self.totalCost = cost AND self.downPayment = downPayment AND self.totalYears = years AND self.principal = principal
 * AND self.Customer = Customer object
 */
public class Mortgage extends AbsMortgage implements IMortgage {

    private double percentDown;
    private double payment;
    private double debtToIncomeRatio;
    private double numberOfPayments;
    private double rate;
    private double APR;
    private double cost;
    private double downPayment;
    private int years;
    private double principal;
    private ICustomer Customer;

    /**
     * This creates a mortgage object to help keep track of necessary payments and interest
     *
     * @param c     total cost of the house
     * @param dp    initial payment made on house
     * @param y     total years that payments will be made
     * @param cust  Customer object that holds the information of the customer
     * @pre c > 0 AND c > dp > 0 AND y > 0 AND cust is a valid ICustomer object
     * @post Customer = cust AND cost = c AND years = y AND numberOfPayments = y*12
     * AND principal = c-dp AND percentDown = dp/c AND rate = APR/12 AND
     * payment = (rate*principal)/(1-Math.pow(1+rate,-(numberOfPayments)))
     * AND debtToIncomeRatio = Customer monthly debts/(Customer income / 12)
     */
    public Mortgage(double c, double dp, int y, ICustomer cust) {
        Customer = cust;
        cost = c;
        downPayment = dp;
        years = y;
        numberOfPayments = y * 12;
        principal = c - dp;
        percentDown = dp / c;

        APR = BASERATE;
        if(years < MAX_YEARS) APR += GOODRATEADD;
        else APR += NORMALRATEADD;

        if(percentDown < PREFERRED_PERCENT_DOWN) APR += GOODRATEADD;
        if(Customer.getCreditScore() < BADCREDIT) APR += VERYBADRATEADD;
        else if(Customer.getCreditScore() < FAIRCREDIT && Customer.getCreditScore() >= BADCREDIT) APR += BADRATEADD;
        else if(Customer.getCreditScore() < GOODCREDIT && Customer.getCreditScore() >= FAIRCREDIT) APR += NORMALRATEADD;
        else if(Customer.getCreditScore() < GREATCREDIT && Customer.getCreditScore() >= GOODCREDIT) APR += GOODRATEADD;
        rate = APR / 12;

        payment = (rate * principal) / (1 - Math.pow(1 + rate, -(numberOfPayments)));
        debtToIncomeRatio = Customer.getMonthlyDebtPayments() / (Customer.getIncome() / 12);
    }

    public boolean loanApproved() {
        return APR <= RATETOOHIGH && percentDown > MIN_PERCENT_DOWN && debtToIncomeRatio < DTOITOOHIGH;
    }

    public double getPayment() { return payment; }
    public double getRate() { return APR; }
    public double getPrincipal() { return principal; }
    public int getYears() { return years; }
}
