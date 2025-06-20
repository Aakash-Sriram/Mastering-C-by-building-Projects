#include <unistd.h>

char *chardup(const char ch){
  static char buff[2];
  char* p;
  p=buff;
  *p++=ch;
  *p--=0;
  return buff;
}

unsigned int my_strlen(const char *str){
  unsigned int count;
  const char *p;
  for(p=str,count=0;*p;p++,count++);
  return count;
} 

int puts(const  char *str){
  unsigned len = my_strlen( str);
  if(len<0)return -1;
  return write(1,str,len);
}

int main(){
// puts("Hello\n");
  char * ptr = chardup('H');
  puts(ptr);
  return 0;
}
