#include <stdio.h>
#include <math.h>
#define MAX_DEPTH 4
#define MAX_EVALUATION_V 10000
#define BLACK -1
#define WHITE 1

void getBoard(const char[], const int inputBoard[5][5], int outputBoard[5][5]);
void getMove(const int board[5][5], char move[4]);
void getMoveList(const int board[5][5], const int player, char moveList[24][4]);
int getEvaluationValue(const int board[5][5]);
int hasWon(const int board[5][5]);



void getBoard(const char input[], const int inputBoard[5][5],
 int outputBoard[5][5]){
    //input ...入力文字列
    //inputBoard ...元の盤面
    //outputBoard ...出力する盤面
}

int alphabeta(const int board[5][5], int turn ,int depth,
     int alpha, int beta, char move[]){
         if(depth == MAX_DEPTH) 
         return getEvaluationValue(board);
    char moveList[24][4] = {""};
    getMoveList(board, )




}

void getMove(const int board[5][5], int ai, char move[4]){
    //board ... 盤面
    //player ...AIの色（黒石か白石か）
    //move ...出力する指し手
    alphabeta(board, 1, 0, -MAX_EVALUATION_V, MAX_EVALUATION_V, move);
}

void getMoveList(const int board[5][5], const int player, char moveList[24][4]){
    //board ...盤面
    //player どっちの手番か　黒の番なら-1, 白の番なら1
    //moveList ...可能な指し手のリストの出力、可能な手が24個以上無いときはNUll文字列で埋める
}

int getEvaluationValue(const int board[5][5]){
    //board ...盤面
    //出力は評価値

}

int hasWon(const int board[5][5]){
    //board ...盤面
    //盤面の勝敗が決まっていれば1を返し、そうでなければ0を返す
}

int main(){

    return 0;
}