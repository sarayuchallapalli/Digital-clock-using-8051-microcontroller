#define datalines P2
sbit rs=P3^0;
sbit en=P3^1; 

// user function declaration
void lcd_cmd(unsigned char);  // controlling
void lcd_data(unsigned char);  //8 bit data display
void lcd_init(void);  // initialzation 
void lcd_string(unsigned char []);   // string display
void delay(unsigned int);   // delay
void lcd_number(unsigned long);

//user function defination
void lcd_cmd(unsigned char ch){
 datalines=ch;
 rs=0;
 en=1;
 delay(10);
 en=0;
} 
void lcd_data(unsigned char ch){
 datalines=ch;
 rs=1;
 en=1;
 delay(10);
 en=0;
} 
void delay(unsigned int ch){
 int a,b;
 for(a=0;a<ch;a++)
 for(b=0;b<1000;b++);
}
void lcd_init(void){
 lcd_cmd(0x38); //lcd in 8bit mode
 lcd_cmd(0x02); //return to home
 lcd_cmd(0x06);  //inc cursor shift right
 lcd_cmd(0x0c); // cursor off display on
}
void lcd_string(unsigned char ch[]){
 int x;
 for(x=0; ch[x]!='\0'; x++){
  lcd_data(ch[x]);
 }
}
void lcd_number(unsigned long ch){
 int x=0,y[10];
 while(ch>0){
  y[x]=ch%10;
  ch=ch/10;
  x++;
 }
 while(x>0){
  x--;
  lcd_data(y[x]+48);
 }
}