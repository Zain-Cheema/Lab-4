#include <stdio.h>

void Score_Combos(int score) {
    int TD, FG, safety, TD_2pt, TD_1pt;
    
    printf("Possible combinations if score is %d:\n", score);
    
    for (TD_2pt = 0; TD_2pt <= score / 8; TD_2pt++) {
        for (TD_1pt = 0; TD_1pt <= (score - 8 * TD_2pt) / 7; TD_1pt++) {
            for (TD = 0; TD <= (score - 8 * TD_2pt - 7 * TD_1pt) / 6; TD++) {
                for (FG = 0; FG <= (score - 8 * TD_2pt - 7 * TD_1pt - 6 * TD) / 3; FG++) {
                    for (safety = 0; safety <= (score - 8 * TD_2pt - 7 * TD_1pt - 6 * TD - 3 * FG) / 2; safety++) {
                        if (8 * TD_2pt + 7 * TD_1pt + 6 * TD + 3 * FG + 2 * safety == score) {
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", 
                                   TD_2pt, TD_1pt, TD, FG, safety);
                        }
                    }
                }
            }
        }
    }
}

int main() {
    int score;
    
    while (1) {      //Keep asking until value <= 1 is entered
        printf("Enter the NFL score (enter 0 or 1 to STOP): ");
        scanf("%d", &score);
        
        if (score <= 1) {
            break;
        }
        
        Score_Combos(score);
    }
    
    return 0;
}
