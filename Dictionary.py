'''
Given n names and phone numbers, assemble a phone book 
that maps friends' names to their respective phone numbers.
You will then be given an unknown number of names to query 
your phone book for. For each name queried, print the associated 
entry from your phone book on a new line in the form name=phoneNumber;
if an entry for name is not found, print Not found instead.

'''

# Enter your code here. Read input from STDIN. Print output to STDOUT
num = int(input())

PhoneBook = {}
for i in range(num):
    line = input().strip().split(' ')
    PhoneBook[line[0]] = line[1]

Queries = []
while True:
    try:
        Queries.append(input())
    except:
        break

for query in Queries:
    if not query in PhoneBook:
        print('Not found')
    else:
        print(f'{query}={PhoneBook[query]}')