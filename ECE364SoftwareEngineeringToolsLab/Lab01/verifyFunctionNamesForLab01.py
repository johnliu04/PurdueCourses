#! /user/local/bin/python3.7

from inspect import getmembers, isfunction

# Define desired functions that should be present.
functionNames = ['calculateChain', 'searchForNumber', 'calculateTensor']

# Attempt to import the code, and fail otherwise.
try:
    import Lab01Module as student
except:
    print("-------------------------------")
    print("Unable to find expected file.")
    print("-------------------------------")
    print()
    exit(-1)
else:
    print("-------------------------------")
    print("Code file found and imported successfully.")
    print("-------------------------------")
    print()

# Obtain all functions in the code.
presentFunctions = [fnName for fnName, _ in getmembers(student, isfunction)]

# Check whether each function is present or missing, and print out the result.
for fnIndex, fnName in enumerate(functionNames):

    if fnName in presentFunctions:
        print('{}- Function "{}" located.'.format(fnIndex + 1, fnName))
    else:
        print('{}- =======> Unable to locate the function "{}".'.format(fnIndex + 1, fnName))
