import Dlinkedlist
import Linkedlist


def Reverse(list) :
    if list.m_head == None :
        return

    new_head = None
    node = list.FindByIndex(0)
    while list.m_head != None :
        list.DeleteByIndex(0)
        node.next = None
        node.next = new_head
        new_head = node
        node = list.FindByIndex(0)

    list.m_head = new_head
    return


def IsRing(list) :
    fast = list.m_head
    slow = list.m_head
    isring = False
    while fast and slow :
        slow = slow.next
        if fast.next != None :
            fast = fast.next.next
        else :
            fast = None
        
        if slow == fast and slow != None :
            isring = True
            break

    return isring


def FindMiddle(list) :
    fast = list.m_head
    slow = list.m_head

    while fast and slow :
        if fast.next :
            fast = fast.next.next
        else :
            fast = None

        if fast :
            slow = slow.next

    return slow

def Merge(list1, list2) :

    new_list = Linkedlist.SingleLinkedList()    
    while list1.m_head and list2.m_head :
        p = list1.FindByIndex(0)
        q = list2.FindByIndex(0)

        print(p.data)
        print(q.data)
        if p.data < q.data :
            list1.DeleteByIndex(0)
            new_list.Insert(p.data)
        elif p.data > q.data :
            list2.DeleteByIndex(0)
            new_list.Insert(q.data)
        else :
            list1.DeleteByIndex(0)
            list2.DeleteByIndex(0)
            new_list.Insert(p.data)
            new_list.Insert(q.data)

    while list1.m_head :
        new_list.Insert(list1.m_head.data)
        list1.DeleteByIndex(0)

    while list2.m_head :
        new_list.Insert(list2.m_head.data)
        list2.DeleteByIndex(0)

    return new_list



list = Linkedlist.SingleLinkedList()

list.Insert(2)
list.Insert(51)
list.Insert(223)
list.Insert(98)
list.Insert(13)

list.Print()

Reverse(list)

list.Print()


p = FindMiddle(list)
print(p.data)


list1 = Linkedlist.SingleLinkedList()

list1.Insert(1300)
list1.Insert(980)
list1.Insert(223)
list1.Insert(51)
list1.Insert(2)

list2 = Linkedlist.SingleLinkedList()

list2.Insert(5)
list2.Insert(4)
list2.Insert(3)
list2.Insert(2)
list2.Insert(1)


list = Merge(list1, list2)
Reverse(list)
list.Print()


node = Linkedlist.LinkedNode(1)
node.next = Linkedlist.LinkedNode(2)
node.next.next = Linkedlist.LinkedNode(3)
node.next.next.next = Linkedlist.LinkedNode(4)
node.next.next.next.next = node.next

list = Linkedlist.SingleLinkedList()
list.m_head = node

#list.Print()
print(IsRing(list))




