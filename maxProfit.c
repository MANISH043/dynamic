// Program Optimizes the Profit on a Subway Roll of N inches
/* Given :  Profit for Roll of length 1: 1
            Profit for Roll of length 2: 5
            Profit for Roll of length 3: 8
            Profit for Roll of length 4: 9

*/
#include <stdio.h>
#include <stdlib.h>

// CUT VALUES
int PRICE[4];

// MAX ROD SIZE
const int LIMIT = 1000;

// Structure
typedef struct node {

    int cut;
    struct node* next;

} node;

// Best Cut Look Up Table
node table[LIMIT];

int BestCut(int n);

int main() {

    PRICE[0] = 1;
    PRICE[1] = 5;
    PRICE[2] = 8;
    PRICE[3] = 9;

    for(int i = 0; i < LIMIT; i++)
    {
        table[i].next = NULL;
        table[i].cut = 0;
    }
    printf("\n");

    int done = 0;
    while (1) {

        int n;
        printf("Enter size of rod: ");
        scanf("%i", &n);

        node* arr = NULL;
        printf("The best way to cut rod of length %d is with max profit of %d \n: ", n, BestCut(n));
        node* travel = table[n-1].next;
        while (travel != NULL) {
            printf("%d | ",travel->cut);
            travel = travel->next;
        }
        scanf("%i", &done);
        if( done == 1) { break;}
    }
}


int BestCut(int n){

    if(n==0) {
        return 0;
    }

    else
    {
        if(table[n-1].next != NULL) {
            return table[n-1].cut;
        }
        else
        {
            if(n==1) {
                node* local = malloc(sizeof(node));
                local->cut = PRICE[0];
                local->next = NULL;
                table[n-1].next = local;
                table[n-1].cut = PRICE[0];
                return table[n-1].cut;
            }
            else if(n == 2) {
                node* local = malloc(sizeof(node));
                int val1 = PRICE[0] + BestCut(n-1);
                int val2 = PRICE[1];

                if(val1 >= val2) {
                    local->cut = PRICE[0];
                    local->next = table[(n-1) - 1].next;
                    table[(n-1)].next = local;
                    table[(n-1)].cut = val1;
                    return val1;
                }
                else {
                    local->cut = PRICE[1];
                    local->next = NULL;
                    table[n-1].next = local;
                    table[n-1].cut = val2;
                    return val2;
                }

            }
            else if( n == 3) {

                node* local = malloc(sizeof(node));
                int val1 = PRICE[0] + BestCut(n-1);
                int val2 = PRICE[1] + BestCut(n-2);
                int val3 = PRICE[2];

                if(val1 >= val2 && val1 >= val3) {
                    local->cut = PRICE[0];
                    local->next = table[(n-1) - 1].next;
                    table[(n-1)].next = local;
                    table[(n-1)].cut = val1;
                    return val1;
                }
                else if(val2 >= val1 && val2 >= val3) {
                    local->cut = PRICE[1];
                    local->next = table[(n-1) - 2].next;
                    table[(n-1)].next = local;
                    table[(n-1)].cut = val2;
                    return val2;
                }
                else {
                    local->cut = PRICE[2];
                    local->next = NULL;
                    table[(n-1)].next = local;
                    table[n-1].cut = val3;
                    return val3;
                }

            }
            else if( n == 4) {
                node* local = malloc(sizeof(node));
                int val1 = PRICE[0] + BestCut(n-1);
                int val2 = PRICE[1] + BestCut(n-2);
                int val3 = PRICE[2] + BestCut(n-3);
                int val4 = PRICE[3];

                if(val1 >= val2 && val1 >= val3 && val1 >= val4) {
                    local->cut = PRICE[0];
                    local->next = table[(n-1) - 1].next;
                    table[(n-1)].next = local;
                    table[(n-1)].cut = val1;
                    return  val1;

                }
                else if ( val2 >= val1 && val2 >= val3 && val2 >= val4) {
                    local->cut = PRICE[1];
                    local->next = table[(n-1) - 2].next;
                    table[(n-1)].next = local;
                    table[(n-1)].cut = val2;
                    return val2;
                }
                else if(val3 >= val1 && val3 >= val2 && val3 >= val4) {
                    local->cut = PRICE[2];
                    local->next = table[(n-1) - 3].next;
                    table[(n-1)].next = local;
                    table[(n-1)].cut = val3;
                    return val3;
                }
                else {
                    local->cut = PRICE[3];
                    local->next = NULL;
                    table[(n-1)].cut = val4;
                    table[(n-1)].next = local;
                    return val4;
                }
            }
            else {

                node* local = malloc(sizeof(node));
                int val1 = PRICE[0] + BestCut(n-1);
                int val2 = PRICE[1] + BestCut(n-2);
                int val3 = PRICE[2] + BestCut(n-3);
                int val4 = PRICE[3] + BestCut(n-4);

                if(val1 >= val2 && val1 >= val3 && val1 >= val4) {
                    local->cut = PRICE[0];
                    local->next = table[(n-1) - 1].next;
                    table[(n-1)].next = local;
                    table[(n-1)].cut = val1;
                    return  val1;

                }
                else if ( val2 >= val1 && val2 >= val3 && val2 >= val4) {
                    local->cut = PRICE[1];
                    local->next = table[(n-1) - 2].next;
                    table[(n-1)].next = local;
                    table[(n-1)].cut = val2;
                    return val2;
                }
                else if(val3 >= val1 && val3 >= val2 && val3 >= val4) {
                    local->cut = PRICE[2];
                    local->next = table[(n-1) - 3].next;
                    table[(n-1)].next = local;
                    table[(n-1)].cut = val3;
                    return val3;
                }
                else {
                    local->cut = PRICE[3];
                    local->next = table[(n-1) - 4].next;
                    table[(n-1)].cut = val4;
                    table[(n-1)].next = local;
                    return val4;
                }

            }
        }

    }




}

