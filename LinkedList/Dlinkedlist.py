class DLinkedNode :
    def __init__(self, data) :
        self.m_prev = None
        self.m_data = data
        self.m_next = None


    @property
    def prev(self) :
        return self.m_prev

    @prev.setter
    def prev(self, value) :
        self.m_prev = value

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



class DLinkedList :
    def __init__(self) :
        self.m_head = None


    def Insert(self, value) :
        new_node = DLinkedNode(value)

        if self.m_head == None :
            self.m_head = new_node
            return

        self.m_head.prev = new_node
        new_node.next = self.m_head
        self.m_head = new_node


    def FindByValue(self, value) :
        p = self.m_head
        while p and p.data != value :
            p = p.next

        return p


    def DeleteByValue(self, value) :
        if self.m_head == None :
            return False

        if self.m_head.data == value :
            self.m_head = self.m_head.next
            if self.m_head :
                self.m_head.prev = None
            return True

        p = self.m_head
        while p :
            if p.data == value :
                prev = p.prev
            
                prev.next = p.next
                #prev = p.next.prev
                p.next.prev = prev
                return True

            p = p.next

        return False


    def Print(self) :
        p = self.m_head
        while p :
            print(p.data)
            p = p.next











































    