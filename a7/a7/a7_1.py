import time
from random import randrange
import math

def swap(A,a,b):
    A[a],A[b] = A[b],A[a]

def Lomuto_partition(A, p, q):
    x = A[q]

    i = p - 1
    for j in range(p, q):
        if A[j] < x:
            i += 1
            temp = A[i]
            A[i] = A[j]
            A[j] = temp
    temp = A[i + 1]
    A[i + 1] = A[q]
    A[q] = temp
    return i + 1

def Hoare_Partition(A,p,r):
  x = A[p]
  i = p-1
  j = r+1
  while True:
    i+=1
    while A[i]<x:
      i += 1
    j-=1
    while A[j]>x:
      j-=1
    if i >= j:
      return j
    A[i], A[j] = A[j], A[i]


def Med_Partition(A,p:int,q:int):
    f=q-p-1
    m = math.floor(f/2)
    m = m + p
    left = p + 1
    if (A[m]-A[q-1])*(A[p]-A[m]) >= 0:
       swap(A,p,m)
    elif (A[q - 1] - A[m]) * (A[p] - A[q - 1]) >= 0:
        swap(A,p,q - 1)
    x = A[p]
    for right in range(p,q):
        if x > A[right]:
            swap(A,left,right)
            left = left + 1
    swap(A,p,left-1)
    return left-1

def Lomuto_quicksort(A, p, q):
    if p < q:
        piv = Lomuto_partition(A, p, q)
        Lomuto_quicksort(A, p, piv-1 )
        Lomuto_quicksort(A, piv + 1, q)
    return A

def Hoare_quicksort(A, p, q):
    if p < q:
        piv = Hoare_Partition(A, p, q)
        Hoare_quicksort(A, p, piv )
        Hoare_quicksort(A, piv + 1, q)
    return A  

def Med_quicksort(A, p, q):
     if p < q:
         piv = Med_Partition(A, p, q)
         Med_quicksort(A, p, piv)
         Med_quicksort(A,piv+1, q)  

def Lquicksort(A):
    return Lomuto_quicksort(A, 0, len(A) - 1)
    
def Hquicksort(A):
    return Hoare_quicksort(A, 0, len(A) - 1) 

def Mquicksort(A):
    return Med_quicksort(A, 0, len(A) - 1)   

c=0
ASize=1000
t1,t2,t3=0,0,0
while (c<1000):
  L1=[ASize]
  L2=[ASize]
  L3=[ASize]
  for i in range(ASize):
    x=randrange(10000)
    L1.append(x)
    L2.append(x)
  t0 = time.perf_counter() 
  Lquicksort(L1)
  t1 += (time.perf_counter() - t0)
  t0 = time.perf_counter() 
  Hquicksort(L2)
  t2 += (time.perf_counter() - t0)
  t0 = time.perf_counter() 
  Mquicksort(L2)
  t3 += (time.perf_counter() - t0)
  c+=1
print ('Average time for Lomuto partition:  ' ,t1/c)
print ('Average time for Hoare partition: ' ,t2/c)
print ('Average time for Median partition:  ' ,t3/c)