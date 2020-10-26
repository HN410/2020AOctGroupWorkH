#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAX_DEPTH 4
#define MAX_MOVE_N 24
#define MOVE_STR_N 5
#define BOARD_LEN 5
#define MAX_EVALUATION_V 10000
#define BLACK -1
#define WHITE 1

void getBoard(const char[], const int inputBoard[BOARD_LEN][BOARD_LEN],
     int outputBoard[BOARD_LEN][BOARD_LEN]);
void getMove(const int board[BOARD_LEN][BOARD_LEN], char move[MOVE_STR_N]);
void getMoveList(const int board[BOARD_LEN][BOARD_LEN],
     const int player, char moveList[MAX_MOVE_N][MOVE_STR_N]);
int getEvaluationValue(const int board[BOARD_LEN][BOARD_LEN]);
int hasWon(const int board[BOARD_LEN][BOARD_LEN]);

int max(int i, int j){ return i > j ? i: j;}
int min(int i, int j){ return i > j ? j : i;}

void getBoard(const char input[], const int inputBoard[BOARD_LEN][BOARD_LEN],
 int outputBoard[BOARD_LEN][BOARD_LEN]){
    //input ...入力文字列
    //inputBoard ...元の盤面
    //outputBoard ...出力する盤面
}

int alphabeta(const int board[BOARD_LEN][BOARD_LEN], int turn, int aiColor ,int depth,
     int alpha, int beta, char outputMove[]){
    //alphabeta法に基づくAI
    //
    //board 現在の盤面
    //turn 現在の手番の人の石の色
    //aiColor AIの石の色
    //depth 現在のゲーム木の深さ。根は0
    //alpha, beta alphabeta法の引数
    //outputMove 出力する手の文字列
    if(hasWon(board))
         return MAX_EVALUATION_V * (turn * aiColor);
    if(depth == MAX_DEPTH) //ノードが葉
         return getEvaluationValue(board);
    char moveList[MAX_MOVE_N][BOARD_LEN] = {""};
    getMoveList(board, turn, moveList);

    alpha = aiColor == turn ? -MAX_EVALUATION_V : alpha;
    beta = aiColor == turn ? beta : MAX_EVALUATION_V;

    int ansIndex = 0;
    int ansV = MAX_EVALUATION_V * turn * (-1);

    for(int i = 0; moveList[i][0] !='\0' && i < MAX_MOVE_N; i++){
        int nextBoard[BOARD_LEN][BOARD_LEN];
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

void getMove(const int board[BOARD_LEN][BOARD_LEN], int ai, char move[MOVE_STR_N]){
    //board ... 盤面
    //player ...AIの色（黒石か白石か）
    //move ...出力する指し手
    alphabeta(board, ai, ai, 0, -MAX_EVALUATION_V, MAX_EVALUATION_V, move);
}

void getMoveList(const int board[BOARD_LEN][BOARD_LEN], const int player, char moveList[MAX_MOVE_N][MOVE_STR_N]){
    //board ...盤面
    //player どっちの手番か　黒の番なら-1, 白の番なら1
    //moveList ...可能な指し手のリストの出力、可能な手が24個以上無いときはNUll文字列で埋める
}

int getPieceN(const int board[BOARD_LEN][BOARD_LEN], int direction, int color, int index){
    //boardのある行（列, 斜め方向）にcolorの石が何個あるかを返す
    //directionは0が縦, 1が横, 2が斜め(左上から右下）, 3が斜め（右上から左下）に対応
    //斜めのindexはdirection=2のとき、(0, 4)=0 (0, 0)=4, (4, 0) = 8
    //            direction=3のとき、(0, 0)=0 (0, 4) = 4 (4, 4)=8
    int res = 0;
    if(direction ==0){
        for(int i0 = 0; i0 < BOARD_LEN; i0++){
            if(board[i0][index] == color) res++;
        }
    }else if(direction == 1){
        for(int i1 = 0; i1 < BOARD_LEN; i1++){
            if(board[index][i1] == color) res++;
        }
    }else if(direction == 2){
        int i2, j2;
        i2 = max(index - BOARD_LEN + 1, 0);
        j2 = max(BOARD_LEN -1 -index, 0);
        for(; i2 < BOARD_LEN && j2 < BOARD_LEN;){
            if(board[i2++][j2++] == color) res++;
        }
    }else{
        int i3, j3;
        i3 = max(index-BOARD_LEN+1, 0);
        j3 = min(index, BOARD_LEN-1);
        for(; i3 < BOARD_LEN && j3 >= 0;){
            if(board[i3++][j3--] == color)res++;
        }
    }
    return res;
}
int getConnectedPieceN(const int board[BOARD_LEN][BOARD_LEN], int isCorrumn, int index, int color){
    //colorの石が２個以上ある行（列）で自分の石が繋がっているほどよい値を返す
    int res = 0;
    if(isCorrumn){
        for(int i = 0; i < BOARD_LEN-1; i++){
            res += board[i][index] * board[i + 1][index];
        }
    }
    else{
        for(int i = 0; i < BOARD_LEN -1; i++){
            res += board[index][i] * board[index][i+1];
        }
    }
    return res;
}

int getEvaluationValue(const int board[BOARD_LEN][BOARD_LEN]){
    //board ...盤面
    //出力は評価値



}

int hasWon(const int board[BOARD_LEN][BOARD_LEN]){
    //board ...盤面
    //盤面の勝敗が決まっていれば1を返し、そうでなければ0を返す
}

int main(){

    return 0;
}