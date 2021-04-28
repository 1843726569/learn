#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
//�������̲���ʼ��
#define MAX_ROW 3
#define MAX_COL 3
void init(char chess[MAX_ROW][MAX_COL]){
	for (int row = 0; row < MAX_ROW; row++){
		for (int col = 0; col < MAX_COL; col++){
			chess[row][col] = ' ';
		}
	}
}
//��ӡ����
void print(char chess[MAX_ROW][MAX_COL]){
	printf("+--+--+--+\n");
	for (int row = 0; row < MAX_ROW; row++){
		printf("|");
		for (int col = 0; col < MAX_COL; col++){
			printf("%c |", chess[row][col]);
		}
		printf("\n+--+--+--+\n");
	}
}
//�������
void playerMove(char chessBoard[MAX_ROW][MAX_COL]){
	while (1){
		printf("�����ӣ�row col)\n");
		int row = 0;
		int col = 0;
		scanf("%d %d", &row, &col);//¼�����������Ϣ
		if (row >= MAX_ROW || row < 0 || col < 0 || col >= MAX_COL){
			printf("���Ӵ�������������:\n");
			continue;
		}//�ж�������ӵĺϷ��ԡ�
		else if (chessBoard[row][col] != ' '){
			printf("�������λ���Ѿ������ӣ����������룺\n");
			continue;
		}//�жϸ�λ���Ƿ��������ӡ�
		else{
			chessBoard[row][col] = 'x';
			break;
		}//��������λ�á�
	}
}
//��������
void computerMove(char chessBoard[MAX_ROW][MAX_COL]){
	while (1){
		int row = rand() % MAX_ROW;
		int col = rand() % MAX_COL;
		if (chessBoard[row][col] != ' '){
			continue;
		}//�����ӣ�����λ�á�
		chessBoard[row][col] = '0';
		break;
	}
}
//�ж������Ƿ���������������0��û�����1.
int isFull(char chessBoard[MAX_ROW][MAX_COL]){
	for (int row = 0; row < MAX_ROW; row++){
		for (int col = 0; col < MAX_COL; col++){
			if (chessBoard[row][col] == ' '){
				return 1;
			}
		}
	}
	return 0;
}
//�ж�˭��ʤ������Լ��������ء�x'��һ�ʤ
//������ء�0'���Ի�ʤ
//���ء� �����ʾ��δ����
//���� ��s'��ʾ����
char isGameover(char chessBoard[MAX_ROW][MAX_COL]){
	for (int row = 0; row < MAX_ROW; row++){
		if (chessBoard[row][0] != ' '&& chessBoard[row][0] == chessBoard[row][1] && chessBoard[row][0] == chessBoard[row][2]){
			return chessBoard[row][0];
		}
	}//ɨ��������
	for (int col = 0; col < MAX_COL; col++){
		if (chessBoard[0][col] != ' '&& chessBoard[0][col] == chessBoard[1][col] && chessBoard[0][col] == chessBoard[2][col]){
			return chessBoard[0][col];
		}
	}//ɨ��������
	if (chessBoard[0][0] != ' '&& chessBoard[0][0] == chessBoard[1][1] && chessBoard[0][0] == chessBoard[2][2]){
		return chessBoard[0][0];
	}
	if (chessBoard[0][2] != ' '&& chessBoard[0][2] == chessBoard[1][1] && chessBoard[0][2] == chessBoard[2][0]){
		return chessBoard[0][2];
	}//ɨ��б��
	if (isFull(chessBoard)){
		return 's';
	}//�ж��Ƿ����
	return ' ';
}
//ǰ�溯���ĵ���
int main(){
	char chessBoard[MAX_ROW][MAX_COL];
	init(chessBoard);
	char winner = ' ';
	while (1){
		print(chessBoard);//��ӡ����
		playerMove(chessBoard);//�������
		winner = isGameover(chessBoard);
		if (winner != ' '){
			//��Ϸ����"
			break;
		}
		computerMove(chessBoard);//��������
		winner = isGameover(chessBoard);
		if (winner != ' '){
			//��Ϸ����
			break;
		}
	}
	//������ս����
	if (winner = 'x'){
		printf("��ϲ�㣬��Ӯ�ˣ�\n");
	}
	else if (winner = '0'){
		printf("���������ˣ�\n");
	}
	else{
		printf("���壡\n");
	}
	return 0;
}