
import sys
sys.path.append("../Array")
sys.path.append("../LinkedList")




import myarray
import linkedlist


class Queue :
    def __init__(self, size=20) :
        self.m_arr = myarray.Arr(size)
        for i in range(size) :
            self.m_arr.Append(0)

        self.m_head, self.m_tail = 0, 0
        self.m_num = size

    def Enqueue(self, value) :
        if self.m_tail == self.m_num and self.m_head == 0 :
            return False

        if self.m_tail == self.m_num and self.m_head != 0 :
            for i in range(self.m_head, self.m_tail) :
                self.m_arr[i-self.m_head] = self.m_arr[i]

            self.m_tail = self.m_tail - self.m_head
            self.m_head = 0


        self.m_arr[self.m_tail] = value
        self.m_tail = self.m_tail + 1
        return True

    def Dequeue(self) :
        if self.m_head == self.m_tail :
            return False

        #res = self.m_arr[self.m_head]
        self.m_head = self.m_head + 1
        return True


    
    def Print(self) :
        for i in range(self.m_head, self.m_tail) :
            print(self.m_arr[i])



class LinkedQueue :
    def __init__(self) :
        self.m_head = None
        self.m_tail = None

    def Enqueue(self, value) :
        new_node = linkedlist.LinkedNode(value)
        if self.m_tail :
            self.m_tail.next = new_node
        else :
            self.m_head = new_node

        self.m_tail = new_node
        return True

    def Dequeue(self) :
        if not self.m_head :
            return False

        self.m_head = self.m_head.next
        if not self.m_head :
            self.m_tail = None

        return True

    def Print(self) :
        val = []
        p = self.m_head
        while p :
            val.append(p.data)
            p = p.next

        print(val)



class RingQueue :
    def __init__(self, size = 20) :
        self.m_arr = myarray.Arr(size)
        for i in range(size) :
            self.m_arr.Append(None)

        self.m_num = size
        self.m_head, self.m_tail = 0, 0

    def Enqueue(self, value) :
        if (self.m_tail + 1) % self.m_num == self.m_head :
            return False

        self.m_arr[self.m_tail] = value
        self.m_tail = (self.m_tail + 1) % self.m_num
        return True


    def Dequeue(self) :
        if self.m_head == self.m_tail :
            return False

        # res = self.m_arr[self.m_head]
        self.m_head = (self.m_head + 1) % self.m_num
        return True

    
    def Print(self) :
        if self.m_head == self.m_tail :
            return
        
        val = []
        pos = self.m_head
        while pos != self.m_tail :
            val.append(self.m_arr[pos])
            pos = (pos + 1) % self.m_num

        print(val)



if __name__ == "__main__" :

    q = RingQueue(5)
    q.Enqueue(1)
    q.Enqueue(2)
    q.Enqueue(3)
    q.Enqueue(4)
    q.Enqueue(5)
    
    q.Dequeue()
    q.Dequeue()
    q.Dequeue()

    q.Enqueue(6)
    q.Enqueue(7)


    q.Print()

