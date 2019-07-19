#include <stdio.h>

int binary_search(int arr[], int size, int item){
	int start = 0;
	int end = size;

	while(start < end){
		int midle = (end - start) / 2;
		int quess = arr[midle];

		if(quess == item){
			return midle;
		}
		if(quess < item){
			start = midle;
		}
		else{
			end = midle;
		}

	}
}

void test(){
	int mas[5] = {0,3,27,50,122};
	printf("0-3-27-50-122\nindex of three: %d\n", binary_search(mas, 5, 3));
}

int main(int argc, char const *argv[]){
	test();
	return 0;
}