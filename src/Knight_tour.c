#include "../include/Knight_tour.h"
#include <string.h>

const int MOVES_X[MOVE_COUNT] = {2, 1, -1, -2, -2, -1, 1, 2};
const int MOVES_Y[MOVE_COUNT] = {1, 2, 2, 1, -1, -2, -2, -1};

int move_is_possible(size_t move_id, size_t x, size_t y, board_t visited){
    int offset_x=MOVES_X[move_id];
    int offset_y=MOVES_Y[move_id];
    int new_x=offset_x+x;
    int new_y=offset_y+y;
    if (visited[new_x][new_y]==1||new_x>=SIZE||new_x<0||new_y>=SIZE||new_y<0){
        return 0;
    }else {
        return 1;
    }
}


unsigned int tour_greedy(size_t start_x, size_t start_y){
    board_t board;
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            board[i][j]=0;
        }
    }

    int x=start_x;
    int y=start_y;
    unsigned int move_count=0;
    board[x][y]=1;
    while(1){
        int is_found = 0;
        for(int i=0;i<MOVE_COUNT;i++){
            int is_possible = move_is_possible(i, x, y, board);
            if (is_possible==1){
                x=x+MOVES_X[i];
                y=y+MOVES_Y[i];
                is_found = 1;
                board[x][y]=1;
                move_count++;
                break;
            } 
        }
        if (is_found == 0){
            break;
        }
    }
    return move_count;
}

void greedy_tour_from_each_square(){
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            int move_count = tour_greedy(i, j);
            printf("%.2d  ", move_count);
        }
        printf("\n");
    }
}