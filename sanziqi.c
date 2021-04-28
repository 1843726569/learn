#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
//创建棋盘并初始化
#define MAX_ROW 3
#define MAX_COL 3
void init(char chess[MAX_ROW][MAX_COL]){
	for (int row = 0; row < MAX_ROW; row++){
		for (int col = 0; col < MAX_COL; col++){
			chess[row][col] = ' ';
		}
	}
}
//打印棋盘
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
//玩家落子
void playerMove(char chessBoard[MAX_ROW][MAX_COL]){
	while (1){
		printf("请落子（row col)\n");
		int row = 0;
		int col = 0;
		scanf("%d %d", &row, &col);//录入玩家落子信息
		if (row >= MAX_ROW || row < 0 || col < 0 || col >= MAX_COL){
			printf("落子错误，请重新落子:\n");
			continue;
		}//判断玩家落子的合法性。
		else if (chessBoard[row][col] != ' '){
			printf("您输入的位置已经有棋子，请重新输入：\n");
			continue;
		}//判断该位置是否已有棋子。
		else{
			chessBoard[row][col] = 'x';
			break;
		}//最终落子位置。
	}
}
//电脑落子
void computerMove(char chessBoard[MAX_ROW][MAX_COL]){
	while (1){
		int row = rand() % MAX_ROW;
		int col = rand() % MAX_COL;
		if (chessBoard[row][col] != ' '){
			continue;
		}//已落子，更换位置。
		chessBoard[row][col] = '0';
		break;
	}
}
//判断棋盘是否已满，如果满输出0，没满输出1.
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
//判断谁获胜，可以约定如果返回‘x'玩家获胜
//如果返回‘0'电脑获胜
//返回‘ ’则表示还未结束
//返回 ’s'表示和棋
char isGameover(char chessBoard[MAX_ROW][MAX_COL]){
	for (int row = 0; row < MAX_ROW; row++){
		if (chessBoard[row][0] != ' '&& chessBoard[row][0] == chessBoard[row][1] && chessBoard[row][0] == chessBoard[row][2]){
			return chessBoard[row][0];
		}
	}//扫描所有行
	for (int col = 0; col < MAX_COL; col++){
		if (chessBoard[0][col] != ' '&& chessBoard[0][col] == chessBoard[1][col] && chessBoard[0][col] == chessBoard[2][col]){
			return chessBoard[0][col];
		}
	}//扫描所有列
	if (chessBoard[0][0] != ' '&& chessBoard[0][0] == chessBoard[1][1] && chessBoard[0][0] == chessBoard[2][2]){
		return chessBoard[0][0];
	}
	if (chessBoard[0][2] != ' '&& chessBoard[0][2] == chessBoard[1][1] && chessBoard[0][2] == chessBoard[2][0]){
		return chessBoard[0][2];
	}//扫描斜行
	if (isFull(chessBoard)){
		return 's';
	}//判断是否和棋
	return ' ';
}
//前面函数的调用
int main(){
	char chessBoard[MAX_ROW][MAX_COL];
	init(chessBoard);
	char winner = ' ';
	while (1){
		print(chessBoard);//打印棋盘
		playerMove(chessBoard);//玩家落子
		winner = isGameover(chessBoard);
		if (winner != ' '){
			//游戏结束"
			break;
		}
		computerMove(chessBoard);//电脑落子
		winner = isGameover(chessBoard);
		if (winner != ' '){
			//游戏结束
			break;
		}
	}
	//输出最终结果。
	if (winner = 'x'){
		printf("恭喜你，你赢了！\n");
	}
	else if (winner = '0'){
		printf("蠢，你输了！\n");
	}
	else{
		printf("和棋！\n");
	}
	return 0;
}