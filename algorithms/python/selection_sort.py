def min_item_index(arr):
	min_item = arr[0]
	min_index = 0
	for i in range(len(arr)):
		if arr[i] < min_item:
			min_item = arr[i]
			min_index = i
	return min_index

def selection_sort(arr):
	sorted_arr = list()
	for i in range(len(arr)):
		min_index = min_item_index(arr)
		sorted_arr.append(arr.pop(min_index))
	return sorted_arr

def main():
	my_list = [2,6,8,1,0,3,2,4,7,5]
	print(my_list)
	print(selection_sort(my_list))

if __name__ == '__main__':
 	main()