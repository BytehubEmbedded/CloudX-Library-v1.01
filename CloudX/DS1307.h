#include <CloudX\I2C.h>

unsigned short read_ds1307(unsigned short address)
{
  unsigned short r_data;
  I2C_Start();
  I2C_Wr(0xD0);
  I2C_Wr(address);
  I2C_Repeated_Start();
  I2C_Wr(0xD1);
  r_data=I2C_Read();
  I2C_Stop();
  return(r_data);
}


void write_ds1307(unsigned short address,unsigned short w_data)
{
  I2C_Start();
  I2C_Wr(0xD0);
  I2C_Wr(address);
  I2C_Wr(w_data);
  I2C_Stop();
}


unsigned char BCD2UpperCh(unsigned char bcd)
{
  return ((bcd >> 4) + '0');
}


unsigned char BCD2LowerCh(unsigned char bcd)
{
  return ((bcd & 0x0F) + '0');
}

char Binary2BCD(byte aa)
{
   char t1, t2;
   t1 = aa%10;
   t1 = t1 & 0x0F;
   aa = aa/10;
   t2 = aa%10;
   t2 = 0x0F & t2;
   t2 = t2 << 4;
   t2 = 0xF0 & t2;
   t1 = t1 | t2;
   return t1;
}


char BCD2Binary(byte aa)
{
   char rr,tt;
   tt = aa & 0x0F;
   rr = tt;
   aa = 0xF0 & aa;
   tt = aa >> 4;
   tt = 0x0F & tt;
   rr = tt*10 + rr;
   return rr;
}
