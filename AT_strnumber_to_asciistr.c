#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//将字符串(只包含数字)全部转换成ascii 
int strnumber_to_asciistr(char *dest,const char *src,int len)
{

	int i = 0 ; 
	if(0 == len || NULL == src || NULL == dest)
		return -1; 
	else 
	{
		for(i = 0 ; i < len ; i++,src++)
		{
			if(*src < '0' || *src > '9')
				return -2 ; 
			*dest++ = "0123456789"[*src >> 4];
			*dest++ = "0123456789"[*src & 0x0f];
		}
		*dest = '\0';
		printf("dest=%s\n",dest-2*len);
		return 0 ;
	}
}
 
void Send_Data_To_easyiot(char *__imsi,char *__imei,int property ,int status)
{
	char imsi[31] = {0};
	char imei[31] = {0};
	char cmd_buf[141] = {0};
	//IMSI整体转ASCII 
	strnumber_to_asciistr(imsi,__imsi,strlen(__imsi));
	//IMEI整体转ASCII 
	strnumber_to_asciistr(imei,__imei,strlen(__imei));
	printf("转化后的imsi:%s\n",imsi);
	printf("转化后的imei:%s\n",imei);
	sprintf(cmd_buf,"AT+QLWULDATAEX=57,01F00035000150FFFFFFCE%s%s00000166295B30700200040%d0001%d22,0x0100",imei,imsi,property+30,status+30);
	printf("拼接AT指令:\n%s\n",cmd_buf);
}
 
int main(void)
{
	int i ;
	char *_imei = "460111174556744";
	char *_imsi = "867726030069368";
	char imei[31];
	char imsi[31];
	char cmd_buf[150];
	char value = 0 ;
	int property = 0;
	int status = 1 ;
	printf("原来的imei:%s\n",_imei); 
	printf("原来的imsi:%s\n",_imsi); 
	Send_Data_To_easyiot(_imsi,_imei,1,1);
	return 0;	
} 
