  #define Row1_On digitalWrite(A1 , LOW);
   #define Row2_On digitalWrite(A2 , LOW);
   #define Row3_On digitalWrite(A3 , LOW);
   #define Row4_On digitalWrite(A4 , LOW);
   #define Row5_On digitalWrite(A5 , LOW);

   #define Row1_Off digitalWrite(A1 , HIGH);
   #define Row2_Off digitalWrite(A2 , HIGH);
   #define Row3_Off digitalWrite(A3 , HIGH);
   #define Row4_Off digitalWrite(A4 , HIGH);
   #define Row5_Off digitalWrite(A5 , HIGH);
   
volatile int button_pushed = 0;

void initialize();
void straight_text(int Array[]);
void Moving_Text(char string[], int slength);

void setup() {
  initialize();
}

void loop() {
  int i;
    //int I_Love_You_1[15] = {17,31,17,0,12,30,15,30,12,0,31,1,31,0,0};
    //int I_Love_You_2[15] = {0,17,31,17,0,12,30,15,30,12,0,31,1,31,0};
    //int I_Love_You_3[15] = {0,0,17,31,17,0,12,30,15,30,12,0,31,1,31};
    int blank[15] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    char string_1[] = "WHAT DOES THE LORD REQUIRE";
    char string_2[] = "ACT JUSTLY";
    char string_3[] = "LOVE MERCY";
    char string_4[] = "WALK HUMBLY";
    char string_5[] = "MICAH SIX EIGHT";

    if(button_pushed == 1)
    {
      goto loop;
    }
    Moving_Text(string_1, strlen(string_1));
    if(button_pushed == 1)
    {
      goto loop;
    }
    /*for(i = 0; i < 5; ++i)
    {
      straight_text(I_Love_You_1);
      straight_text(I_Love_You_2);
      straight_text(I_Love_You_3);
      straight_text(I_Love_You_2);
    }
    if(button_pushed == 1)
    {
      goto loop;
    }
    */
    straight_text(blank);
    straight_text(blank);
    Moving_Text(string_2, strlen(string_2));
    if(button_pushed == 1)
    {
      goto loop;
    }
    straight_text(blank);
    straight_text(blank);
    Moving_Text(string_3, strlen(string_3));
    if(button_pushed == 1)
    {
      goto loop;
    }
    straight_text(blank);
    straight_text(blank);
    Moving_Text(string_4, strlen(string_4));
    if(button_pushed == 1)
    {
      goto loop;
    }
    straight_text(blank);
    straight_text(blank);
    Moving_Text(string_5, strlen(string_5));
    if(button_pushed == 1)
    {
      goto loop;
    }
    straight_text(blank);
    straight_text(blank);


    while(button_pushed == 1)
    {
      loop:
        pinMode(3 , INPUT);
        digitalWrite(3 , HIGH);
        if(digitalRead(3) == 0)
        {
        button_pushed = 0;
        pinMode(3 , OUTPUT);
        digitalWrite(3 , LOW);
        delay(1000);
        }
    }

}

void initialize()
{
  int i;
  
   for(i = 2; i < 14; ++i)
    {
      pinMode(i , OUTPUT);
    }
   pinMode(0 , OUTPUT);
   pinMode(1 , OUTPUT);
   digitalWrite(0 , LOW);
   digitalWrite(1 , LOW);
   pinMode(A0 , OUTPUT);
   pinMode(A1 , OUTPUT);
   pinMode(A2 , OUTPUT);
   pinMode(A3 , OUTPUT);
   pinMode(A4 , OUTPUT);
   pinMode(A5 , OUTPUT);
   digitalWrite(A1 , HIGH);
   digitalWrite(A2 , HIGH);
   digitalWrite(A3 , HIGH);
   digitalWrite(A4 , HIGH);
   digitalWrite(A5 , HIGH);
}

