"""
Ex: 
i/p: {2,12,8,6,5,1,2,10,3,2} 
o/p:{12,12,10,10,10,2,10,10,3,2}
replace each element with the next element in the list which is larger than it.
"""

def find_next_smaller_elements(xs):
    ys=[-1 for x in xs]
    stack=[]
    for i,x in enumerate(xs):
        while len(stack)>0 and x>xs[stack[-1]]:
           ys[stack.pop()]=x
        stack.append(i)
    return ys
