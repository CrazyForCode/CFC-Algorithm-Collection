#include <stdio.h>
#include <string.h>
#define MAXLEN 70

char ss;
char plaintext[MAXLEN], ciphertext[MAXLEN];
int plaincode[MAXLEN], ciphercode[MAXLEN];
int i, temp, len, key, select;


void inputText(char * f_text);
void outputText(char * f_text);
void encryption();
void deciphering();

int main(){
	printf("请输入加密关键字：");
	scanf("%d", &key);

	while (1){
		printf("请问需要进行加密还是解密？退出请输入 0\n");
		printf("加密请输入 1，解密请输入 -1 「文本以 0 结束」\n");
		scanf("%d", &select);
		fflush(stdin);
		if (select == 1){
			inputText(plaintext);
			encryption();
			outputText(ciphertext);
		}else if (select == -1){
			inputText(ciphertext);
			deciphering();
			outputText(plaintext);
		}else if (select == 0){
			break;
		}
	}
	return 0;
}

void inputText(char * f_text){
	for (i = 0; (*(f_text + i) = getchar()) != '0'; i++);
	*(f_text + i) = '\0';
	len = strlen(f_text);
}

void outputText(char * f_text){
	for (i = 0; i < len; ++i){
		printf("%c", *(f_text + i));
	}
	printf("\n");
}


void encryption(){
	for (i = 0; i < len; ++i){
		if (*(plaintext + i) == '_'){
			*(plaincode + i) = 0;
		}
		else if (*(plaintext + i) == '.'){
			*(plaincode + i) = 27;
		}
		else{
			*(plaincode + i) = (int)(*(plaintext + i)) - 96;
		}
	}

	for (i = 0; i < len; ++i){
		temp = *(plaincode + key * i % len) - i;
		while (temp < 0){
			temp += 28;
		}
		*(ciphercode + i) = temp % 28;
	}

	for (i = 0; i < len; ++i){
		if (*(ciphercode + i) == 0){
			*(ciphertext + i) = '_';
		}else if (*(ciphercode + i) == 27){
			*(ciphertext + i) = '.';
		}else{
			*(ciphertext + i) = *(ciphercode + i) + 96;
		}
	}

}

void deciphering(){
	for (i = 0; i < len; ++i){
		if (*(ciphertext + i) == '_'){
			*(ciphercode + i) = (*(ciphertext + i) - 95 + i) % 28;
		}else if (*(ciphertext + i) == '.'){
			*(ciphercode + i) = (*(ciphertext + i) - 47 + i) % 28;
		}else{
			*(ciphercode + i) = (*(ciphertext + i) - 96 + i) % 28;
		}

		temp = key * i % len;
		*(plaincode + key * i % len) = *(ciphercode + i);

		if (*(plaincode + temp) == 0){
			*(plaintext + temp) = *(plaincode + temp) + 95;
		}else if (*(plaincode + temp) == 27){
			*(plaintext + temp) = *(plaincode + temp) + 19;
		}else{
			*(plaintext + temp) = *(plaincode + temp) + 96;
		}
	}

	*(plaintext + len) = '\0';

}