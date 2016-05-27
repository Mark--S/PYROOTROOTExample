class randomGen:
    
    seed = 0
    lastRandom = 0
    multiplier =  0
    constant = 0
    modulo = 0

    def __init__(self,seed):
        self.seed = seed
        self.modulo = 2**32
        self.constant =  1664525
        self.multiplier = 1013904223
        self.lastRandom = seed

    def getSeed(self):
        return self.seed

    def setSeed(self,seed):
        self.seed = seed

    
    def getRandom(self,lowerLimit,upperLimit):
        randomNumber = ((self.multiplier*self.lastRandom)+self.constant) % self.modulo
        self.lastRandom = randomNumber
        randomFloat = ((float(randomNumber)/self.modulo)*(upperLimit-lowerLimit))+lowerLimit
        return randomFloat


