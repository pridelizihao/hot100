def quick_sort(arr):
    if len(arr) <= 1:
        return arr
    pivot = arr[0]

    left = []
    middle = []
    right = []

    for num in arr:
        if num < pivot:
            left.append(num)
        elif num > pivot:
            right.append(num)
        else:
            middle.append(num)

    return quick_sort(left) + middle + quick_sort(right)

if __name__=="__main__":
    list1 = [1,4,6,8,3,7,3,7,3,7,4,7,3,6,3,6,3]
    list1 = quick_sort(list1)
    print(list1)