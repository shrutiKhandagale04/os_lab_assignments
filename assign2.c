#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct keyword{
    char k[100];
}kw[32];

struct operator{
    char op[10];
}o[10];

struct output{
    int sr;
    char name[100];
    char type[100];
}out[500];


int main()
{
    FILE* ptr;
    int i,j, a=1, idflag=0;
    char str[100];
    ptr=fopen("LA.txt","r");

    strcpy(kw[0].k,"char");
    strcpy(kw[1].k,"int");
    strcpy(kw[2].k,"include");
    strcpy(kw[3].k,"stdio.h");
    strcpy(kw[4].k,"if");
    strcpy(kw[5].k,"else");

    strcpy(o[0].op, "*");
    strcpy(o[1].op, "+");
    strcpy(o[2].op, "=");
    strcpy(o[3].op, "-");
    strcpy(o[4].op, "<=");
    strcpy(o[5].op, ">=");

    // Read the file and compare the strings
    if(ptr==NULL)
    {
        printf("File is empty");
    }
    else
    {
	    while(fscanf(ptr, "%s",str)!= EOF)
        {
  	        idflag=0;
	        for(i=0;i<=32;i++)
	        {
		        if(strcmp(str,kw[i].k)==0)
		  	    {
		  	        printf("\nKeyword %s was found", str);
		  	        idflag=1;		  	
		  	        break;
		  	    }
	        }
	
            if(str[0]=='#' || str[0]=='(' || str[0]==')' || str[0]=='{' || str[0]=='}' ||str[0]==';' || str[0]=='<' || str[0]=='>')
	  	    {
	      	    printf("\nSpecial Symbol %c was found", str[0]);
	  	        idflag=1;	  
	  	    }

	        if (str[0] >= '1' && str[0] <= '9')
	  	    {
	  		    printf("\nConstant %c was found", str[0]);
  		  	    idflag=1;
	  	    }
	  	    for(i=0;i<10;i++)
	  	    {
	 	        if(strcmp(str,o[i].op)==0)
	  		    {
	  	 	       printf("\nOperator %s was found", str);
	  	 	        idflag=1;
	  	 	    }
	  	    }

	        if(idflag==0)
            {
	  	        printf("\nIdentifier %s was found", str);
	  	    }

	    }
    }

}