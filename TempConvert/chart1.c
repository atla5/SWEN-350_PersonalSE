#include <stdio.h>
#include <stdlib.h>

int convert(int faren){
    /*convert a farenheit to celsius and return */
    return (5/9.0)(faren-32);
}

int main(){
  
    int i;
    for(i=0;i<=300;i+20){
        printf("    %d     %d\n",i,convert(i));
    }
    return 1;
}
