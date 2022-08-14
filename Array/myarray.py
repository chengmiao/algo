class Arr :
    def __init__(self, capacity = 20) :
        if capacity < 0 :
            capacity = 0
        self._capacity = capacity
        self._size = 0
        self._data = [None] * capacity


    def __getitem__(self, index) :
        if index < 0 or index >= self._size :
            raise Exception("Index out of range")
        return self._data[index]

    def __setitem__(self, index, value) :
        if index < 0 or index >= self._size :
            raise Exception("Index is illegal")
        
        self._data[index] = value

    def Append(self, value) :
        if self._size == self._capacity :
            self._resize()

        self._data[self._size] = value
        self._size += 1

    def _resize(self) :
        print("Arr resize!")
        newarr = Arr(self._capacity * 2)
        for i in range(self._capacity) :
            newarr._data[i] = self._data[i]

        self._capacity = newarr._capacity
        self._data = newarr._data

    def print(self) :
        for i in range(self._size) :
            print(self._data[i], end = "\t")






class SortedArr :
    def __init__(self, capacity = 20) :
        if capacity < 0 :
            capacity = 0

        self._capacity = capacity
        self._size = 0
        self._data = [None] * capacity

    def __getitem__(self, index) :
        if index < 0 or index >= self._size :
            raise Exception("Index out of range")
        
        return self._data[index]

    def __setitem__(self, index, value) :
        if index < 0 or index >= self._size :
            raise Exception("Index is illegal")

        self._data[index] = value


    def Append(self, value) :
        if self._size == self._capacity :
            print("Sorted Array is Full")
            return

        # if self._size == 0 :
        #     self._data[self._size] = value
        #     self._size += 1
        #     return

        i = self._size - 1
        for i in reversed(range(self._size)) :
            if value < self._data[i] :
                self._data[i+1] = self._data[i]
            else :
                break

        self._data[i+1] = value
        self._size += 1


    def Delete(self, index) :
        if index < 0 or index >= self._size :
            raise Exception("Index out of range")

        for i in range(index+1, self._size, 1) :
            self._data[i-1] = self._data[i]

        self._size -= 1

    def print(self) :
        for i in range(self._size) :
            print(self._data[i], end = "\t")


def ArrMerge(array1, array2) :
    newsize = array1._size + array2._size
    newarr = Arr(newsize)

    i, j = 0, 0
    while i < array1._size and j < array2._size :
        if array1[i] < array2[j] :
            newarr.Append(array1[i])
            i += 1
        elif array1[i] > array2[j] :
            newarr.Append(array2[j])
            j += 1
        else :
            newarr.Append(array1[i])
            newarr.Append(array2[j])
            i += 1
            j += 1

    if i < array1._size :
        for index in range(i, array1._size, 1) :
            newarr.Append(array1[index])
    elif j < array2._size :
        for index in range(j, array2._size, 1) :
            newarr.Append(array2[index])

    return newarr




if __name__ == "__main__" :

    '''
    array1 = Arr(20)
    array1.Append(1)
    array1.Append(2)
    array1.Append(3)
    array1.Append(4)


    array2 = Arr(10)
    array2.Append(1)
    array2.Append(2)
    array2.Append(3)
    array2.Append(4)


    newarr = ArrMerge(array1, array2)
    newarr.print()

    '''
    test = SortedArr(10)

    test.Append(2)
    test.Append(6)
    test.Append(4)
    test.Append(3)
    test.Append(10)
    test.print()

