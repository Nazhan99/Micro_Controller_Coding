#define LATCH_DIO 4
#define CLK_DIO 7
#define DATA_DIO 8

//segment data from 0-9
const byte SEGMENT_MAP[]={192,249,164,176,153,146,130,248,128,152}; //MSB FIRST

const byte SEGMENT_SELECT[]={0xF1,0xF2,0xF4,0xF8}; //MSB FIRST

void setup() 
{
  pinMode(LATCH_DIO,OUTPUT); pinMode(CLK_DIO,OUTPUT); pinMode(DATA_DIO,OUTPUT);
  
}

void WriteNumber(byte Segment, byte Value)
{
  digitalWrite(LATCH_DIO,LOW);
  shiftOut(DATA_DIO,CLK_DIO,MSBFIRST, SEGMENT_MAP[Value]); //0-9
  shiftOut(DATA_DIO,CLK_DIO,MSBFIRST, SEGMENT_MAP[Segment]); //segment 0,1,2,3
  digitalWrite(LATCH_DIO,LOW);
}


void loop() 
{
  //1234
  WriteNumber(0,5);
  WriteNumber(1,5);
  WriteNumber(2,5);
  WriteNumber(3,5);
  
}
