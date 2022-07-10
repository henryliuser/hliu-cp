from collections import deque

class Elevator:
    def __init__(self):
        self.floor = 0   # current floor
        self.target = 0  # next floor
        self.floor_queue = deque()  # assume synchronous requests, no race conditions
        self.direction = 1  # 1:up, -1:down
        self.in_use = False

        # bonus stuff if you have time
        self.out_of_order = False
        self.restriction_level = 0

    def request(self, floor:int) -> None:
        dir = 1 if (self.floor < floor) else -1
        if __on_the_way(floor):
            __preempt(floor)
        else:
            self.floor_queue.append(floor)
            # doesn't usually make sense to change direction, but
            # you can be more creative with the logic here

    def go(self) -> None:
        if not self.floor_queue:
            self.in_use = False
            return  # nothing to do

        self.target = queue.popleft()
        self.direction = 1 if (self.floor < self.target) else -1
        self.in_use = True

    def __preempt(self, floor:int):
        # cut ahead in line. service this request first and push
        # the current one to the front of the queue.
        self.floor_queue.appendleft(self.target)  # push back onto the queue
        self.target = floor  # and then handle this one first.
        # direction should stay the same

    def __on_the_way(self, floor:int) -> bool:
        if self.direction == 1:
            return self.floor <= floor <= self.target
        else:
            return self.floor >= floor >= self.target


class ElevatorSystem:
    def __init__(self, num_floors:int, num_elevators:int):
        self.elevators = [ Elevator() for _ in range(num_elevators) ]

    def request(self, floor:int, dir:int) -> None:
        idle = [ e for e in self.elevators if not e.in_use ]
        if not idle:   # none idle
            best = __findBest(floor, dir)
            best.request(floor, dir)
        else:
            dist = lambda e : abs(e.floor - floor)
            closest = min(idle, key=dist)
            closest.request(floor, dir)

    def __findBest(self, floor:int, dir:int) -> Elevator:
        """
        leave this for last. abstract it away unless
        they push for implementation. if they do, you can say:
        assign each elevator a score based on their current dist
        and what's in their floor queue, based on some statistical
        data about how long it takes to service some number of requests.
        then choose the minimum one.
        """


"""
If the guys asks you to decompose the classes even further, do:

class Button:
    def __init__(self, func : callable):
        self.action = func
    def __call__(self, *args, **kwargs):
        self.action(*args, **kwargs)

class Elevator:
    def __init__(self, num_floors:int):
        self.floor = 0
        self.target = 0
        self.floor_queue = deque()
        self.direction = 1
        self.in_use = False

        n = num_floors
        req = lambda floor : lambda : self.request(floor)
        self.buttons = [ Button(req(i)) for i in range(n) ]

        self.buttons += [ Button() ]  #  open door
        self.buttons += [ Button() ]  # close door
        self.buttons += [ Button() ]  # firefighters
        self.buttons += [ Button() ]  # call for help
        # etc ...

-------------------------------------------------------------------------------------

BONUS STUFF IF YOU HAVE TIME:
add access_level to Elevator state and handle in request logic
add out_of_order edge case and handling
implement __findBest()
more creative logic for handling __prempt() in a smarter way,
    if you take this route also probably use a statistical argument
    say that past some threshold, it's worth it to change directions
    to service some request or whatever
"""
