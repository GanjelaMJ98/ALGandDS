def binary_search(mas,item):
	start = 0
	end = len(mas)-1
	while(start < end):
		mid = int((start + end) / 2)
		quess = mas[mid]
		if(quess == item):
			return mid
		if(quess < item):
			start = mid
		else:
			end = mid
	return None

def main():
	l = [0,1,2,3,4,5]
	a = 2
	n = -1
	print(l)
	print("BS(2):")
	print(binary_search(l,a))

	print("BS(-1):")
	print(binary_search(l,n))

if __name__ == '__main__':
	main()

