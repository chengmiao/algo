import mystack



def SimulateBrowser() :
    forward = mystack.Stack()
    back = mystack.Stack()

    while True :
        action = input("Input your action : ")
        if action == "up" :
            val = forward.Pop()
            print(val)
            if val != None :
                back.Push(val)
        elif action == "down" :
            val = back.Pop()
            print(val)
            if val != None :
                forward.Push(val)
        else :
            back.Push(action)
    
    


SimulateBrowser()