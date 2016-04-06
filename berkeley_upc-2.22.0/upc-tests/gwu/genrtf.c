/* Generate rtf.

   This program generates a rich text format file based on the description 
   in the headers of the testing suite.

   The generated rtf file can be formatted using the format macro which
   is in the file Format.bas

   Copyright 2000 Sebastien Chauvin - George Mason University.


This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/

#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <string.h>

#define STR_SIZE 100
#define BIGSTRING 1000

#define MAXCAT 20
#define MAXSUBCAT 10

typedef struct {
    int id[3];
    char* name;
    char* purpose;
    char* type;
    char* how;
    char* passingc;
    int used;
} header;

enum state_t { root, Test, Name, Purpose, Type, How, Passingc };

char* CurrentFileName;

#define SEQ(s1, s2) (!strncmp((s1), (s2), strlen((s2)) ) )
#define SKIPBLANK { pline+=strspn(pline," \t"); }
#define PERROR(error) { printf("Parse error : %s (file: %s line: %s.{%s}).\n", error, CurrentFileName, line, pline); return 1; }

int get_roman(char** l)
{
    char* line = *l;
    char* pline = *l;
    
    int n=0;
 
    while(strspn(*l, "IVXivx")) {
        if (**l=='I' || **l=='i') 
	    n++;
	else if (**l=='V' || **l=='v')
	    if (n<5) n=5-n;
	    else n+=5;
	else if (**l=='X' || **l=='x')
	    if (n<10) n=10-n;
	    else n+=10;
	(*l)++;	
    }

    if (!n) PERROR("Invalid roman number");
    
    return n;    
}

int read_header(FILE* fin, header* h) 
{
    int n;
    
    char line[STR_SIZE];
    char* pline;
    enum state_t state=root;

    memset(h, 0, sizeof(*h));

    h->name=(char*)malloc(BIGSTRING); *(h->name)=0;
    h->purpose=(char*)malloc(BIGSTRING); *(h->purpose)=0;
    h->type=(char*)malloc(BIGSTRING); *(h->type)=0;
    h->how=(char*)malloc(BIGSTRING); *(h->how)=0;    
    h->passingc=(char*)malloc(BIGSTRING); *(h->passingc)=0;

 skip_nonheader:
    while (!feof(fin)) {
	fgets(line, STR_SIZE, fin);
	if (strstr(line, "/*")) 
	    break;
    }
    
    while (!feof(fin)) {
	fgets(line, STR_SIZE, fin);
	if (strstr(line, "*/")) 
	    goto skip_nonheader;
	
	while(line[strlen(line)-1]=='\n') line[strlen(line)-1]=' ';	
	pline = line;
	
    sameline:
	SKIPBLANK;
	
	if (!(*pline)) continue;
	
	if (SEQ(pline, "Test:"))
	    { state = Test; 
	    pline+=5;
	    goto sameline;
	    } else if (SEQ(pline, "Purpose:"))
		{ state = Purpose; 
		pline+=8;
		goto sameline;
		} else if (SEQ(pline, "Type:"))
		    { state = Type; 
		    pline+=5;
		    goto sameline;
		    } else if (SEQ(pline, "How:") || SEQ(pline, "How :"))
			{ state = How; 
			pline+=5;
			goto sameline;
			} else if (SEQ(pline, "Passing criteria:"))
			    { state = Passingc; 
			    pline+=17;
			    goto sameline;
			    }
	switch (state) {
	case root:
	    break;
	
	case Test:
	    h->id[0]=get_roman(&pline)-1;	
	    if (!SEQ(pline, "_case"))
		PERROR("invalid name");
	    pline+=5;
	    n=*pline-'0';
	    if ((n<0) || (n>9))
		PERROR("invalid name");
	    h->id[1]=n-1;
	    pline+=2;
	    h->id[2]=get_roman(&pline)-1;
	    state = Name;
	    goto sameline;
	    
	case Name:
	    pline+=strspn(pline, " -\t");
	    strcat (h->name, pline);
	    break;
	  
	case Purpose:
	    strcat(h->purpose, pline);
	    break;
	    
	case Type:
	    strcat(h->type, pline);
	    break;

	case How:
	    strcat(h->how, pline);
	    break;

	case Passingc:
	    strcat(h->passingc, pline);
	    break;	    
	}
    }

    return 0;
}


void print_header(header h)
{
    //    printf("Test: %d.%d.%d\n", h.id[0], h.id[1], h.id[2]);
    
    printf("\\s3 {%s \\par}\n"
	   "\\pard \\plain {Purpose: %s \\par\n"
	   "Type: %s \\par\n"
	   "How:\\par}\n\\s4 {%s\\par}\n", h.name,h.purpose, h.type, h.how);

    if (strlen(h.passingc))
	printf("\\pard {Passing criteria:\n %s\\par}\n", h.passingc);
    
}

