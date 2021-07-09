"""Implementation of a lift System"""

from enum import Enum
from typing import TypeVar
from threading import Lock, Thread
from heapq import heappush, heappop
import time
import random


LiftType = TypeVar('LiftType', bound='Lift')
QueueManagerType = TypeVar('QueueManagerType', bound='QueueManager')
SensorNameType = TypeVar('SensorNameType', bound='SensorName')
DirectionType = TypeVar('DirectionType', bound='DirectionType')

class SensorName(Enum):
  weight = 'weight'
  smoke = 'smoke'

class Direction(Enum):
  up = 1
  down = -1

class State(Enum):
  running = 'running'
  wait = 'waiting'
  stop = 'stop'

class Lift:
  def __init__(self, num_floors: int):
    """
    Contains all the properties of lift
    :param sensors: A list of sensor objects
    """
    self.num_floors = num_floors
    self.curr_direction = Direction.up
    self.state = State.running
    self.curr_floor = 0
    self.instruction_queue = {Direction.up: [], Direction.down: []}
    self.queue_lock = Lock()

  def move(self):
    """
    Moves the lift according to the instruction
    """
    if self.state in [State.running, State.wait]:
      if len(self.instruction_queue[Direction.up]) or len(self.instruction_queue[Direction.down]):
        self.state = State.running
        try:
          stop = heappop(self.instruction_queue[Direction.up])
        except IndexError:
          stop = -1
        if stop > -1:
          self.curr_floor = stop
          print(stop, Direction.up)
        else:
          if self.curr_direction == Direction.up:
            self.curr_direction = Direction.down
            if len(self.instruction_queue[Direction.down]):
              stop = heappop(self.instruction_queue[Direction.down])
              self.curr_floor = stop
              print(stop, Direction.down)
            else:
              self.state = State.wait
          else:
            self.curr_direction = Direction.up
        self.move()
      else:
        self.state = State.wait

  def add_instruction(self, floor, direction=None):
    if direction == Direction.up:
      time.sleep(random.uniform(0,1))
    else:
      time.sleep(random.uniform(0,4))
    if direction is None:
      if self.curr_floor > floor:
        direction = Direction.down
      else:
        direction = Direction.up
    with self.queue_lock:
      heappush(self.instruction_queue[direction], floor)
    self.move()


if __name__ == '__main__':
  lift_1 = Lift(21)
  lift_1.add_instruction(0, Direction.up)
  Thread(target=lift_1.add_instruction, args=(2,)).start()
  Thread(target=lift_1.add_instruction, args=(5,)).start()
  Thread(target=lift_1.add_instruction, args=(2,)).start()
  Thread(target=lift_1.add_instruction, args=(18,)).start()
  Thread(target=lift_1.add_instruction, args=(12,)).start()
  Thread(target=lift_1.add_instruction, args=(21,)).start()
