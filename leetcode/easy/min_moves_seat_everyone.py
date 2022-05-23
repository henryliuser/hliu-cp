# honestly harder than it looks
class Solution:
    def minMovesToSeat(self, seats: List[int], students: List[int]) -> int:
        return sum(abs(a-b) for a,b in zip(sorted(seats), sorted(students)))
        # ans = 0
        # seats.sort(), students.sort()
        # for i in range(len(seats)):
        #     ans += abs(seats[i] - students[i])
        # return ans
