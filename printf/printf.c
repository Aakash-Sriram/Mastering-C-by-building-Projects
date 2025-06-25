#include "helper.h"
#include "printf.h"
void itoa(int value , char* buffer , int base, int Cap){
  int index = 0;
  char str[1024];
  if(value==0){
    str[index++]='0';
    str[index]='\0';
  }

  char cap;
  while(value>0){
        if(Cap)cap ='A';else cap ='a';
        str[index++] = ( (value%base)<10 )?'0'+ (value%base): ( (value%base) - 10 )+ cap;
        value/=base;
  }
  str[index]='\0';

  for(int i=0;i<index;i++){
        buffer[i]=str[index-i-1]; 
  }
  buffer[index]='\0';
  
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
          if(*str==10)my_putchar(10);
          break;
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
      char buffer[2048];
      int ind =0;
      switch(*str){
        case '%':
          my_putchar(*str);
          state = Wait4Char;
          break;
        case 's':
          puts(va_arg(args,  char*));
          state = Wait4Char;
          break;
        case 'c':
          my_putchar((char)va_arg(args,int));
          state = Wait4Char;
          break;
        case 'd':
          ind =0;
          itoa( va_arg(args,int) , buffer , 10 ,1);
          while(buffer[ind]){
            my_putchar(buffer[ind++]);
          }
          state =Wait4Char;
          break;
        case 'x':
          ind = 0;
          itoa( va_arg(args,int) , buffer , 16 ,0);
          while(buffer[ind]){
            my_putchar(buffer[ind++]);
          }
          state =Wait4Char;
          break;
        case 'X':
          ind = 0;
          itoa( va_arg(args,int) , buffer , 16 ,0);
          while(buffer[ind]){
            my_putchar(buffer[ind++]);
          }
          state =Wait4Char;
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



