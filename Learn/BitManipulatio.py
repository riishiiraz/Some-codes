# 12:34 AM 16-Sep-23

class App:

    def binary(self , n:int , bits = 32):
        opt=""
        for x in range(bits-1,-1,-1):
            mask = 1<<x
            if (mask & n):
                opt+="1"
            else:
                opt+="0"
            if(x%8)==0:
                opt+=" "
        return opt


    def invertViaXor(self , num , pos):
        # toggle the bit of 'pos' position
        
        mask = 1<<pos

        return self.binary( mask ^ num)

    def setBit(self , num , pos):
        # Set the bit to '1' of 'pos' position

        mask = 1<<pos
        return self.binary(mask | num)

    def clearBit(self , num , pos):
        mask = ~(1<<pos)

        return self.binary(mask & num)

if __name__ == "__main__":
    pass
    app = App()

    num = 56
    print("Binary of %d:"%num)
    print(app.binary(num))

    pos = 5
    
    print("Invert %dth bit by Making : "%pos)
    print(app.invertViaXor(num , pos))

    pos = 2
    

    print("Setting %dth bit by Making : "%pos)
    print(app.setBit(num , pos))

    pos = 3

    print("Clearing %dth bit by Making : "%pos)
    print(app.clearBit(num , pos))
