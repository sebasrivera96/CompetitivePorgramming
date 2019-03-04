# This is an implementation of the classical Towers of Hanoi problem

class Tower:
    # ===== Atributes =====
    index = 0
    disks = [] # Stack for integers

    # ===== Methods =====
    def __init__(self, numOfDisks=0):
        self.index = numOfDisks
    
    def getIndex(self):
        return self.index
    
    def add(self, d):
        self.disks.append(d)

    def moveTopTo(self, destTower):
        currTop = self.disks.pop()
        destTower.add(currTop)

    def moveDisks(self, n, destination, buffer):
        if n > 0:
            self.moveDisks(n-1, buffer, destination)
            self.moveTopTo(destination)
            buffer.moveDisks(n-1, destination, self)

def moveTop(origin, destination):
    origin.moveTopTo(destination)

def moveDisks(n, origin, destination, buffer):
    # Base case
    if n <= 0:
        return NULL

    # Move top n-1 from origin to buffer, using destination as a buffer
    moveDisks(n - 1, origin, buffer, destination)

    # Move top from origin to destination
    moveTop(origin, destination)

    # Move top n-1 disks from buffer to destination, using origin as a buffer
    moveDisks(n-1, buffer, destination, origin)

def main():
    n = 3 # Example of 3 disks on the first tower

    tower1 = Tower(numOfDisks=n)
    tower2 = Tower()
    tower3 = Tower()

    towers = [tower1, tower2, tower3]

    for i in range(n-1,0,-1):
        towers[i].add(i)

    print(towers[0].disks)
    print(towers[2].disks)

    towers[0].moveDisks(n, towers[2], towers[1])
    print(towers[0].disks)
    print(towers[2].disks)

if __name__ == "__main__":
    main()