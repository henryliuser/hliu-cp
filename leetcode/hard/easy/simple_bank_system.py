class Bank:

    def __init__(self, balance: List[int]):
        self.mp = {i+1:balance[i] for i in range(len(balance))}

    def transfer(self, a1: int, a2: int, money: int) -> bool:
        if a1 not in self.mp or a2 not in self.mp: return False
        if self.mp[a1] < money: return False
        self.mp[a1] -= money
        self.mp[a2] += money
        return True

    def deposit(self, account: int, money: int) -> bool:
        if account not in self.mp: return False
        self.mp[account] += money
        return True

    def withdraw(self, account: int, money: int) -> bool:
        if account not in self.mp: return False
        if self.mp[account] < money: return False
        self.mp[account] -= money
        return True



# Your Bank object will be instantiated and called as such:
# obj = Bank(balance)
# param_1 = obj.transfer(account1,account2,money)
# param_2 = obj.deposit(account,money)
# param_3 = obj.withdraw(account,money)
