/*
*      This file is part of the tknet project. 
*    which be used under the terms of the GNU General Public 
*    License version 3.0 as published by the Free Software
*    Foundation and appearing in the file LICENSE.GPL included 
*    in the packaging of this file.  Please review the following 
*    information to ensure the GNU General Public License 
*    version 3.0 requirements will be met: 
*    http://www.gnu.org/copyleft/gpl.html
*
*    Copyright  (C)   2012   Zhong Wei <clock126@126.com>  .
*/ 

#include <ansi_c.h>
#include "base64.h"
#include <windows.h> 
void Base64Encode(char *src, int src_len, char *dst)
{
	int i = 0, j = 0;
	char base64_map[65] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

	for (; i < src_len - src_len % 3; i += 3) 
	{
		dst[j++] = base64_map[(src[i] >> 2) & 0x3F];
		dst[j++] = base64_map[((src[i] << 4) & 0x30) + ((src[i + 1] >> 4) & 0xF)];
		dst[j++] = base64_map[((src[i + 1] << 2) & 0x3C) + ((src[i + 2] >> 6) & 0x3)];
		dst[j++] = base64_map[src[i + 2] & 0x3F];
	}

	if (src_len % 3 == 1) 
	{
		dst[j++] = base64_map[(src[i] >> 2) & 0x3F];
		dst[j++] = base64_map[(src[i] << 4) & 0x30];
		dst[j++] = '=';
		dst[j++] = '=';
	}
	else if (src_len % 3 == 2) 
	{
		dst[j++] = base64_map[(src[i] >> 2) & 0x3F];
		dst[j++] = base64_map[((src[i] << 4) & 0x30) + ((src[i + 1] >> 4) & 0xF)];
		dst[j++] = base64_map[(src[i + 1] << 2) & 0x3C];
		dst[j++] = '=';
	}

	dst[j] = '\0';
}
 
int unicode_to_utf8(char* szUnicode,char* dest,int dst_len) 
{ 

	int wcsLen = MultiByteToWideChar(CP_ACP, NULL, szUnicode, strlen(szUnicode), NULL, 0); 
	wchar_t wszString[5120];
	if(wcsLen + 1>5120 )
		return -1;

	MultiByteToWideChar(CP_ACP, NULL, szUnicode, strlen(szUnicode), wszString, wcsLen); 
	wszString[wcsLen] = '\0'; 

	int ansiLen = WideCharToMultiByte(CP_UTF8, NULL, wszString, wcslen(wszString), NULL, 0, NULL, NULL); 

	if(ansiLen+1 >dst_len)
		return -1;

	WideCharToMultiByte(CP_UTF8, NULL, wszString, wcslen(wszString), dest, ansiLen, NULL, NULL); 
	dest[ansiLen] = '\0'; 

	return ansiLen;
} 
