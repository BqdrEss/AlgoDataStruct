import time
from random import randrange

def dual_pivot_sort(list, start, top):
    if top <= start:
        return
    p = start
    q = top
    k = p+1
    h = k
    l = q-1
    if list[p] > list[q]:
        list[p], list[q] = list[q], list[p]
    while k <= l: 
    # the last non-check index is l,as l+1 to top - 1 is the part III,              
    #where all elements > list[top] 
        if list[k] < list[p]:
            list[h], list[k] = list[k], list[h]
            #h is the first element of part II
            h += 1 
            #increase h by 1, for pointing to the first element of part II
            k += 1 
            #increase k by 1, because we have checked list[k]
        elif list[k] > list[q]:
        #l is the last element of part IV
            list[k], list[l] = list[l], list[k]
            #don't increase k, as we have not check list[l] yet
            l -= 1 
            #after swap, we should compare list[k] with list[p] and list[q] again
        else: k += 1
        # no swap, then the current k-th value is in part II, thus we plus 1 to k
    h -= 1#now,h is the last element of part I
    l += 1 #now, l is the first element of part III
    list[p], list[h] = list[h], list[p]
    list[q], list[l] = list[l], list[q]
    dual_pivot_sort(list, start, h-1)
    dual_pivot_sort(list, h+1, l-1)
    dual_pivot_sort(list, l+1, top)

def Dquicksort(A):
    return dual_pivot_sort(A, 0, len(A) - 1)

c=0
ASize=1000
t1,t2,t3=0,0,0
while (c<10):
    L1=[ASize]
    L2=[ASize]
    L3=[ASize]
    L=[]
    for i in range(ASize):
        x=randrange(100)
        L.append(x)
        L2.append(x)
    Dquicksort(L)
    for i in L:
        L1.append(i)
    for j in range(ASize-1,0,-1):
        L3.append(j)
  t0 = time.perf_counter()
  Dquicksort(L1)
  t1 += (time.perf_counter() - t0)
  t0 = time.perf_counter()
  Dquicksort(L2)
  t2 += (time.perf_counter() - t0)
  t0 = time.perf_counter()
  Dquicksort(L2)
  t3 += (time.perf_counter() - t0)
  print("Time for best",)
  c+=1