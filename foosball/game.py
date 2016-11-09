class Game:
  def __init__(self, name, id='test', mode='single'):
    self.name = name
    self.id = id
    self.blackScore = 0
    self.redScore = 0
    self.mode = mode
    self.goals = []


  def getScore(self):
    currentScore = "Red: " + str(self.redScore) + " Black: " + str(self.blackScore)
    return currentScore
    
  def score(self, team):
    if team == "red":
      self.redScore += 1
    if team == "black":
      self.blackScore += 1

  def isValid(self, goal_value):
    if len(self.goals) > 0:
      delta = goal_value.timestamp - self.goals[-1].timestamp
      if float(delta.total_seconds()) >= 3:
        return True
      else:
        return False
    else:
      return True

  def addGoal(self, goal_value):
    if self.isValid(goal_value):
      self.goals.append(goal_value)
      self.score(goal_value.team)

class goal:
  def __init__(self, team, timestamp):
    self.team = team
    self.timestamp = timestamp


