//azra rangwala
//making own directory
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

struct files {
    char file_name[256];  //255+null
    int permissions;   //0-7
};

bool exists(char *command); 
char arrn[3];

int main(){
    struct files *p1; // pointer to struct files
    struct files *p2;
    char reply[3];
    p1= malloc(sizeof(struct files)*20); 
    if (p1==NULL){
        printf("not enough memory\n");
        return 1;
    }do{
    printf("do you want to load a directory? Enter yes or no \n");
    scanf("%s", &reply);
    }while(strcmp(reply, "yes")!=0 && strcmp(reply, "no")!=0);
    if (strcmp(reply, "yes")==0){
        //prompt for an actual file to retrieve previous data using fread
        char open_file[20];
        FILE *stream;
        do{
            printf("enter a file name you want to open \n"); 
            scanf("%s", open_file);
            stream= fopen("open_file","rb");
        }while(stream == NULL);
        //open the file that the user tells you to
        if (stream== NULL){
            //ask for new file name
            printf("error opening file! \n");
            printf("enter a new file name \n");
            scanf("%s", stream);
        }
        fread(p1, sizeof(struct files), 20, stream);
        fclose(stream);
    }
    else if (strcmp(reply,"no")==0){
        //use memory allocated for new files
        for (int i=0; i<20; i++){
            (p1+i)->file_name[0]= '-'; 
            (p1+i)->permissions= -1; 
        }
    }
    else if((strcmp(reply,"yes")!=0)&&(strcmp(reply,"no")!=0)&&(strcmp(reply,"No")!=0)&&(strcmp(reply,"Yes")!=0))
		        printf("invalid input\n");

    char command[10]; //need to declare outside of scope
    do{
        printf("enter a command: touch, ls, mv, chmod, rm, or quit: \n");
        scanf("%s", command);
    }while(strcmp(command,"touch")!=0 && strcmp(command,"ls")!=0 && strcmp(command,"mv")!=0 &&
        strcmp(command,"chmod")!=0 && strcmp(command,"rm")!=0 && strcmp(command,"quit")!=0);
    char newfile[256];
    if (strcmp(command,"touch")==0){
        printf("enter a filename \n");
        scanf("%s", newfile);
        int ex=0;
        //check if newfile exists
        for(int i=0; i<20; i++){
            if (strcmp(newfile, (*(p1+i)).file_name)==0){
                ex=1;
                printf("file already exists \n");
            }
        }
        if(ex==0){
            for(int i = 0; i < 20; i++) {
                if (strcmp((*(p1+i)).file_name, "-")==0){
                    strcpy((*(p1+i)).file_name,newfile);
                    (p1+i)->permissions=7;  
            }
        }
        printf("%s was created\n", newfile);
    do{
    printf("enter a command: touch, ls, mv, chmod, rm, or quit: \n");
    scanf("%s", command);
    }while(strcmp(command,"touch")!=0 && strcmp(command,"ls")!=0 && strcmp(command,"mv")!=0 &&
        strcmp(command,"chmod")!=0 && strcmp(command,"rm")!=0 && strcmp(command,"quit")!=0); 
    }
    if (strcmp(command, "ls")==0){ 
        for(int i =0; i<20; i++){   
            if ((p1+i)->permissions==7 && strcmp((p1+i)->file_name, "-")!=0)
                printf("rwx      %s\n", (p1+i)->file_name);
            if ((p1+i)->permissions==6 && strcmp((p1+i)->file_name, "-")!=0)
                printf("rw-      %s\n",(p1+i)->file_name); 
            if ((p1+i)->permissions==5 && strcmp((p1+i)->file_name, "-")!=0)
                printf("r-x      %s\n",(p1+i)->file_name);
            if ((p1+i)->permissions==4 && strcmp((p1+i)->file_name, "-")!=0)
                printf("r--      %s\n",(p1+i)->file_name);
            if(((p1+i)->permissions==4 || (p1+i)->permissions==5 || (p1+i)->permissions==6 || (p1+i)->permissions==7) && strcmp((p1+i)->file_name, "-")!=0)
                break;
        } //do not list if there is no read permissions 
    do{
    printf("enter a command: touch, ls, mv, chmod, rm, or quit: \n");
    scanf("%s", command);
    }while(strcmp(command,"touch")!=0 && strcmp(command,"ls")!=0 && strcmp(command,"mv")!=0 &&
        strcmp(command,"chmod")!=0 && strcmp(command,"rm")!=0 && strcmp(command,"quit")!=0);
    }
    if(strcmp(command, "mv")==0){
        printf("enter a filename: \n");
        char name[256];
        scanf("%s",name);
        int x=0;
        int y=0; 
        for(int i=0; i<20; i++){
                if (strcmp(name, (*(p1+i)).file_name)==0)
                    x=1;
            }
        if(x==0){ //file does not exist
            printf("file not found \n");
            do{
            printf("enter a command: touch, ls, mv, chmod, rm, or quit: \n");
            scanf("%s", command);
            }while(strcmp(command,"touch")!=0 && strcmp(command,"ls")!=0 && strcmp(command,"mv")!=0 &&
            strcmp(command,"chmod")!=0 && strcmp(command,"rm")!=0 && strcmp(command,"quit")!=0); 
        }
        for (int i=0; i < 20; i++ ){
             //check if write permissions and exists
            if (x==1 && ((p1+i)->permissions==2 || (p1+i)->permissions==3 || (p1+i)->permissions==6 || (p1+i)->permissions==7))  
                y=1;
        }
        if (y=1){
            printf("This file already exists. Enter a new filename:  \n");
            char new_name[20];
            scanf("%s", new_name);
            for(int i =0; i<20; i++){
                //set new name
                if ((strcmp(new_name, (*(p1+i)).file_name)!=0)){ 
                    strcpy((*(p1+i)).file_name, new_name);
                    printf("%s was set as the new name\n",(*(p1+i)).file_name);
                    break;
                }
            }
        }
        do{
            printf("enter a command: touch, ls, mv, chmod, rm, or quit: \n");
            scanf("%s", command);
        }while(strcmp(command,"touch")!=0 && strcmp(command,"ls")!=0 && strcmp(command,"mv")!=0 &&
        strcmp(command,"chmod")!=0 && strcmp(command,"rm")!=0 && strcmp(command,"quit")!=0);
    }
    if(strcmp(command, "chmod")==0){
        printf("enter a filename: \n");
        char fl [100];
        scanf("%s", fl);
        int k=0;
        int p;
        for(int p=0;p<20; p++){
                if (strcmp(fl, (*(p1+p)).file_name)==0)
                    k=1;
        }
        if(k!=1){
            printf("file not found, re-enter different file \n");
            scanf("%s", fl);
                for(int p=0; p<20; p++){
                if (strcmp(fl, (*(p1+p)).file_name)==0)
                    k=1;
                }
        }
        else if(k==1){
            //change permissions however they want 
            printf("enter new permissions, either an integer from 0-7 or 'r' 'w' 'x' to toggle the permissions \n"); 
            char n [100];
            int p;
            scanf("%s", n);
            if((strcmp(n,"0")!=0)&&(strcmp(n,"1")!=0)&&(strcmp(n,"2")!=0)&&(strcmp(n,"3")!=0)&&(strcmp(n,"4")!=0)&&(strcmp(n,"5")!=0)&&(strcmp(n,"6")!=0)&&(strcmp(n,"7")!=0)&&(strcmp(n,"r")!=0)&&(strcmp(n,"w")!=0)&&(strcmp(n,"x")!=0))
		        printf("invalid input\n");
                    if (strcmp(n, "0")==0)
                        (*(p1+p)).permissions=0;
                    if(strcmp(n,"1")==0)
                        (*(p1+p)).permissions=1;
                    if(strcmp(n,"2")==0)
                        (*(p1+p)).permissions=2;
                    if(strcmp(n, "3")==0)
                        (*(p1+p)).permissions=3;
                    if(strcmp(n, "4")==0)
                        (*(p1+p)).permissions=4;
                    if (strcmp(n, "5")==0)
                        (*(p1+p)).permissions=5;
                    if(strcmp(n, "6")==0)
                        (*(p1+p)).permissions=6;
                    if(strcmp(n, "7")==0)
                        (*(p1+p)).permissions=7;
                    if(strcmp(n, "r")==0){
                        if ((*(p1+p)).permissions== 0 || (*(p1+p)).permissions== 1 || (*(p1+p)).permissions== 2 || (*(p1+p)).permissions== 3)
                            (*(p1+p)).permissions+=4;
                    }
                    if(strcmp(n, "w")==0){
                        if ((*(p1+p)).permissions== 0 || (*(p1+p)).permissions== 1 || (*(p1+p)).permissions== 5 || (*(p1+p)).permissions== 4)
                            (*(p1+p)).permissions+=4;
                    }
                    if(strcmp(n, "x")==0){
                        if ((*(p1+p)).permissions%2==0)
                            (*(p1+p)).permissions++;
                    }
                    printf("the new permissions were set %s",(*(p1+p)).permissions);
                }
    do{
    printf("enter a command: touch, ls, mv, chmod, rm, or quit: \n");
    scanf("%s", command);
    }while(strcmp(command,"touch")!=0 && strcmp(command,"ls")!=0 && strcmp(command,"mv")!=0 &&
        strcmp(command,"chmod")!=0 && strcmp(command,"rm")!=0 && strcmp(command,"quit")!=0);
    }
    if(strcmp(command, "rm")==0){
        printf("enter a filename: \n");
        char arr[256];
        scanf("%s", arr);
        int z=0;
        for(int i=0; i<20; i++){
            if (strcmp(arr, (*(p1+i)).file_name)==0){
                if((*(p1+i)).permissions==2 || (*(p1+i)).permissions==3 || (*(p1+i)).permissions==5 || (*(p1+i)).permissions==6 || (*(p1+i)).permissions==7){
                    z=1;
                }
                else 
                    printf("no write permissions \n");
            }
        }
        if(z==0)
            printf("file not found \n"); 
        //exists and write permissions
        if(z==1){
        //set struct for that file back to original state
            int i=0;
            while(strcmp(arr, (*(p1+i)).file_name)!=0){
                i++; }
            strcpy((*(p1+i)).file_name, "-");
            (*(p1+i)).permissions=-1;
            printf("%d", (p1+i)->permissions); 
        }
    do{
    printf("enter a command: touch, ls, mv, chmod, rm, or quit: \n");
    scanf("%s", command);
    }while(strcmp(command,"touch")!=0 && strcmp(command,"ls")!=0 && strcmp(command,"mv")!=0 &&
        strcmp(command,"chmod")!=0 && strcmp(command,"rm")!=0 && strcmp(command,"quit")!=0);
    }
    else if(strcmp(command, "quit")==0){
        char arrr[256];
        printf("Do you want to save the directory information in a file? \n");
        gets(arrr);
        FILE *fpDest;
        char quits[25];
        if(strcmp(arrr,"yes")==0){
            do{
            printf("enter a filename \n");
            scanf("%s", quits);
            //use fwrite to write to that file
            fpDest = fopen(quits, "w");
            }while(fpDest == NULL);
            if (fpDest == NULL){
                printf("Error opening destination file! Enter other file name: \n");
                scanf("%s", quits);
                fpDest = fopen(quits, "w");
            }
            fwrite(p1, sizeof(struct files), 20, fpDest);
            fclose(fpDest);
        }
        if(strcmp(arrr, "no")==0)
            return 0; 
        else 
            printf("invalid input"); //make sure wrong responses accounted for
    do{
    printf("enter a command: touch, ls, mv, chmod, rm, or quit: \n");
    scanf("%s", command);
    }while(strcmp(command,"touch")!=0 && strcmp(command,"ls")!=0 && strcmp(command,"mv")!=0 &&
        strcmp(command,"chmod")!=0 && strcmp(command,"rm")!=0 && strcmp(command,"quit")!=0);
    }
    }
}

bool exists(char *command){
    // check if exists here by using fopen
    FILE *fp;
    bool ifexists= 0;
    fp=fopen(command, "rb");
    if (fp!= NULL){
        ifexists= 1; 
        fclose(fp);
    }
    return ifexists;
}




    
