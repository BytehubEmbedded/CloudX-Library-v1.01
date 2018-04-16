
#define Clear 0
#define Set 1
#define Invert 2

#define Black 0xFF
#define White Clear


char RSS,ENN,RWW,CS11,CS22,RSTT,pports;
void glcdSettings(char RSS1,char RWW1,char ENN1,char CS111,char CS222,char RSTT1,char portss){
    pinMode(RSS1,OUTPUT); pinMode(ENN1,OUTPUT); pinMode(CS111,OUTPUT); pinMode(CS222,OUTPUT); pinMode(RSTT1,OUTPUT); pinMode(RWW1,OUTPUT);
   RSS = RSS1; ENN= ENN1;  RWW= RWW1; CS11=CS111; CS22=CS222; RSTT=RSTT1;
   portMode(portss,OUTPUT);
   pports=portss;
   }

#define RS RSS
#define EN ENN
#define RW RWW
#define CS1 CS11
#define CS2 CS22
#define RST RSTT
#define port pports
void GLCD_ENABLE()
{
    digitalWrite(EN,1);
    __delay_us(1);
    digitalWrite(EN,0);
    __delay_us(1);
}


void GLCD_START_ROW(unsigned char row){
    digitalWrite(RS,0);
    digitalWrite(RW,0);
    portWrite(port,(0xB8 | row));
    GLCD_ENABLE();
    portWrite(port,0x00);
}

void clearCmd(){
     digitalWrite(CS1,0); digitalWrite(CS2,0);
     digitalWrite(RS,0);
     digitalWrite(RW,0);
    portWrite(port,0xC0);
    GLCD_ENABLE();
    portWrite(port,0x00);

}
void GLCD_START_ROW_LINE(unsigned char row){
    digitalWrite(RS,0);
    digitalWrite(RW,0);
    portWrite(port,(0xC0 | row));
    GLCD_ENABLE();
    portWrite(port,0x00);

}



void GLCD_START_COL(unsigned char col){
    digitalWrite(RS,0);
    digitalWrite(RW,0);
    if(col < 64){
        digitalWrite(CS1,0);
        digitalWrite(CS2,1);
    }
    else {
        digitalWrite(CS1,1);
        digitalWrite(CS2,0);
        col = col-64;
    }
    portWrite(port,(col | 0x40));
    GLCD_ENABLE();
    portWrite(port,0x00);
}

void glcdWrite(char row1,unsigned char col1,unsigned char chr,char levell){

    if(col1>128);
    else{ GLCD_START_COL(col1);
    switch (levell)
    {
        case 0:  GLCD_START_ROW_LINE(row1); break;
        case 1:  GLCD_START_ROW(row1);      break;
    }
    
    digitalWrite(RS,1);
    digitalWrite(RW,0);
    portWrite(port,chr);
    GLCD_ENABLE();
    }
    portWrite(port,0x00);
   
}


void xglcdWrite(const unsigned short *table1, unsigned char FontLength, char FontHeight, char roww, char coll, unsigned char chrr, char dispTyper){
     unsigned char pos_x=0, ByteChar=0,TempRow;
     unsigned int YFontHeight, XFontLength,xFont;
     // ByteChar = FONT_5x7[((chrr - 0x20)*width) + pos_x];
    // xFont =  ((FontLength/8)+1);
     xFont = (FontHeight/8)+1;
           FontLength = FontLength * xFont;
           XFontLength = table1[(chrr - 0x20)* (FontLength+1)];  //length of font
            while(pos_x<(XFontLength*xFont)){
                TempRow = roww;
                 YFontHeight = FontHeight/8;  //height of Font
           YFontHeight= YFontHeight+1;
    while (YFontHeight--!=0){
           ByteChar = table1[((chrr - 0x20)* (FontLength+1)) + ++pos_x];
        switch(dispTyper){
            case Clear: ByteChar= ~ByteChar; break;
            case Set:   ByteChar = ByteChar;  break;
        }
        glcdWrite(TempRow++,coll, ByteChar,1);
    }
                coll++;
}
           
}

void xglcdWriteText(const unsigned short *table1, unsigned char width, char length, unsigned row, unsigned col,unsigned char *txt, char dispType)
{                  unsigned char LineSpacing;
    unsigned char pnt=0;
            while (txt[pnt] != '\0') {
            xglcdWrite(table1, width, length, row,col,txt[pnt], dispType);
            LineSpacing = table1[(txt[pnt++] - 0x20)* ((width*((length/8)+1))+1)];
            col = col+LineSpacing+2;
            }
}