void Col_On_Off(int Col_Num, int Value)
{
  
  if(Col_Num == 14)
  {
    digitalWrite(A0 , HIGH);
  }
  else
  {
    digitalWrite(Col_Num , HIGH);
  }

  short Row1 = Value >> 4;                           
  short Row2 = Value << 12; Row2 = Row2 >> 15;
  short Row3 = Value << 13; Row3 = Row3 >> 15;
  short Row4 = Value << 14; Row4 = Row4 >> 15;
  short Row5 = Value << 15; Row5 = Row5 >> 15;
  
  if(Row1)
  {
    Row1_On;
  }
  if(Row2)
  {
    Row2_On;
  }
  if(Row3)
  {
    Row3_On;
  }
  if(Row4)
  {
    Row4_On;
  }
  if(Row5)
  {
    Row5_On;
  }
  delayMicroseconds(20);
  Row1_Off;
  Row2_Off;
  Row3_Off;
  Row4_Off;
  Row5_Off;

    if(Col_Num == 14)
  {
    digitalWrite(A0 , LOW);
  }
  else
  {
    digitalWrite(Col_Num , LOW);
  }
  pinMode(3 , INPUT);
  digitalWrite(3 , HIGH);
  if(digitalRead(3) == 0)
  {
    button_pushed = 1;
  }
  pinMode(3 , OUTPUT);
  digitalWrite(3 , LOW);
  
}

void straight_text(int Array[])
{
  int i,j;

  for(i = 0; i < 150; ++i)
  {
    for(j = 0; j < 15; ++j)
    {
      Col_On_Off(j , Array[j]);
    }
  }
}

