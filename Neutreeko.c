#include <stdio.h>

void getBoard(const char input[], const int inputBoard[5][5],
 int outputBoard[5][5]){
    //input ...入力文字列
    //inputBoard ...元の盤面
    //outputBoard ...出力する盤面
}

void getMove(const int board[5][5], char move[4]){
    //board ... 盤面
    //move ...出力する指し手
}

void getMoveList(const int board[5][5], const int player, char moveList[][4]){
    //board ...盤面
    //player どっちの手番か　黒の番なら-1, 白の番なら1
    //moveList ...可能な指し手のリストの出力
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