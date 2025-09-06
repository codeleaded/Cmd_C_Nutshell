#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

int main(){
    //freopen("C:/Users/Micha/OneDrive/Yanis_Shared/Test/Stream.txt","w",stdout);
    //freopen("C:/Users/Micha/OneDrive/Yanis_Shared/Test/Stream.txt","r",stdin);

    fprintf(stdout,"Start:\n");

    fpos_t p;
    //fgetpos(stdout,&p);
    //p = (fpos_t)0;
    fsetpos(stdout,&p);
    fsetpos(stdin,&p);

    char pre[16];
    char aft[16];
    fscanf(stdin,"%s%s",pre,aft);
    strcat(pre," ");
    strcat(pre,aft);
    fprintf(stdout,"Output: %s |\n",pre);
    return 0;
}