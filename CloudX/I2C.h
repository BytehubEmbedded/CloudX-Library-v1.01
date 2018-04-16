#define I2C_Begin I2C_Init

MSSPWait(){
    while(!PIR1bits.SSPIF);
           PIR1bits.SSPIF=0;
}

void I2C_Start(){
   SSPCON2bits.SEN =1; //Generate START Condition
   MSSPWait();
}

void I2C_Repeated_Start(){
    SSPCON2bits.RSEN=1;
    while(SSPSTATbits.S==0);
    MSSPWait();
}

void I2C_Stop(){
    SSPCON2bits.PEN=1;
    while(SSPSTATbits.P==0);
    MSSPWait();
}

void I2C_Wr(unsigned char addressbyte){
                   SSPBUF = addressbyte;
                   MSSPWait();
                   while(SSPCON2bits.ACKSTAT);
}

I2C_Init(unsigned long I2C_BAUD){
    TRISCbits.TRISC3 =1;
    TRISCbits.TRISC4 =1;
    SSPCON =  0b00101000;
    SSPSTAT = 0b10000000;
    SSPADD =  (20000000 / (4 * I2C_BAUD)) - 1;
	}
	
I2C_Read(){
      SSPCON2bits.RCEN = 1;
      MSSPWait();
      SSPCON2bits.ACKDT =1;
      SSPCON2bits.ACKEN =1;
      SSPCON2bits.PEN =1;
      MSSPWait();
      return SSPBUF;
}