#include <stdio.h>
#include "pico/stdlib.h"

int main() {
  stdio_init_all();
  
  for(char i=0;i<3;i++){
    gpio_init(i);
    gpio_set_dir(i,false);

  }
  for(char i=3;i<11;i++){
    gpio_init(i);
    gpio_set_dir(i,true);
  }

  int e = 0;
  int numero=0x70;

  while (true) {

    if (e== 0){
      numero= 0x7e;
    }
    if (e== 1){
      numero= 0x30;
    }
    if (e== 2){
      numero= 0x6d;
    }
    if (e== 3){
      numero= 0x79;
    }
    if (e== 4){
      numero= 0x33;
    }
    if (e== 5){
      numero= 0x5b;
    }
    if (e== 6){
      numero= 0x5f;
    }
    if (e== 7){
      numero= 0x70;
    }
    if (e== 8){
      numero= 0x7f;
    }
    if (e== 9){
      numero= 0x73;
    }
  
    for(char i=0;i<7;i++){
      bool salida = numero&(1<<(6-i));
      char pin = 3+i  ;
      gpio_put(pin,salida);    
    }
    sleep_ms(500);
  }
}
