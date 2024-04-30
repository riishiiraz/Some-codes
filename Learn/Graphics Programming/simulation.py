import tkinter as tk

root = tk.Tk()

frameWidth = 400
frameHeight = 300
dotSize = 10
dropStep = 1
dotRefresh = 4

drops = dict()

frame = tk.Frame(root)
frame.config( width=frameWidth, height= frameHeight , bg = "#111")
frame.pack()

root.bind("<Motion>", lambda event : Sprinkle(event))

canvas = tk.Canvas(frame, width=frameWidth, height= frameHeight , bg = "#111")
canvas.pack()

def drop(object, x,y, ground = frameHeight):

    if(y>=ground):
        return
    
    y+=dropStep
    canvas.move(object, 0, dropStep)
    root.after(dotRefresh, lambda : drop(object ,x , y, ground))


def nearest(x, near):
    return (int(x/near)+1)*(near)

def Sprinkle(event):
    h,k = event.x,event.y
    
    h = nearest(h, 5)


    if(h not in drops):
        drops[h] = 0
    else:
        drops[h]+=1

    clr = int((h/frameWidth)*255) , int((k/frameHeight)*255) , 150
    # print(clr)
    clr = "#%02x%02x%02x"%clr

    object = canvas.create_rectangle( h+0,k+0,h+dotSize,k+dotSize, fill=clr,outline="" )


    drop(object ,h, k, frameHeight - (drops[h] * dotSize ) )


root.mainloop()