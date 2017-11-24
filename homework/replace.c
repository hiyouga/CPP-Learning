#include <stdio.h>
#include <ctype.h>

int main()
{
    int i = 0, j, t, k = 0, flag, m = 0, n = 0;
    char c, r[999], p[999], s[9999];
    FILE * in, * out;
    in = fopen("filein.txt", "r");
    out = fopen("fileout.txt", "w");
    while((c = getchar()) != '\n')
        r[m++] = tolower(c);
    while((c = getchar()) != '\n')
        p[n++] = c;
    while((c = fgetc(in)) != EOF){
        s[k++] = c;
    }
    while(i < k){
        if(tolower(s[i]) == r[0]){
            j = 0, t = i, flag = 1;
            while(j < m){
                if(tolower(s[t++]) != r[j++]){
                    flag = 0;
                    break;
                }
            }
            if(flag){
                for(j = 0; j < n; j++){
                    fputc(p[j], out);
                }
                i += m;
            }else{
                fputc(s[i], out);
                i++;
            }
        }else{
            fputc(s[i], out);
            i++;
        }
    }
    fclose(in);
    fclose(out);
    return 0;
}
