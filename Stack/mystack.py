import sys
sys.path.append("../Array")
sys.path.append("../LinkedList")


import myarray
import linkedlist


class Stack :
    def __init__(self, capacity = 20) :
        self.m_arr = myarray.Arr(capacity)
        for i in range(capacity) :
            self.m_arr.Append(None)
        self.m_top = 0
        self.m_num = capacity

    def Push(self, value) :
        if self.m_top == self.m_num :
            self.m_arr.Append(None)
            self.m_num = self.m_arr._capacity

        self.m_arr[self.m_top] = value
        self.m_top += 1

    def Pop(self) :
        if self.m_top <= 0 :
            return

        self.m_top -= 1
        return self.m_arr[self.m_top]

    def Print(self) :
        for i in range(self.m_top) :
            print(self.m_arr[i])



class LinkedStack :
    def __init__(self) :
        self.m_list = linkedlist.SingleLinkedList()

    def Push(self, value) :
        self.m_list.Insert(value)
        return

    def Pop(self) :
        val = self.m_list.FindeByIndex(0)
        self.m_list.DeleteByIndex(0)
        return val

    def Print(self) :
        self.m_list.Print()
        return






if __name__ == "__main__" :
    test = Stack(1)
    test.Push(1)
    test.Push(2)
    test.Push(3)
    test.Pop()
    test.Pop()

    test.Print()

    test.Push(4)
    test.Push(5)

    test.Print()

    '''
    test1 = LinkedStack()
    test1.Push(1)
    test1.Push(2)
    test1.Push(3)
    test1.Pop()

    test1.Print()
    '''