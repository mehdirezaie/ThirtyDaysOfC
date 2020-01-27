class Difference:
    def __init__(self, a):
        self.__elements = a

	# Add your code here
    def computeDifference(self):
        self.maximumDifference=0
        n = len(self.__elements)
        for i in range(0, n):
            for j in range(i+1, n):
                diff = abs(self.__elements[i]-self.__elements[j])
                if diff > self.maximumDifference:
                    self.maximumDifference = diff

# End of Difference class

_ = input()
a = [int(e) for e in input().split(' ')]

d = Difference(a)
d.computeDifference()

print(d.maximumDifference)