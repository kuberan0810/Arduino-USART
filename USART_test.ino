int UBRR_Val=0;
int transval=123,transval1=57;
int d1 = 48,d2=49,d3=50,d4=51,d5=52,d6=53,d7=54,d8=55,d9=56,d0=57,nl=10;
void setup() 
{
  DDRD &=~(1<<3);
  USART_Init(9600);   
}

void loop() 
{
  PORTD^=(1<<3);
  //transval1 = micros();
  USART_Transmit(transval1);
  //USART_print(transval);
  USART_Transmit(nl); 
  //transval1 = micros()-transval1;
  //Serial.println(transval1);
  //USART_Transmit(transval1);
  //delayMicroseconds(2000);
}
void USART_Init(unsigned int baud)
{
  UDR0=0;
  UBRR_Val = 16000000/16/baud-1;
  UBRR0H = (unsigned char)(UBRR_Val>>8);
  UBRR0L = (unsigned char)UBRR_Val;
  //UCSR0B = (1<<RXEN0)|(1<<TXEN0);
  //UCSR0C = (1<<USBS0)|(3<<UCSZ00);
  UCSR0B = (1<<4)|(1<<3);
  //UCSR0C = (1<<USBS0)|(3<<UCSZ00);
  UCSR0C = (1<<2)|(1<<1);
}
void USART_Transmit( unsigned char data )
{
  //if ( ( UCSR0A & (1<<UDRE0))>0 )
  while ( ( UCSR0A & (1<<5))<0 );
  //if ( ( UCSR0A & (1<<5))>0 )  
  UDR0 = data;
}
void USART_print( unsigned int printdata )
{
 int reverse=0,int_to_ASCII = 0;
 while (printdata != 0)
   {
      reverse = reverse * 10;
      reverse = reverse + printdata%10;
      printdata= printdata/10;
   }
 while (reverse != 0)
   {
      int_to_ASCII = reverse % 10;      
      switch(int_to_ASCII)
      {
        case 0:
        USART_Transmit(d1);
        break;
        case 1:
        USART_Transmit(d2);
        break;
        case 2:
        USART_Transmit(d3);
        break;
        case 3:
        USART_Transmit(d4);
        break;
        case 4:
        USART_Transmit(d5);
        break;
        case 5:
        USART_Transmit(d6);
        break;
        case 6:
        USART_Transmit(d7);
        break;
        case 7:
        USART_Transmit(d8);
        break;
        case 8:
        USART_Transmit(d9);
        break;
        case 9:
        USART_Transmit(d0);
        break;
        default:
        break;
      }
      reverse= reverse/10;
   } 
   USART_Transmit(nl); 
}

