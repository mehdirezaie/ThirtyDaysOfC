'''
    You are given two classes, Person and Student, 
    where Person is the base class and Student is the derived class. 
    Completed code for Person and a declaration for Student 
    are provided for you in the editor. 
    Observe that Student inherits all the properties of Person.

    Complete the Student class by writing the following:

    A Student class constructor, which has  parameters:
    A string, firstName.
    A string, lastName.
    An integer, idNumber.
    An integer array (or vector) of test scores, scores.
    A char calculate() method that calculates     
    a Student object's average and returns the grade
    character representative of their calculated average

'''


class Person:
	def __init__(self, firstName, lastName, idNumber):
		self.firstName = firstName
		self.lastName = lastName
		self.idNumber = idNumber
	def printPerson(self):
		print("Name:", self.lastName + ",", self.firstName)
		print("ID:", self.idNumber)

class Student(Person):
    #   Class Constructor
    #   
    #   Parameters:
    #   firstName - A string denoting the Person's first name.
    #   lastName - A string denoting the Person's last name.
    #   id - An integer denoting the Person's ID number.
    #   scores - An array of integers denoting the Person's test scores.
    #
    # Write your constructor here
    def __init__(self, firstName, lastName, idNumber, scores):
        super().__init__(firstName, lastName, idNumber)
        self.scores = scores

    #   Function Name: calculate
    #   Return: A character denoting the grade.
    #
    # Write your function here
    def calculate(self):
        totScore = sum(self.scores)/len(self.scores)
        if (totScore >= 90) & (totScore <= 100):
            return "O"
        elif (totScore >= 80) & (totScore < 90):
            return "E"
        elif (totScore >= 70) & (totScore < 80):
            return "A"
        elif (totScore >= 55) & (totScore < 70):
            return "P"
        elif (totScore >= 40) & (totScore < 55):
            return "D"
        elif (totScore < 40):
            return "T"
        else:
            raise ValueError("Wrong values")



line = input().split()
firstName = line[0]
lastName = line[1]
idNum = line[2]
numScores = int(input()) # not needed for Python
scores = list( map(int, input().split()) )
s = Student(firstName, lastName, idNum, scores)
s.printPerson()
print("Grade:", s.calculate())
