from queue import Queue

class ElevatorSystem:
    class Elevator:
        def __init__(self):
            self.floor = 0  # current floor
            self.floor_queue = Queue()
            self.direction = 1  # 1:up, -1:down
            self.out_of_order = False
            self.in_use = False

        def request(self, floor:int) -> None:
            self.floor_queue.put(floor)

        def go(self) -> None:
            while not self.floor_queue.empty():
                next_floor = queue.get()
                if self.floor < next_floor: dir = 1
                else: dir = -1

    def __init__(self, N:int):  # N is the number of elevators.
        self.elevators = [ElevatorSystem.Elevator() for _ in range(N)]

    def request(self, dir:int, floor:int) -> None:
        # select elevator based on tiered availability
        pass
