package cpsc2150.banking.models;

public abstract class AbsMortgage implements IMortgage {

    /**
     * This method overrides {@link Object#toString()} to provide a string
     * representation for mortgage objects.
     *
     * @pre [interestRate and payment have been calculated]
     * @post [toString = The string value of the loan, or "Loan was not approved"]
     */
    @Override
    public String toString() {
        String str = "";
        if (loanApproved()) {
            str += "Principal Amount: $" + getPrincipal() + "\n";
            str += "Interest Rate: " + (getRate() * 100) + "%\n";
            str += "Term: " + getYears() + " years\n";
            str += "Monthly Payment: $" + getPayment() + "\n";
        } else {
            str += "Loan was not approved";
        }

        return str;
    }
}