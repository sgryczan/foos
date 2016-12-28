class Game:
  def __init__(self, name, id='test', mode='single', scorelimit=10):
    self.name = name
    self.id = id
    self.blackScore = 0
    self.redScore = 0
    self.mode = mode
    self.goals = []
    self.scorelimit = scorelimit
    self.winner = None
    self.loser = None
    self.startTime = None
    self.endTime = None
    self.playTime = None	

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
      goal_value.valid = self.isValid(goal_value)
      self.goals.append(goal_value)
      self.score(goal_value.team)
      
      if self.blackScore == self.scorelimit or self.redScore == self.scorelimit:
        out = self.endGame()
        return out


  def endGame(self):
    #self.convertGoals()
    if self.redScore > self.blackScore:
      self.winner = 'red'
      self.loser = 'black'
    else:
      self.winner = 'black'
      self.loser = 'red'
    output = "Game finished. Winner: " + self.winner
    return output

  def convertGoals(self):
    for i in self.goals:
      i.convertTS()

class goal:
  def __init__(self, team, timestamp, valid=False):
    self.team = team
    self.timestamp = timestamp
    self.valid = valid

  def convertTS(self):
    self.timestamp = self.timestamp.isoformat()

  def isoformat(self):
    return self.timestamp.isoformat()
 
  def validate(self):
    self.valid = True


class team:
  def __init__(self, name, color):
    self.name = name
    self.color = color


class player:
  def __init__(self, name):
    self.name = name
