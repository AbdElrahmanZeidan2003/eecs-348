#include <stdio.h>

int main(){
    int score;
    while((score != 1) &&(score !=0)){
        printf(" Enter the NFL Score: \n");
        scanf("%d", &score);
        printf("All of the combinations %d\n", score);
        for (int td_2pt = 0; td_2pt * 8 <= score; td_2pt++) {
            for (int td_fg = 0; td_fg * 7 <= score; td_fg++) {
                for (int td = 0; td * 6 <= score; td++) {
                    for (int fg = 0; fg * 3 <= score; fg++) {
                        for (int safety = 0; safety * 2 <= score; safety++) {
                            int total = td_2pt * 8 + td_fg * 7 + td * 6 + fg * 3 + safety * 2;
                            if (total == score) {
                                printf("%d TD + 2pt, %d TD + FG, %d TD, %d FG, %d Safety\n", td_2pt, td_fg, td, fg, safety);
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
    
}