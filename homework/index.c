#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <malloc.h>
#define LEN 105
#define MAXN 999
#define STAT (strcmp(str,"a")&&strcmp(str,"an")&&strcmp(str,"the")&&strcmp(str,"and"))

typedef struct node{
    int col, lne;
    struct node * nxt;
} Node, * PNode;

typedef struct {
    char word[LEN];
    struct node * pos;
} List;

int t = 0;
List lst[MAXN];

void add_word(const char * str, int x, int y)
{
    int i, flag = 0;
    if(!STAT) return;
    PNode p, q;
    p = (PNode)malloc(sizeof(Node));
    p -> col = x, p -> lne = y, p -> nxt = NULL;
    for(i = 0; i < t; i++){
        if(!strcmp(str, lst[i].word)){
            q = lst[i].pos;
            while(q -> nxt != NULL){
                q = q -> nxt;
            }
            q -> nxt = p;
            flag = 1;
        }
    }
    if(!flag){
        strcpy(lst[t].word, str);
        lst[t].pos = p;
        t++;
    }
}

int cmp(const void * p, const void * q)
{
    return strcmp((*(List*)p).word, (*(List*)q).word);
}

int main()
{
    FILE * in, * out;
    int i, j, r = 0, x = 0, y = 1, flag = 0;
    char c, wd[LEN];
    PNode np;
    in = fopen("crossin.txt", "r");
    out = fopen("crossout.txt", "w");
    while((c = fgetc(in)) != EOF){
        if(c == '\n'){
            if(flag){
                wd[r] = '\0';
                add_word(wd, x - strlen(wd) + 1, y);
                r = 0;
                flag = 0;
            }
            y++;
            x = 0;
        }else if(isalpha(c) || (c == '-' && r != 0)){
            wd[r++] = c;
            x++;
            flag = 1;
        }else{
            if(flag){
                wd[r] = '\0';
                add_word(wd, x - strlen(wd) + 1, y);
                r = 0;
                flag = 0;
            }
            x++;
        }
    }
    if(flag){
        wd[r] = '\0';
        add_word(wd, x, y);
    }
    qsort(lst, t, sizeof(List), cmp);
    for(i = 0; i < t; i++){
        fprintf(out, "%s:", lst[i].word);
        np = lst[i].pos;
        for(j = 0; np != NULL; j++){
            if(j != 0) fputc(',', out);
            fprintf(out, "(%d,%d)", np->lne, np->col);
            np = np -> nxt;
        }
        fprintf(out, "\n");
    }
    return 0;
}