void GLCD_WRITE_CHAR(const unsigned short *table1, unsigned char width, char length, char roww, char coll, unsigned char chrr, char dispTyper)
{
     unsigned char pos_x=0, ByteChar=0;
     // ByteChar = FONT_5x7[((chrr - 0x20)*width) + pos_x];
    while(pos_x<width){
      //  ByteChar = table1[chrr - 0x20][pos_x];
         ByteChar = table1[((chrr - 0x20)*width) + pos_x];
        switch(dispTyper){
            case Clear: ByteChar= ~ByteChar; break;
            case Set:   ByteChar = ByteChar;  break;
        }
        glcdWrite(roww,coll+pos_x++, ByteChar,1);
    }
}

void GLCD_WRITE_DATA_CHAR(const unsigned short *table1, unsigned char width, char length, char roww, char coll, unsigned char chrr, char dispTyper)
{
     unsigned char pos_x=0, ByteChar=0;
     // ByteChar = FONT_5x7[((chrr - 0x20)*width) + pos_x];
    while(pos_x<width){
      //  ByteChar = table1[chrr - 0x20][pos_x];
         ByteChar = table1[((chrr - 0x20)*width) + pos_x];
        switch(dispTyper){
            case Clear: ByteChar= ~ByteChar; break;
            case Set:   ByteChar = ByteChar;  break;
        }
        glcdWrite((63-roww),coll+pos_x++, ByteChar,0);
    }
}


void glcdWriteText(const unsigned short *table1, unsigned char width, char length, unsigned row, unsigned col,unsigned char *txt, char dispType)
{
    unsigned char pnt=0;
            while (txt[pnt] != '\0') {
           
               xglcdWrite(table1, width, length, row,col,txt[pnt++], dispType);
            col = col + width+1;
            }
}

void GLCD_WRITE_DATA_TEXT(const unsigned short *table1, unsigned char width, char length, unsigned char row, unsigned char col,unsigned char *txt, char dispType)
{
    unsigned char pnt=0;
            while (txt[pnt] != '\0') {
                 
                   GLCD_WRITE_DATA_CHAR(table1, width, length, row,col,txt[pnt++], dispType);
            col = col + width+1;
            }
}



void GLCD_DISPLAY_ON(void){
    digitalWrite(CS1,1);
    digitalWrite(CS2,1);
    digitalWrite(RS,0);
    digitalWrite(RW,0);
    portWrite(port,0x3F);
    GLCD_ENABLE();
    portWrite(port,0x00);
}


void glcdFill_Screen(unsigned char clr){
    unsigned char x=0,y=0;
    clearCmd();
    for(y=0; y<8; y++){
          glcdWrite(y,0,clr,1);
        for(x=0; x<128; x++)
           glcdWrite(y,x,clr,1);
    }
}

void glcdFill(unsigned char clr,unsigned char page,unsigned char FromX, unsigned char toX ){
         clearCmd();
          while(FromX<toX)
            glcdWrite(page,FromX++,clr,1);
    
}

void glcdDrawRectangle(char FromX, char FromY, char toX,char  toY){
    unsigned char x,y;
    for(y=FromY; y<toY; y++){
        for(x=FromX; x<toX; x++){
            glcdWrite(y,x,0x40,0);
        }
    }
}

void glcd_Image(const char *image){
    unsigned int ImagePnter=0,ImageYPnter=0,ImageCounter=0;
    while(ImageCounter < 1024) {
        glcdWrite(ImageYPnter,ImagePnter,image[(128*ImageYPnter) + ImagePnter],1);
        ImagePnter++; ImageCounter++;
          if(ImagePnter>=128){
            ImageYPnter++;
           ImagePnter=0;
        }
    }
    
}

void glcdSetting(char RSS1,char RWW1,char ENN1,char CS111,char CS222,char RSTT1,char portss){
    pinMode(RSS1,OUTPUT); pinMode(ENN1,OUTPUT); pinMode(CS111,OUTPUT); pinMode(CS222,OUTPUT); pinMode(RSTT1,OUTPUT); pinMode(RWW1,OUTPUT);
   RSS = RSS1; ENN= ENN1;  RWW= RWW1; CS11=CS111; CS22=CS222; RSTT=RSTT1;
   portMode(portss,OUTPUT);
   pports=portss;
       digitalWrite(RST ,1);
       GLCD_DISPLAY_ON();
       glcdFill_Screen(0);
}


void Glcd_Image_Write(const char *ImgWr,unsigned int ImgWrLength, unsigned int ImgWrHeight, unsigned int posX,unsigned int posY){
        unsigned int ImageXPnter=posX,ImageYPnter=posY,ImageCounter=0,PickerX=0,PickerY=0;
           while(ImageCounter < (((ImgWrHeight/8)+1)*ImgWrLength)) {
           glcdWrite(ImageYPnter,ImageXPnter,ImgWr[(ImgWrLength*PickerY) + PickerX++],1);
        ImageXPnter++; ImageCounter++;
          if(ImageXPnter>=(ImgWrLength + posX)){
            ImageYPnter++; PickerY++;
           ImageXPnter=posX; PickerX=0;
        }

      }
}
