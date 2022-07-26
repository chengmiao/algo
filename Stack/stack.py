import sys
sys.path.append("../Array")

import myarray


class Stack :
    def __init__(self, capacity = 20) :
        self.m_arr = myarray.Arr()

    def Push(self, value) :
        self.m_arr.Append(value)

    def Pop(self) :
        return

    def Print(self) :
        self.m_arr.print()


if __name__ == "__main__" :
    test = Stack()
    test.Push(2)
    test.Push(3)


    test.Print()