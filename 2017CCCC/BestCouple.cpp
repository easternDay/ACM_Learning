#include <stdio.h>
int main () {
	int n;
	char c;
	float h;
	//方法一 
	//scanf("%d\n", &n); 	//'\n'表示忽略所有的空白字符,输入非空白字符结束输入 ，不加'\n'会使c接收换行符 
	//方法二 
	scanf("%d", &n);
	getchar(); //接收换行符 
	while ( n-- ) {
		//scanf("%c %f\n", &c, &h);
		scanf("%c %f", &c, &h);
		getchar();
		if ( c == 'F' ) 
			printf("%.2f\n", h * 1.09);
		else
			printf("%.2f\n", h / 1.09);
	} 
 	return 0;
}