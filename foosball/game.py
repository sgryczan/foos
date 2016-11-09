class Game:
  def __init__(self, name, id='test', mode='single'):
    self.name = name
    self.id = id
    self.blackScore = 0
    self.redScore = 0
    self.mode = mode


  def getScore(self):
    currentScore = "Red: " + str(self.redScore) + " Black: " + str(self.blackScore)
    return currentScore
    
  def score(self, team):
    if team == "red":
      self.redScore += 1
    if team == "black":
      self.blackScore += 1
