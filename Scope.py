'''
    Complete the Difference class by writing the following:`

    A class constructor that takes an array of integers 
    as a parameter and saves it to the elements instance variable.
    A computeDifference method that finds the maximum
    absolute difference between any 2 numbers in N
    and stores it in the maximumDifference instance variable.

'''
class Difference:
    def __init__(self, a):
        self._elements = a

	# Add your code here
    def computeDifference(self):
        self.maximumDifference=0
        n = len(self._elements)
        for i in range(0, n):
            for j in range(i+1, n):
                diff = abs(self._elements[i]-self._elements[j])
                if diff > self.maximumDifference:
                    self.maximumDifference = diff

# End of Difference class

_ = input()
a = [int(e) for e in input().split(' ')]

d = Difference(a)
d.computeDifference()

print(d.maximumDifference)
