"""
Main module that call the `C` module `cmain`.
"""

import cmain

def addPy(a_list):
    return cmain.addList(a_list)


if __name__ == '__main__':
    print("Enter a series of numbers csv: ")
    t_input = input()
    print(t_input)
    s_args = t_input.split(',')
    i_args = [int(i) for i in s_args]
    print(i_args)
    print(addPy(i_args))
