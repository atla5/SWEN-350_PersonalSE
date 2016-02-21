#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
 
int main() {
    char *typeKey[7];  // and array of char *
    printf("%p\n",&typeKey[0]);
    printf("%p\n",&typeKey[1]);
    typeKey[0] = "<none>";
    typeKey[1] = "Temperature";
    printf("%s\n",typeKey[0]);
    printf("%s\n",typeKey[1]);
    typeKey[2] = "Heart Rate";
    typeKey[3] = "Systolic Pressure";
    typeKey[4] = "Diastolic Pressure";
    typeKey[5] = "Respiration Rate";
    typeKey[6] = "Print command entered";
 
    char time[50] = "12:34:45";
    int id = 233;
    int type = 4;
    printf("%s\n", time);
    printf(":%s\n", typeKey[type]);
    printf(" %d\n",id);
 
    printf("%s: %s for PatientID = %d\n", time, typeKey[type], id);
 
 
    return 0 ;
}
