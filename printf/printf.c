#include <unistd.h>
#include <stdarg.h>

#define my_putchar(x) write(1,chardup(x),1)

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


int my_printf(const char *str, ...){
  va_list args;
  va_start(args,str);
  while(*str){
    if(*str=='%' && *(str+1)=='s'){
      str+=2;
      char* s = va_arg(args,char *);
      puts(s);
    }
    else{
      my_putchar(*str++);
    }
  }
  va_end(args);
  return 0;
}



int main(){
  char * s = "somehow";
  my_printf("This %s works  \n",s);
  return 0;
}
