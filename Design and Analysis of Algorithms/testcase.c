#include<stdio.h>
#include<stdlib.h>


int main(){
    FILE *file;

    file = fopen("bestcase.txt","w");
    for(int i=0; i < 10000; i++){
        fprintf(file,"%d ",i);
    }
    fclose(file);


    file = fopen("worstcase.txt","w");
    for(int i=100000; i>0; i--){
        fprintf(file,"%d ",i);
    }
    fclose(file);


    file = fopen("avragecase.txt","w");
    for(int i=100000; i>0; i--){
        fprintf(file,"%d ", rand()%100000);
    }
    fclose(file);

}