void post_process(header* h, char* subcat)
{
   char* p = h->how;
   char* new_how = (char*)malloc(strlen(h->how)+1);
   int first = 1;
   

   // NAME

   if (strlen(h->name)-strlen(subcat)>2)
       if (strstr(h->name, subcat))
	   h->name+=strlen(subcat);
   
   h->name+=strspn(h->name, " \t");

   if ((h->name[0]<='z') && (h->name[0]>='a')) h->name[0]+='A'-'a';
   
   // HOW
   *new_how=0;
   
   while(p && *p) {
       if (!first) 
	   strcat(new_how,"\\par\n");       
       p+=strspn(p,"- \t");

       if (strstr(p, "- "))
	   strncat(new_how, p, strstr(p,"- ")-p);
       else
	   strcat(new_how, p);
              
       p=strstr(p,"- ");
       first=0;
       
   }
   
   free(h->how);
   h->how=new_how;   
}

int read_categories(char* cats[MAXCAT][MAXSUBCAT], int n1[MAXCAT])
{
    int n0=-1;
    char* line;
    FILE* f;
    
    f=fopen("Categories.lst", "r");
    if (!f)
	fprintf(stderr, "Unable to open the category list.\n");
    else {
	while(!feof(f)) {
	    line=(char*)malloc(STR_SIZE);
	    fgets(line, STR_SIZE, f);
	    while (line[strlen(line)-1]=='\n') line[strlen(line)-1]=0;

	    if (*line!='*') {
		cats[++n0][0]=line;
	    }
	    else
		if (n0>=0)
		    cats[n0][++(n1[n0])]=line+1;
		else
		    fprintf(stderr,"Error : subcategory before the first category.\n");
	}
	fclose(f);	
    }    
    return n0+1;
}

int comp_header_3(const void* p1, const void* p2)
{
    header* h1 = (header*) p1;
    header* h2 = (header*) p2;
    
    return h1->id[2] - h2->id[2];
    
}

int comp_header_2(const void* p1, const void* p2)
{
    header* h1 = (header*) p1;
    header* h2 = (header*) p2;
    
    return h1->id[1] - h2->id[1];
    
}

char* TBL_ROMAN[] = { "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", 
		      "X", "XI", "XII", "XIII", "XIV" 
};


char* print_roman(char* buf, int n)
{
    /* Write a more general thing ! */

    return TBL_ROMAN[n];    
}

void main(int argc, char** argv)
{  
    int i,j,k; 
    int nh = argc-1;
    header* h = (header*)malloc(argc*sizeof(header));
    FILE* f;

    char* Categories[MAXCAT][MAXSUBCAT];
    int ncats;    
    int nsubcat[MAXCAT] = {0};
    

    for (i=0; i<nh; i++) {
	f = fopen(argv[i+1], "r");
        CurrentFileName = argv[i+1];
	if (!f)
	    fprintf(stderr, "Unable to open: %s\n", argv[i+1]);
	else {
	    if (!read_header(f, h+i));
	}
	fclose(f);
    }
    
    qsort(h, nh, sizeof(header), comp_header_3);
    //    qsort(h, nh, sizeof(header), comp_header_2);
        
    ncats=read_categories(Categories, nsubcat);
    
    printf("{\\rtf1\\ansi \\deff0\\deflang1033\\deflangfe1033"
	   "{\\stylesheet"
	   "  {Normal;}"
	   "  {\\s1 heading 1;}"
	   "  {\\s2 heading 2;}"
	   "  {\\s3 heading 3;}"
	   "  {\\s4 Bulletised How;}"
	   "}\n"
	   "{\n");
    
    for(i=0; i<ncats; i++) {
	//printf("%s ", print_roman(buf, i));
	printf("\\s1 {%s \\par}\n", Categories[i][0], nsubcat[i]);

	for(j=0; j<nsubcat[i]; j++) {
	    printf("\\s2 {case %d: %s \\par}\n", j+1, Categories[i][j+1]);
	    for(k=0; k<nh; k++)
		if ((h[k].id[0]==i) && (h[k].id[1]==j)) {
		    post_process(h+k, Categories[i][j+1]);
		    print_header(h[k]);
		    h[k].used=1;
		}
	}
	
    }

    for(k=0; k<nh; k++)
	if (!h[k].used)
	    fprintf(stderr, "Warning, test %d.%d.%d (%s) is not used.\n",
		    h[k].id[0], h[k].id[1], h[k].id[2], h[k].name);
    
    printf("}}\n");
}
