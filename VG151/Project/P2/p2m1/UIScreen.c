#include"UIScreen.h"

#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
#include<stdarg.h>

#include"Card.h"
#include"Pile.h"
#include"User.h"
#include"Operation.h"
#include"Game.h"
#include"Sys.h"

void UIPrint(int _thisPauseTime,char *_thisFormat,...){
	va_list ap;
	va_start(ap,_thisFormat);
	for (char *c=_thisFormat;*c;c++){
		if (*c!='%') printf("%c",*c);
		else switch (*++c){
			case 'd': printf("%d",va_arg(ap,int)); break;
			case 'c': printf("%c",(char)va_arg(ap,int)); break;
			case 's': printf("%s",va_arg(ap,char*)); break;
			default : 
					if (*c=='2'){
						printf("%2d",va_arg(ap,int));
						c++;
					}
					else printf("%c",*c); 
					break;
		}
	}
	va_end(ap);
	PauseScreen(_thisPauseTime);
}


