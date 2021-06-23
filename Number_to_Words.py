import sys


# Function to convert a single-digit or two-digit or three-digit number into words
def convertToDigit(n, suffix):
 
    # if n is zero
    if n == 0:
        return EMPTY
 
    s = EMPTY
    if n>99:
        s = X[n // 100] +"Hundred and "

    if n%100 > 19:
            return s + Y[(n % 100)//10] + X[(n % 100)%10] + suffix
    else:
        return s + X[n%100] + suffix
 
 
# Function to convert a given number (max 9-digits) into words
def convert(n):

    result =  convertToDigit((n // 1000000000000000000000) % 1000, "Sextillion, ")

    result += convertToDigit((n // 1000000000000000000) % 1000, "Quintillion, ")

    result += convertToDigit((n // 1000000000000000) % 1000, "Quadrillion, ")

    result += convertToDigit((n // 1000000000000) % 1000, "Trillion, ")

    result += convertToDigit((n // 1000000000) % 1000, "Billion, ")
 
    result += convertToDigit((n // 1000000) % 1000, "Million, ")
 
    result += convertToDigit(((n// 1000) % 1000), "Thousand, ")
 
    result += convertToDigit(((n// 100) % 10), "Hundred ")
 
    if n > 100 and n % 100:
        result += "and "
 
    result += convertToDigit((n % 100), "")
    return result
 
 
# Python program to convert numbers to words
if __name__ == '__main__':
 
    EMPTY = ""
 
    X = [EMPTY, "One ", "Two ", "Three ", "Four ", "Five ", "Six ", "Seven ", "Eight ", "Nine ", "Ten ",
        "Eleven ", "Twelve ","Thirteen ", "Fourteen ", "Fifteen ", "Sixteen ","Seventeen ", "Eighteen ", "Nineteen "]
 
    Y = [EMPTY, EMPTY, "Twenty ", "Thirty ", "Forty ", "Fifty ","Sixty ", "Seventy ", "Eighty ", "Ninety "]

    print(convert(1)) 
    print(convert(99))
    print(convert(966))
    print(convert(6004))
    print(convert(985632))
    print(convert(23985632))
    print(convert(997751076))
    print(convert(8123985632))
    print(convert(199775107060))
    print(convert(512598123985632))
    print(convert(sys.maxsize))