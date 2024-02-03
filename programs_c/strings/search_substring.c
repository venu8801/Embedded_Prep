/* find an occurence of sub strig in a given string */

#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>

/* haystick is big string and needle is small string *
 */

int str_comp(char *str1, char *str2,int n)
{
	//printf("%s----%s---%d\n",str1,str2,n);
	int i;
	for(i=0; i < n; i++)
	{
		if(str1[i] != str2[i])
			return -1;
	
	}
	printf("return 0\n");
	return 0;
}

int find_occurences(char *haystack, char *needle){
	if(haystack == NULL || needle == NULL)
		return -1;
	int occur = 0;
	int h_len = strlen(haystack), n_len = strlen(needle);

	int i, ret;
	for(i = 0; i < (h_len - n_len+1); ){
		ret = str_comp(&haystack[i], needle, n_len);
		if(ret == 0){
			occur++;
			i = i + n_len;
		}			
		else
			i++;
	}
	return occur;


}


int main(){
	char hay[100], needle[100];
	printf("Enter main string: ");
	scanf("%[^\n]",hay);
	__fpurge(stdin);
	printf("Enter sub string: ");
	scanf("%[^\n]",needle);
	printf("Entered M:%s\tS:%s\n",hay,needle);
	printf("occurences: %d\n",find_occurences(hay,needle));



	return 0;
}	
