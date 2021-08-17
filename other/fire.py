age = 31  # grad at 22, 9 years later im 31
savings   = 500000  # 500k here
portfolio = 3000000 # 3m here
rate = 1.04
annual_spending = 190000
while savings + portfolio > 0:
    if savings > 0:  # take from savings first
        savings -= annual_spending
        if savings < 0:  # if we go over, dip into portfolio
            portfolio += savings
            savings = 0
    elif portfolio > 0:  # take from portfolio if we have no savings
        portfolio -= annual_spending
    portfolio *= rate  # apply the rate
    age += 1
    print(f"{age}: NW = {savings + portfolio:<10.2f}")
    print(f"Cash:     {savings:<7.2f}")
    print(f"Invested: {portfolio:<7.2f}")
    print("-"*20)
