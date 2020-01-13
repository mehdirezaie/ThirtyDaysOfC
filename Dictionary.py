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