void Moving_Text(char string[], int slength)
{
  int Array[800];
  int Arrayelement = 0;
  int i;
  for(i = 0; i < 15; i++)
    {
      Array[Arrayelement] = 0; ++Arrayelement;
    }
  for(i = 0; i < slength; ++i)
  {
    if (string[i] == 'A')
    {
      Array[Arrayelement] = 31; ++Arrayelement;
      Array[Arrayelement] = 20; ++Arrayelement;
      Array[Arrayelement] = 31; ++Arrayelement;
    }
    if (string[i] == 'B')
    {
      Array[Arrayelement] = 31; ++Arrayelement;
      Array[Arrayelement] = 21; ++Arrayelement;
      Array[Arrayelement] = 10; ++Arrayelement;
    }
    if (string[i] == 'C')
    {
      Array[Arrayelement] = 31; ++Arrayelement;
      Array[Arrayelement] = 17; ++Arrayelement;
      Array[Arrayelement] = 17; ++Arrayelement;
    }
    if (string[i] == 'D')
    {
      Array[Arrayelement] = 31; ++Arrayelement;
      Array[Arrayelement] = 17; ++Arrayelement;
      Array[Arrayelement] = 14; ++Arrayelement;
    }
    if (string[i] == 'E')
    {
      Array[Arrayelement] = 31; ++Arrayelement;
      Array[Arrayelement] = 21; ++Arrayelement;
      Array[Arrayelement] = 21; ++Arrayelement;
    }
    if (string[i] == 'F')
    {
      Array[Arrayelement] = 31; ++Arrayelement;
      Array[Arrayelement] = 20; ++Arrayelement;
      Array[Arrayelement] = 20; ++Arrayelement;
    }
    if (string[i] == 'G')
    {
      Array[Arrayelement] = 31; ++Arrayelement;
      Array[Arrayelement] = 17; ++Arrayelement;
      Array[Arrayelement] = 7; ++Arrayelement;
    }
    if (string[i] == 'H')
    {
      Array[Arrayelement] = 31; ++Arrayelement;
      Array[Arrayelement] = 4; ++Arrayelement;
      Array[Arrayelement] = 31; ++Arrayelement;
    }
    if (string[i] == 'I')
    {
      Array[Arrayelement] = 17; ++Arrayelement;
      Array[Arrayelement] = 31; ++Arrayelement;
      Array[Arrayelement] = 17; ++Arrayelement;
    }
    if (string[i] == 'J')
    {
      Array[Arrayelement] = 17; ++Arrayelement;
      Array[Arrayelement] = 31; ++Arrayelement;
      Array[Arrayelement] = 16; ++Arrayelement;
    }
    if (string[i] == 'K')
    {
      Array[Arrayelement] = 31; ++Arrayelement;
      Array[Arrayelement] = 12; ++Arrayelement;
      Array[Arrayelement] = 23; ++Arrayelement;
    }
    if (string[i] == 'L')
    {
      Array[Arrayelement] = 31; ++Arrayelement;
      Array[Arrayelement] = 1; ++Arrayelement;
      Array[Arrayelement] = 1; ++Arrayelement;
    }
    if (string[i] == 'M')
    {
      Array[Arrayelement] = 31; ++Arrayelement;
      Array[Arrayelement] = 8; ++Arrayelement;
      Array[Arrayelement] = 4; ++Arrayelement;
      Array[Arrayelement] = 8; ++Arrayelement;
      Array[Arrayelement] = 31; ++Arrayelement;
    }
    if (string[i] == 'N')
    {
      Array[Arrayelement] = 31; ++Arrayelement;
      Array[Arrayelement] = 12; ++Arrayelement;
      Array[Arrayelement] = 6; ++Arrayelement;
      Array[Arrayelement] = 31; ++Arrayelement;
    }
    if (string[i] == 'O')
    {
      Array[Arrayelement] = 31; ++Arrayelement;
      Array[Arrayelement] = 17; ++Arrayelement;
      Array[Arrayelement] = 31; ++Arrayelement;
    }
    if (string[i] == 'P')
    {
      Array[Arrayelement] = 31; ++Arrayelement;
      Array[Arrayelement] = 20; ++Arrayelement;
      Array[Arrayelement] = 28; ++Arrayelement;
    }
    if (string[i] == 'Q')
    {
      Array[Arrayelement] = 31; ++Arrayelement;
      Array[Arrayelement] = 17; ++Arrayelement;
      Array[Arrayelement] = 31; ++Arrayelement;
      Array[Arrayelement] = 1; ++Arrayelement;
    }
    if (string[i] == 'R')
    {
      Array[Arrayelement] = 31; ++Arrayelement;
      Array[Arrayelement] = 22; ++Arrayelement;
      Array[Arrayelement] = 29; ++Arrayelement;
    }
    if (string[i] == 'S')
    {
      Array[Arrayelement] = 29; ++Arrayelement;
      Array[Arrayelement] = 21; ++Arrayelement;
      Array[Arrayelement] = 23; ++Arrayelement;
    }
    if (string[i] == 'T')
    {
      Array[Arrayelement] = 16; ++Arrayelement;
      Array[Arrayelement] = 31; ++Arrayelement;
      Array[Arrayelement] = 16; ++Arrayelement;
    }
    if (string[i] == 'U')
    {
      Array[Arrayelement] = 31; ++Arrayelement;
      Array[Arrayelement] = 1; ++Arrayelement;
      Array[Arrayelement] = 31; ++Arrayelement;
    }
    if (string[i] == 'V')
    {
      Array[Arrayelement] = 30; ++Arrayelement;
      Array[Arrayelement] = 1; ++Arrayelement;
      Array[Arrayelement] = 30; ++Arrayelement;
    }
    if (string[i] == 'W')
    {
      Array[Arrayelement] = 31; ++Arrayelement;
      Array[Arrayelement] = 2; ++ Arrayelement;
      Array[Arrayelement] = 4; ++Arrayelement;
      Array[Arrayelement] = 2; ++Arrayelement;
      Array[Arrayelement] = 31; ++Arrayelement;
    }
    if (string[i] == 'X')
    {
      Array[Arrayelement] = 27; ++Arrayelement;
      Array[Arrayelement] = 4; ++Arrayelement;
      Array[Arrayelement] = 27; ++Arrayelement;
    }
    if (string[i] == 'Y')
    {
      Array[Arrayelement] = 24; ++Arrayelement;
      Array[Arrayelement] = 7; ++Arrayelement;
      Array[Arrayelement] = 24; ++Arrayelement;
    }
    if (string[i] == 'Z')
    {
      Array[Arrayelement] = 19; ++Arrayelement;
      Array[Arrayelement] = 21; ++Arrayelement;
      Array[Arrayelement] = 25; ++Arrayelement;
    }
    if (string[i] == ' ')
    {
      Array[Arrayelement] = 0; ++Arrayelement;
      Array[Arrayelement] = 0; ++Arrayelement;
      Array[Arrayelement] = 0; ++Arrayelement;
    }
    Array[Arrayelement] = 0; ++Arrayelement;
  }
  
  for(i = 0; i < 15; i++)
  {
    Array[Arrayelement] = 0; ++Arrayelement;
  }

  int testvalue;
  int j,k;

    for (testvalue = 0; testvalue < Arrayelement - 15; testvalue++)
    {
       for(j = 0; j < 40; ++j)
       {
         for(k = 0, i = testvalue; k < 15; ++k, ++i)
         {
            Col_On_Off(k, Array[i]);
         }
       }
    }
}
