import time


class Clock:
    def __init__(self, name):
        self.name = name
        self.time = None

    def setTime(self, ts):
        self.time = ts

    def getTime(self):
        return self.time

    def resetTime(self):
        self.time = time.time()

    def get_diffTime(self):
        if self.time:
            return time.time() - self.time
        else:
            return None
