#include <unistd.h>

char *chardup(const char ch){
  static char buff[2];
  char* p;
  p=buff;
  *p++=ch;
  *p--=0;
  return buff;
}

unsigned int strlen(const char *str){
  unsigned int count;
  char *p;
  for(p=str,count=0;*p;p++,count++);
  return count;
} 

int puts(const  char *str){
  unsigned len = strlen( str);
  if(len<0)return -1;
  return write(1,str,len);
}
