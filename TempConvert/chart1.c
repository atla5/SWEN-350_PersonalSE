#include <stdio.h>
#include <stdlib.h>

int convert(int faren){
    /*convert a farenheit to celsius and return */
    return (5*(faren-32))/9;
}

int main(){
 
    printf("Farenheit-Celsium\n");
 
    int f;
    for(f=0;f<=300;f+=20){
      if(f<10){
        printf("    %d        %d\n",f,convert(f));
      }else if(f<100){
        printf("    %d       %d\n",f,convert(f));
      }else{
        printf("    %d      %d\n",f,convert(f));
      }
    }
    return 1;
}
