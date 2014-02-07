def binary(data, target, start, end):
    if start >= end:
        return -1
    mid_index = (start + end) // 2
    mid_value = data[mid_index]
    if target == mid_value:
        return mid_index
    elif target < mid_value:
        return binary(data, target, start, mid_index-1)
    else:
        return binary(data, target, start+1, end)

