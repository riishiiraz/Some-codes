class stack:
    def __init__(self) -> None:
        self.array = []
        self.top=-1


    def push(self, item):
        self.array.append(item)
        self.top+=1

    def pop(self):
        if(not self.isEmpty()):
            self.top-=1
        return self.array.pop()
    
    def peek(self):
        if(not self.isEmpty()):
            return self.array[self.top]
        return None
    
    def isEmpty(self):
        return (self.top<0)
    
    def precedence(self, opr):
        if opr in ['*','/']:
            return 3
        elif opr in ['+','-']:
            return 2
        return 0
    
    def isOperator(self,char):
        if(char in '*+/-'):
            return True
        return False
    
def solve(infix):
    stk = stack()
    postfix=""
    
    for char in infix:
        
        if(not stk.isOperator(char)):
            postfix+=char
        
        elif (stk.precedence(char)>stk.precedence(stk.peek())):
            stk.push(char)

        else:
            while (stk.precedence(stk.peek()) >= stk.precedence(char) ):
                postfix+=stk.pop()
            stk.push(char)

        #print(stk.array)

    while (not stk.isEmpty()):
        postfix+=stk.pop()

    return postfix


    
def main():
    #expr = "x-y/z-k*d"
    expr = "x+y*z-k"
    expr = "x-y/z-k*d"
    print("Postfix : %s"%solve(expr))

main()


