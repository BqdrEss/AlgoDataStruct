import math
def counting_sort(arr):
    lst = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    for i in range(len(arr)):
        lst[arr[i]] += 1
    for i in range(1, len(lst)):
        lst[i] += lst[i-1]
    lst2 = []
    for w in range(len(arr)):
        lst2.append(0)
    for i in range(len(arr)):
        lst[arr[i]] -= 1
        lst2[lst[arr[i]]] = arr[i]
    return lst2


def insertionSort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key

def bucket_sort(arr):
    max_value = max(arr)
    size = max_value/len(arr)

    # Create n empty buckets where n is equal to the length of the input list
    buckets_list= []
    for x in range(len(arr)):
        buckets_list.append([]) 

    # Put list elements into different buckets based on the size
    for i in range(len(arr)):
        j = int (arr[i] / size)
        if j != len (arr):
            buckets_list[j].append(arr[i])
        else:
            buckets_list[len(arr) - 1].append(arr[i])

    # Sort elements within the buckets using Insertion Sort
    for z in range(len(arr)):
        insertionSort(buckets_list[z])
            
    # Concatenate buckets with sorted elements into a single list
    final_output = []
    for x in range(len (arr)):
        final_output = final_output + buckets_list[x]
    return final_output

    
    


lst1 = [9, 1, 6, 7, 6, 2, 1]
print(bucket_sort(lst1))
lst2 = [0.9, 0.1, 0.6, 0.7, 0.6, 0.3, 0.1]
print(bucket_sort(lst2))
lst3 = ['word','category','cat','new','news','world','bear', 'at','work', 'time']