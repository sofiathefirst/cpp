from ctypes import *

ml= cdll.LoadLibrary("./libswp.so") 
swp=ml.swp
pchar=ml.pchar
add = ml.add
a=(22)
b=(34)
#swp(a,b)
pchar('asgd')
print a,b,add(102,3)
