#include "numTrans.h"

char numBase[36] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int i, j;
int isHightestNum = 1;
int haveDecimalNum = 0;
int haveIntegerNum = 0;

int main(){
	NUMBER number, resultNumber;
	int n, m;
	printf("请输入数字的进制类型：\n");
	scanf("%d", &n);
	fflush(stdin);
	//高精度数总是以位数从低到高排在数组里面，如有计算需要翻转，计算完毕再翻转回来，以免混乱。
	printf("请输入这个数：\n");
	if (!inputNum(&number, n)){
		printf("输入错误\n");
		return 0;
	}
	printf("请输入需要转换的进制类型：\n");
	scanf("%d", &m);
	transNum(&number, &resultNumber, n, m);
	printTheWholeNum(&resultNumber, m);
	return 0;
}

int inputNum(NUMBER * f_num, int f_n){
	char tempChar;
	short tempNum;
	*(f_num->s_integer) = 0;
	*(f_num->s_decimal) = 0;
	while ((tempChar = getchar()) != '\n'){	
		if (isHightestNum){
			if (tempChar == '0'){
				continue;
			}else{
				isHightestNum = 0;
			}
		}	
		if (!haveDecimalNum && tempChar == '.'){
			haveDecimalNum = 1;
		}
		if ((tempNum = charToNum(tempChar, f_n)) == -1){
			return 0;
		}
		if (haveDecimalNum){
			++(*(f_num->s_decimal));
			*(f_num->s_decimal + *(f_num->s_decimal)) = tempNum;
		}else{
			++(*(f_num->s_integer));
			*(f_num->s_integer + *(f_num->s_integer)) = tempNum;
		}
	}
	if (haveDecimalNum){
		numFlip(f_num->s_decimal);
	}
	
	if (*(f_num->s_integer) != 0){
		haveIntegerNum = 1;
		numFlip(f_num->s_integer);
	}
	return 1;
}

short charToNum(char f_c, int f_n){
	short tempNum;
	if (f_c >= 'a' && f_c <= 'z'){
		tempNum = (short)f_c - 'a' + 10;
	}else if (f_c >= 'A' && f_c <= 'Z'){
		tempNum = (short)f_c - 'A' + 10;
	}else if (f_c >= 48 && f_c <= 57){
		tempNum = (short)f_c - '0';
	}
	if (tempNum >= f_n){
		return -1;
	}else{
		return tempNum;
	}
}

void numFlip(short * f_num){
	short temp;
	for (i = 0; i < *f_num / 2; i++){
		temp = *(f_num + 1 + i);
		*(f_num + 1 + i) = *(f_num + *f_num - i);
		*(f_num + *f_num - i) = temp;
	}
}

void transNum(NUMBER * f_number, NUMBER * f_resultNumber, int f_n, int f_m){
	short f_tempNum[MAXSIZE];
	short f_num[MAXSIZE];
	//*f_tempNum = 0;
	*(f_resultNumber->s_decimal) = 0;
	*(f_resultNumber->s_integer) = 0;
	if (haveIntegerNum){
		for (j = 1; j <= *(f_number->s_integer); j++){
				*(f_tempNum - 1 + j) = *(f_number->s_integer + j);
		}
		int len = *(f_number->s_integer);
		while(len) {	//每一轮手动模拟除法
	        for(i = len - 1; i >= 1; --i) {
	        	*(f_tempNum + i - 1) += *(f_tempNum + i) % f_m * f_n;
				*(f_tempNum + i) /= f_m;
	        }
	        *(f_resultNumber->s_integer + ++(*(f_resultNumber->s_integer))) = *f_tempNum % f_m;
	        *f_tempNum /= f_m;
	        while(len > 0 && !*(f_tempNum + len - 1)){
	            len--;
	        }
	    }
	}
	if (haveDecimalNum){
		for (i = 0; i <= *(f_number->s_decimal); i++){
			*(f_num + i) = *(f_number->s_decimal + i);
		}
		*f_tempNum = *(f_number->s_decimal);
		int len = *f_tempNum, k = 0, s = 0, carry, flag = 1;  // k 如果进制转换死循环，用于控制小数点位数
		*(f_tempNum + len + 1) = 0;
		*(f_tempNum + len + 2) = 0;
		while (1){
			++k;
			for (i = 1; i <= len; i++){
				*(f_tempNum + i) = 0;
			}
			for (i = 1; i <= len; i++){
				*(f_tempNum + i) += *(f_num + i) * (f_m % 10);
				*(f_tempNum + i + 1) += *(f_tempNum + i) / 10;
				*(f_tempNum + i) %= 10;
			}
			for (i = 1; i <= len; i++){
				*(f_tempNum + i + 1) += *(f_num + i) * (f_m / 10);
				*(f_tempNum + i + 2) += *(f_tempNum + i + 1) / 10;
				*(f_tempNum + i + 1) %= 10;
			}	

			*(f_resultNumber->s_decimal + ++(*(f_resultNumber->s_decimal))) = *(f_tempNum + len + 1) + *(f_tempNum + len + 2) * 10;
			*(f_tempNum + len + 1) = 0;
			*(f_tempNum + len + 2) = 0;
			for (i = 0; i <= len; i++){
				*(f_num + i) = *(f_tempNum + i);
			}
			for (i = 1; i <= len; ++i){
				if (*(f_tempNum + i) != 0){
					flag = 0;
				}
			}
			if (flag){
				break;
			}
			flag = 1;
			if (k == 16){
				break;
			}
		}
		numFlip(f_resultNumber->s_decimal);
	}

}

void printNum(short * f_num){
	for (i = *f_num; i >= 1; i--){
		printf("%c", *(numBase + *(f_num + i)));
	}
}

void printTheWholeNum(NUMBER * f_num, int f_m){
	if (f_m == 16){
		printf("0x");
	}else if (f_m == 8){
		printf("0");
	}
	if (*(f_num->s_integer)){
		printNum(f_num->s_integer);
	}else{
		printf("0");
	}
	if (*(f_num->s_decimal)){
		printf(".");
		printNum(f_num->s_decimal);
	}
	printf("\n");
}