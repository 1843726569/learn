#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//int main(){
//	int m = 0;
//	int n = 0;
//	int count = 0;
//	printf("请输入比较的数：\n");
//	scanf("%d %d", &m,&n);
//	for (int i = 31; i >= 0; i--){
//		if ((((m >> i) & 1) ^ ((n >> i) & 1)) == 1){
//			count++;
//		}
//	}
//	printf("不同位数为:%d\n",count);
//	system("pause");
//	return 0;
//}

//int main(){
//	int m = 0;
//	int i = 0;
//	printf("请输入：\n");
//	scanf("%d", &m);
//	printf("偶数位为：");
//	for (i = 31; i >= 1; i = i - 2){
//		printf("%d ", (m >> i) & 1);
//	}
//	printf("\n");
//	printf("奇数位为：");
//	for (i = 30; i >= 0; i = i - 2){
//		printf("%d ", (m >> i) & 1);
//	}
//	system("pause");
//	return 0;
//}
//int main(){
//	int m = 0; 
//	int count = 0;
//	printf("请输入：\n");
//	scanf("%d", &m);
//	for (int i = 31; i >= 0; i--){
//		if ((((m >> i) & 1)^1)==0){
//			count++;
//		}
//	}
//	printf("二进制中1的个数为：%d\n", count);
//	system("pause");
//	return 0;
//}

int main(){
	int m = 0;
	int n = 0;
	printf("请输入要交还的数：\n");
	scanf("%d %d", &m, &n);
	m = m ^ n;
	n = m ^ n;
	m = m ^ n;
	printf("交换后为m=%d,n=%d", m, n);
	system("pause");
	return 0;
}