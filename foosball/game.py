class Game:
    def __init__(self, name, id='test', mode='single'):
        self.name = name
        self.id = id
        self.blackScore = 0
        self.redScore = 0
        self.mode = mode


    def get_score(self):
        currentScore = redScore + " - " + blackScore
        return currentScore
    
    def scoreRed(self):
 	self.redScore += 1
	return

    def scoreBlack(self):
 	self.blackScore += 1
	return
