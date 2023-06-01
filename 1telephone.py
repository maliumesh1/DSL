"""Consider telephone book database of N clients. Make use of a hash table implementation to quickly look up client‘s telephone number. Make use of two collision handling techniques and compare them using number of comparisons required to find a set of telephone numbers"""
class Record:
    def __init__(self, name, number):
        self.name = name
        self.number = number

class Hashing:
    def __init__(self):
        self.size = int(input("Enter size: "))
        self.comparison = 0
        self.elementCount = 0 
        self.table = [None] * self.size

    def isFull(self):
        val = True if self.elementCount == self.size else False
        return val

    def hashFunction(self, element):
        return element % self.size

    def insert(self, record):
        if self.isFull():
            print("Hashing table is full")
            return False

        isStored = False

        position = self.hashFunction(record.number)

        if self.table[position] == None:
            self.table[position] = record
            print("Record: ",record.name,"   Position:" ,position)
            isStored = True,
            self.elementCount += 1

        else: 
            print("Collision, finding new position...")
            while self.table[position] != None:
                position += 1
                if position >= self.size:
                    position = 0
            self.table[position] = record

            print("Record: ",record.name,"\n Position:" ,position)
            isStored = True
            self.elementCount += 1

        return isStored


obj = Hashing()
obj.insert(Record("John", 100))
obj.insert(Record("Jane", 202))
obj.insert(Record("Mary", 303))
obj.insert(Record("Mike", 404))
obj.insert(Record("Kite", 500))

