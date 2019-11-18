#include "get_rssi.h"
/*
int get_rssi_char(char *buffer)

读取文本格式的RSSI值，
存入到buffer指向的内存中

注：buffer长度10
成功返回 1
失败返回 0
	
*/

int get_rssi_char(char *buffer)
{
	FILE *fp;
	fp=fopen(FILE_PATH,"r");
	if(NULL==fp)
	{
		printf("fail to open rssi file!\n");
		return 0;
	}
	else
	{	
		fgets(buffer,10,fp);
		buffer[9]='\n';
		fclose(fp);
		return 1;
	}
}
/*
int string_to_int(char *buffer)

文本转数字，保留小数点后两位（直接忽略小数点）
返回 int型RSSI
	
*/
int string_to_int(char *buffer)
{
	int a;
	double b;
	int size,power;
	//经验得出，一般不需要改
	size=strlen(buffer)-6;
	power=size+1;//power可以直接等于5？没试过，可以试下。
	b=0;
	for(a=0;;a++)
	{
		if(buffer[a]!='.')
		{
			if(buffer[a]==' ')//忽略小数点
				break;
			b+=pow10(power--)*(buffer[a]-'0');		
		}
	}
	if(a==5)
		b/=10;
	return (int)b;
}
/*
int get_rssi_char(char *buffer)

读取整数格式的RSSI值，

就是把上面两个程序合了起来
	
*/
int get_rssi_int()
{
	char buffer[10]={0};
	FILE *fp;
	fp=fopen(FILE_PATH,"r");
	if(NULL==fp)
	{
		printf("fail to open rssi file!\n");
		return 0;
	}
	else
	{
		memset(buffer,0,10);	
		fgets(buffer,10,fp);
		fclose(fp);
		return string_to_int(buffer);;
	}
}

