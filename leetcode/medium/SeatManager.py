import heapq
class SeatManager:

    def __init__(self, n: int):
        self.avail = list(range(1,n+1))

    def reserve(self) -> int:
        return heapq.heappop(self.avail)


    def unreserve(self, seatNumber: int) -> None:
        heapq.heappush(self.avail, seatNumber)



# Your SeatManager object will be instantiated and called as such:
# obj = SeatManager(n)
# param_1 = obj.reserve()
# obj.unreserve(seatNumber)
