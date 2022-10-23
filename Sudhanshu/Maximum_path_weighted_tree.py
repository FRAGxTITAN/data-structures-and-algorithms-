//Problem statement: Write a program to find the longest/maximum path in a weighted tree.
//This coding question was asked in one of the coding interview rounds.

#tree node
class node:
  def __init__(self, intVal, listPtr=None):
    self.intVal=intVal
    self.listPtr=listPtr

#find max path in weighted tree
def maxPath(root):
    if root:
      if not root.listPtr:
        return root.intVal
      else:
        return root.intVal+max([maxPath(i) for i in root.listPtr])

#create weighted tree
root=node(0,[node(4,[node(2)]),node(3,[node(4),node(2,[node(1)]),node(1)])])
 
#print maximum path of weighted tree
print(maxPath(root))
