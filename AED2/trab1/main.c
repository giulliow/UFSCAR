#include <stdio.h>
#include <string.h>
#define MAX_SIZE 10000 // Maximum string size



int main()
{
    char linha[MAX_SIZE];
    int N, M, i, j, o, k, l;
	scanf("%d %d\n",&N , &M);
	int valor[N];
    char toSearch[N][50];
	int count[N], Nota[M], nocount[M];
    for(k=0;k<N;k++){
    	scanf("%s %d\n", &toSearch[k],&valor[k]);
	}
	char textos[M][MAX_SIZE];
	char *pt;
    gets(linha);
	pt = strtok(linha,".");
	while(pt){
		strcpy(textos[o],pt);
		pt=strtok(NULL,".");
		o++;
	}
	
	for(i=0;i<M;i++){
		for (l = 0;textos[M][l] != '\0';l++)
    	{
        	if (textos[M][l] == ' ' && textos[M][l+1] != ' ')
        	nocount[i]++;    
    	}
    	printf("%d \n", nocount[i]);
		for(j=0;j<N;j++){
			count[j] = countOccurrences(textos[i],toSearch[j]);
			Nota[i] = Nota[i] + (count[j]*valor[j]);
			nocount[i] = nocount[i] - count[j];
			
    		
		}
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

