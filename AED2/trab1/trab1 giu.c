#include <stdio.h>
#include <string.h>
#define MAX_SIZE 10000 // Maximum string size

int countOccurrences(char * str, char * toSearch);

int main()
{
    char linha[MAX_SIZE];
    int N, M, i, j, o, k, l;
	scanf("%d %d\n",&N , &M);
	int valor[N];
    char toSearch[N][50];
	int count[N], Nota[M], nocount[M];
    for(k=0;k<N;k++){
    	fgets(toSearch[k],MAX_SIZE,stdin);
    	scanf("%d\n",&valor[k]);
	}
	char textos[M][MAX_SIZE];
	char *pt;
    fgets(linha,MAX_SIZE,stdin);
	pt = strtok(linha,".");
	while(pt){
		strcpy(textos[o],pt);
		pt=strtok(NULL,".");
		o++;
	}
	
	for(i=0;i<M;i++){
		while(textos[i][l]!='\0')
    	{
        /* check whether the current character is white space or new line or tab character*/
        	if(textos[i][l]==' ' || textos[i][l]=='\n' || textos[i][l]=='\t'){
            	nocount[i]++;
        	}
			l++;
		}
		l=0;
		for(j=0;j<N;j++){
			count[j] = countOccurrences(textos[i],toSearch[j]);
			Nota[i] = Nota[i] + (count[j]*valor[j]);
			nocount[i] = nocount[i] - count[j];
			
    		
		}
		nocount[i] --;
		Nota[i] = Nota[i] - (nocount[i]*10);
		printf("%d \n",Nota[i]);
	}
	
		

    return 0;
}



int countOccurrences(char * str, char * toSearch)
{
    int i, j, found, count;
    int stringLen, searchLen;

    stringLen = strlen(str);      // length of string
	searchLen = strlen(toSearch); // length of word to be searched

    count = 0;

    for(i=0; i <= stringLen-searchLen; i++)
    {
        /* Match word with string */
        found = 1;
        for(j=0; j<searchLen; j++)
        {
            if(str[i + j] != toSearch[j])
            {
                found = 0;
                break;
            }
        }

        if(found == 1)
        {
            count++;
        }
    }

    return count;
}

