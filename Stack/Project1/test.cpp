#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

void bit_repeat(uint8_t* send, uint8_t idx, uint8_t c) {
	uint32_t repeat_c = 0;
	for (int i = 7; i >= 0; i--) {
		repeat_c = repeat_c << 3;
		// 1bit -> 3bit repetition code
		if (((c & (1 << i)) >> i) == 1)
		{
			repeat_c = repeat_c | 0x7;
		}
		else
		{
			repeat_c = repeat_c | 0x0;
		}
	}
	send[idx] = (repeat_c & 0x00FF0000) >> 16;
	send[idx + 1] = (repeat_c & 0x0000FF00) >> 8;
	send[idx + 2] = repeat_c & 0x000000FF;
}


uint8_t decodeRecvData(uint8_t* dataPtr)
{
	uint32_t temp = 0;
	uint8_t result = 0;
	for (int i = 0; i < 3; i++) {
		temp = temp << 8;
		temp = temp | dataPtr[i];
	}

	uint8_t temp_2 = 0;
	for (int i = 0; i < 8; i++) {
		temp_2 = temp & 7;
		temp = temp >> 3;

		//3비트에서 1과 0중 어떤게 더 많은지 확인
		int one = 0;
		int zero = 0;
		for (int j = 2; j >= 0; j--) {
			if ((temp_2 & (1 << j) >> j) == 1) {
				one++;
			}
			else { zero++; }
		}

		if (one > zero) {
			result = result | (1 << (i));
		}
		else {
			result = result | (0 << (i));
		}

	}

	return result;
}

int main(int argc, char** argv) {

	uint8_t* data = (uint8_t*)malloc(3 * sizeof(uint8_t));
	uint8_t* test = (uint8_t*)malloc(3 * sizeof(uint8_t));
	
	
	// w -> 0b01110111를 뻥튀기 한 다음 오류비트를 임의로 섞는다.
	// decodeRecvData()를 호출한 다음 출력했을 때 w가 제대로 나오면 오류가 해결이 된것이다.
	//000 111 111 111 000 111 111 111

	//맞는 데이터
	data[0] = 0b00011111;
	data[1] = 0b11110001;
	data[2] = 0b11111111;
	
	//오류 데이터
	test[0] = 0b01010111;
	test[1] = 0b11110101;
	test[2] = 0b11111101;
	
	uint8_t temp = decodeRecvData(data);
	printf("Original data : %c\n", temp);


	uint8_t temp_2 = decodeRecvData(test);
	printf("test data: %c\n", temp_2);

	free(data);
	free(test);
	
}