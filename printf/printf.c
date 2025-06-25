#include "helper.h"
#include "printf.h"
void itoa(int value , char* buffer , int base, int Cap){
  int index = 0;
  char str[1024];
  if(value==0){
    buffer[index++]='0';
    buffer[index]='\0';
  }
  int isNeg =0;
  if(value<0 && base==10){
    value = -value;
    isNeg =1;  
  }
  char cap;
  while(value>0){
        int digit = value%base;
        if(Cap)cap ='A';else cap ='a';
        str[index++] = ( digit<10 )? '0'+ digit: ( digit - 10 )+ cap;
        value/=base;
  }

  if(isNeg)str[index++]='-';

  str[index]='\0';

  for(int i=0;i<index;i++){
        buffer[i]=str[index-i-1]; 
  }
  buffer[index]='\0';
  
}
void ftoa(float value , char* buffer , char prec){
  int index=my_strlen(buffer);
  int integer = (int)value;
  float floAT = value - integer;
  floAT = (floAT<0)?-floAT:floAT;
  itoa(integer,buffer,10,0);
  index=my_strlen(buffer);
  buffer[index++]='.';
  int max_limit = prec - '0';
  max_limit =(max_limit>8)?8:max_limit;
  for(int i=0;i<max_limit;i++){
    floAT*=10;
    int digit = (int)floAT ;
    buffer[index++]='0'+digit;
    floAT-=digit;

    if(floAT < 1e-10 && floAT > -1e-10)break;
    /* 
     * floAT may or may not reach 0 
     * or if it somehow reaches negative value due to float precision it might lead to a infinite loop 
     * so break the loop when its close enough
     * 
     */
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
        case 'f':
          ind =0;
          ftoa( va_arg(args,double),buffer,'4');
          while(buffer[ind]){
            my_putchar(buffer[ind++]);
          }
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



