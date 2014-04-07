#include <stdio.h>
#include <stdlib.h>

float convert(int faren){
    /*convert a farenheit to celsius and return */
    return (5.0*(faren-32))/9.0;
}

int main(){
 
    printf("Fahrenheit-Celsius\n");
 
    int f;
    for(f=0;f<=300;f+=20){
        printf("%6d %10.1f\n",f,convert(f));
    }
    return 1;
}
