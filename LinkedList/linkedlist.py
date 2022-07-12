class LinkedNode :
    def __init__(self, data) :
        self.m_data = data
        self.m_next = None

    @property
    def data(self) :
        return self.m_data

    @data.setter
    def data(self, value) :
        self.m_data = value

    @property
    def next(self) :
        return self.m_next

    @next.setter
    def next(self, value) :
        self.m_next = value


class SingleLinkedList :
    def __init__(self) :
        self.m_head = None

    def Insert(self, value) :
        new_node = LinkedNode(value)
        new_node.next = self.m_head
        self.m_head = new_node

    def FindByValue(self, value) :
        p = self.m_head
        while p and p.data != value :
            p = p.next

        return p

    def FindByIndex(self, index) :
        p = self.m_head
        pos = 0
        while p and pos != index :
            p = p.next
            pos += 1

        return p
            
    def DeleteByValue(self, value) :
        if self.m_head == None :
            return False

        if self.m_head.data == value :
            self.m_head = self.m_head.next
            return True

        prev = self.m_head
        p = self.m_head.next
        while p :
            if p.data == value :
                prev.next = p.next
                return True

            prev = p
            p = p.next

        return False

    def DeleteByIndex(self, index) :
        if self.m_head == None or index < 0 :
            return False

        if index == 0 :
            self.m_head = self.m_head.next
            return True

        prev = self.m_head
        p = self.m_head.next
        pos = 0
        while p :
            if pos == index :
                prev.next = p.next
                return True

            prev = p
            p = p.next
            pos += 1

        return False
        
    def Print(self) :
        if self.m_head == None :
            return

        p = self.m_head
        while p :
            print(p.data)
            p = p.next

        return


class CLinkedList :
    def __init__(self) :
        self.m_tail = None

    def Insert(self, value) :
        new_node = LinkedNode(value)
        if self.m_tail == None :
            self.m_tail = new_node
            new_node.next = self.m_tail
            return

        new_node.next = self.m_tail.next
        self.m_tail.next = new_node
        self.m_tail = new_node

    def FindByValue(self, value) :
        p = self.m_tail
        while p and p.data != value :
            p = p.next
            if p == self.m_tail :
                break

        return p

    def DeleteByValue(self, value) :
        if self.m_tail == None :
            return False

        if self.m_tail == self.m_tail.next :
            if self.m_tail.data == value :
                self.m_tail = None
                return True
            else :
                return False

        prev = self.m_tail
        p = self.m_tail.next
        while p != self.m_tail :
            if p.data == value :
                prev.next = p.next
                return True

            prev = p
            p = p.next

        return False

    #def FindByIndex(self, index) :

    #def DeleteByIndex(self, index) :

    def Print(self) :
        if self.m_tail == None :
            return

        p = self.m_tail
        while p :
            print(p.data)
            p = p.next
            if p == self.m_tail :
                break

        return



if __name__ == "__main__" :

    list = CLinkedList()

    list.Insert(2)
    list.Insert(51)
    list.Insert(223)
    list.Insert(98)
    list.Insert(13)

    list.Print()


    list.DeleteByValue(223)

    list.Print()

    p = list.FindByValue(98)
    p.data = 100

    list.Print()


        
