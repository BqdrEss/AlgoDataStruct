def Sub_Finder(lst):
  temp=[1 for _ in range(len(lst))]
  for i in range(1,len(lst)):
    for j in range(i):
        if lst[i]>lst[j] and temp[i]<temp[j]+1:
            temp[i]=temp[j]+1
  temp2=[]
  for nim in range(1, max(temp)+1):
    for idx in range(len(temp)):
      if temp[idx] == nim:
        s = lst[idx]
    temp2.append(s)
  return temp2


lst=[8, 3, 6, 50, 10, 8, 100, 30, 60, 40, 80]
print(lst,Sub_Finder(lst))

