#include"database.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void LOAD(Database *D){
	char filename[50];
	scanf("%s",filename);
	FILE *myin=fopen(filename,"r");
	char tablename[50];
	fscanf(myin,"%s",tablename);
	

int main(){
	Database D;
	char s[10];
	while (1){
		scanf("%s",s);
		if (!strcmp(s,"LOAD")) LOAD(&D);
