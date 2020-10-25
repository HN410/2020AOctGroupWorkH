#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAX_DEPTH 4
#define MAX_MOVE_N 24
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

int alphabeta(const int board[5][5], int turn, int aiColor ,int depth,
     int alpha, int beta, char outputMove[]){
    //alphabeta法に基づくAI
    //
    //board 現在の盤面
    //turn 現在の手番の人の石の色
    //aiColor AIの石の色
    //depth 現在のゲーム木の深さ。根は0
    //alpha, beta alphabeta法の引数
    //outputMove 出力する手の文字列
    
    if(depth == MAX_DEPTH) //ノードが葉
         return getEvaluationValue(board);
    char moveList[MAX_MOVE_N][4] = {""};
    getMoveList(board, turn, moveList);

    int ansIndex = 0;
    int ansV = MAX_EVALUATION_V * turn * (-1);

    for(int i = 0; moveList[i][0] !='\0' && i < MAX_MOVE_N; i++){
        int nextBoard[5][5];
        getBoard(moveList[i], board, nextBoard);

        int v = alphabeta(nextBoard, -1 * turn, aiColor, depth + 1, 
                        alpha , beta, outputMove);// ノードの評価値

        if(turn == aiColor){
            if(v >= beta){//beta切り
                ansIndex = i;
                ansV = v;
                break;
            }else if(ansV < v){//より良い値が見つかったらalpha更新
                ansIndex = i;
                ansV = v;
                alpha = v;
            }
        }else{
            if(v <= alpha){//alpha切り
                ansIndex = i;
                ansV = v;
                break;
            }else if (ansV > v){//より良い値が見つかったらbeta更新
                ansIndex = i;
                ansV = v;
                beta = v;                
            }
        }
    }
    if(depth == 0) strcpy(outputMove, moveList[ansIndex]);//根なら次の手を文字化して出力
    return ansV;
}

void getMove(const int board[5][5], int ai, char move[4]){
    //board ... 盤面
    //player ...AIの色（黒石か白石か）
    //move ...出力する指し手
    alphabeta(board, ai, ai, 0, -MAX_EVALUATION_V, MAX_EVALUATION_V, move);
}

void getMoveList(const int board[5][5], const int player, char moveList[MAX_MOVE_N][4]){
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