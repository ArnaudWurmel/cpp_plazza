#!/usr/bin/python3
import sys
import random

string = "abcdefghi\njklmnopqrstu\nvw\nxyz"
firstname = ["arnaud", "thibaud", "erwan", "baptiste", "lucile"]
lastname = ["wurmel", "marchand", "ballet", "hector", "chauvin"]
extension = "@epitech.eu"
fileSize = 50


class   Generator:

    @staticmethod
    def GenerateMail():
        return random.choice(firstname) + "." + random.choice(lastname) + extension

    @staticmethod
    def GenerateTelephone():
        return str(random.randint(100000000, 999999999))

    @staticmethod
    def GenerateIP():
        return str(random.randint(1, 255)) + "." + str(random.randint(1, 255)) + "." + str(random.randint(1, 255)) + "." + str(random.randint(1, 255))
        

def     main():
    print("Starting generator")
    for i in range (0, fileSize):
        rand = random.randint(0, 3)
        if rand == 0:
            sys.stdout.write(Generator.GenerateIP())
        elif rand == 1:
            sys.stdout.write("0" + Generator.GenerateTelephone())
        else:
            sys.stdout.write(Generator.GenerateMail())
        X = random.randint(1, 255)
        print("")
        sys.stdout.write(''.join(random.choice(string) for x in range(X)))
        sys.stdout.write(str(i) + "\n")



if __name__ == "__main__":
    main()
