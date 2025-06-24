#include <unistd.h>
#include <stdarg.h>

#define my_putchar(x) write(1,chardup(x),1)

#define Wait4Char 1
#define Wait4Fmt  2

typedef unsigned char State;
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
  unsigned int len = my_strlen( str);
  if(len<0)return -1;
  return write(1,str,len);
}


int my_printf(const char *str, ...){
  va_list args;
  va_start(args,str);
  State state = Wait4Char;
  while(*str){
    if(state & Wait4Char){
      switch(*str){
        case '%':
          state = Wait4Fmt;
          break;
        case 10:
        case 13:
          if( (*(str +1) ==10)|| (*(str+1)==13) )str++;
          my_putchar(10);
          break;
        default:
          my_putchar(*str);
          break;
      }
    }
    else if(state & Wait4Fmt){
      switch(*str){
        case '%':
          my_putchar(*str);
          state = Wait4Char;
          break;
        case 's':
          puts(va_arg(args,  char*));
          state = Wait4Char;
          break;
        default:
          state= Wait4Char;
          (void)va_arg(args,char*);
          write(1, "💣", 4); 
          break;
      }
    }
    str++;
  }
  va_end(args);
  return 0;
}



int main(){
  char *str = "Hello,World ! \r\n";
  char *bye = "\nBye";
  int n = 10;
  my_printf("%sThis %x works?%s\r\n" , str , n , bye);
  return 0;
}
