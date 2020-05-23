#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

double sum_double(int n, ...)
{
	va_list arglist;
	va_start(arglist, n);
	double result = 0, i;
	while (n > 0) 
	{
		i = va_arg(arglist, double);
		result += i;
		--n;
	}
	va_end(arglist);
	return result;
}

char* concat(char* s, ...)
{
	va_list arglist;
	va_start(arglist, s);
	char* str = (char*)malloc(20 * sizeof(char));
	char* ans = (char*)malloc(strlen(s)*sizeof(char));
	strcpy_s(ans,strlen(s) + 1, s);
	//printf("%s", ans);
	while (str != "\0")
	{
		str = va_arg(arglist, char*);
		//printf("%s", str);
		strcat_s(ans,strlen(ans)+strlen(str) + 1, str);
	}
	ans[strlen(ans) - 1] = '\0';
	//printf("%s", ans);

	
	va_end(arglist);
	return ans;
}




int main()
{

	//printf("%d\n ", sizeof(int*));
	printf("%lf\n", sum_double(4, 1.1, 2.2, 3.0, 0.1));
	char* s;
	s = concat("One ", "Two ", "Two ","Two ", "\0");
	printf("%s\n", s);
	s = concat("Heppy ", "New " ,"Year!", "\0");
	printf("%s\n", s);

	system("pause");
}