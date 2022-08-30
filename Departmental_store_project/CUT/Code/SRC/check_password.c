/****************************************************************************************************************************************

 **FUNCTION NAME    :   check_password
 **
 **DESCRIPTION      :   This function is used to validate the Employee Password entered by the
                        employee to go inside the product file maintenance. 
 **
 **
 **RETURNS          :   It returns 0 if password is correct and 1 if password is wrong.
 **
 **
 *****************************************************************************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
#include<string.h>
#include<ctype.h>
#include<termios.h>
#include "header.h"
#define MAXPW 32



ssize_t getpasswd(char **pw,size_t sz,int mask,FILE *fp)
{
	if(!pw || !sz || !fp)
		return -1;
#ifdef MAXPW
	if(sz>MAXPW)
		sz=MAXPW;
#endif
	if(*pw==NULL)
	{
		//To reallocate memory......
		void *temp=realloc(*pw,sz * sizeof **pw); 
		if(!temp)
			return -1;
		memset (temp,0,sz);
		*pw=(char*) temp;
	}
	size_t idx=0;
	int c=0;
	struct termios old_kbd_mode;
	struct termios new_kbd_mode;

	if(tcgetattr (0,&old_kbd_mode))
	{
		fprintf(stderr,"%s() error:together failed.\n",__func__);
		return -1;
	}
	memcpy (&new_kbd_mode,&old_kbd_mode,sizeof(struct termios));

	new_kbd_mode.c_lflag &=~(ICANON | ECHO);
	new_kbd_mode.c_cc[VTIME]=0;
	new_kbd_mode.c_cc[VMIN]=1;
	if(tcsetattr (0,TCSANOW,&new_kbd_mode))
	{
		fprintf(stderr,"%s() error:tcsetattr failed.\n",__func__);
		return -1;
	}
	while(((c=fgetc(fp))!='\n' && c!=EOF && idx <sz-1) || (idx==sz-1 && c==127))
	{
		if(c!=127)
		{
			if(31 <mask && mask<127)
				fputc(mask,stdout);
			(*pw)[idx++]=c;
		}
		else if(idx>0)
		{
			if(31<mask && mask<127)
			{
				fputc(0x8,stdout);
				fputc(' ',stdout);
				fputc(0x8,stdout);
			}
			(*pw)[--idx]=0;
		}
	}
	(*pw)[idx]=0;
	if(tcsetattr(0,TCSANOW,&old_kbd_mode))
	{
		fprintf(stderr,"%s() error:tcsetattr failed.\n",__func__);
		return -1;
	}
	if(idx==sz-1 && c!='\n')
		fprintf(stderr,"(%s() warning:truncated at %zu chars.)\n",__func__,sz-1);
	return idx;
}


/*****************TO CHECK PASSWORD*********************************************/

int check_Password()
{
	char pw[MAXPW]={0};
	char *p=pw;
	FILE *fp=stdin;
	ssize_t nchr=0;
	nchr=getpasswd(&p,MAXPW,'*',fp);
	printf("\n Enter employee pasword:");
	nchr=getpasswd(&p,MAXPW,'*',fp);
	if(strcmp(p,"abc@123")==0 || strcmp(p,"xyz@345")==0)
	{
		return 0;
	}
	else
	{
		return 1;
	}

}

/*********************************************************************************/
