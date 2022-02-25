
class DebugMe:

    # Stores the information needed to compute the total price of a meal
    def __init__(self, item_prices, sales_tax, tip_percentage):
        self.item_prices = item_prices
        self.sales_tax = sales_tax
        self.tip_percentage = tip_percentage
        
    # Compute the price of the entire meal (i.e. sum up the price of each item purchased)
    def compute_meals_price(self):
        total = 0
        for m in self.item_prices:
            total += m
        return total

    # Compute the sales tax for a purchase of a given amount of money
    def compute_sales_tax(self, original_price):
        return original_price * self.sales_tax

    # Compute the tip appropriate for a given amount of money
    def compute_tip(self, original_price):
        return original_price * self.tip_percentage

    # Compute the total cost of the meal (we'll be nice and include the tax when we calculate the tip)
    # Round the final cost to 2 decimal places, since that's the smallest monetary division available to us
    def compute_total_cost(self):
        meals = self.compute_meals_price()
        tax = self.compute_sales_tax(meals)
        tip = self.compute_tip(meals + tax)
        return round(meals + tax + tip, 2)
    

# The main method which calls your code to compute the total cost of a meal
if __name__ == "__main__":
    items = [4.95, 11.17, 9.87]
    taxPercent = 0.07
    tipPercent = 0.18

    bill = DebugMe(items, taxPercent, tipPercent)
    print("Total cost is " + str(bill.compute_total_cost()))
