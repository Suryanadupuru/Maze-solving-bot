int s1,s2,s3,s4,s5,s6,s7,s8,r1,dry[100],i=0,j,l,k=0,n,a=65,t=85,g=150;

void setup()
{
  pinMode(6,INPUT);
  pinMode(7,INPUT);
  pinMode(8,INPUT);
  pinMode(9,INPUT);
  pinMode(10,INPUT);
  pinMode(11,INPUT);
  pinMode(12,INPUT);
  pinMode(13,INPUT);
  pinMode(22,INPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(14,OUTPUT);
  pinMode(15,OUTPUT);
  pinMode(A1,OUTPUT);
  pinMode(A2,OUTPUT);
  Serial.begin(9600);
  delay(2000);
}
void loop()
{
  while (1)
  {
    reading();
    if(s1==0 && s3==0 && s4==1 && s5==1 && s6==0 && s8==0)
    {
      go();
    }
    //ajst right
    else if(s1==0 && s3==0  && s5==1 && s6==1 && s8==0)
    {
       ajstr();
       continue;
    }
    //ajst left
    else if(s1==0 && s3==1 && s4==1 && s6==0 && s8==0)
    {
       ajstl();
       continue;
    }
    //left turn
    else if(s1==1 && s3==1  && s4==1 && s8==0)
    {
      check();
      if (s1==0&& s3==0 && s4==0 && s5==0 && s6==0 && s8==0)
      {
        left();
        continue;
      }
      else if (s1==1  && s3==1 && s4==1 && s5==1 && s6==1 && s8==1)
      {
         stopme();
        analogWrite(A1,0);
        break;
      }
      else if (s1==0 && s4==1 && s5==1 && s8==0)
      {
        left();
        Serial.print('L');
        dry[i]=1;
        i=i+1;
        continue;                                                                     
      }
      continue;
    }
    //right turn
    else if(s1==0 && s2==0 && s5==1 && s6==1 && s8==1)
    {
      check();
      if (s1==0 && s3==0 && s4==0 && s5==0 && s6==0 && s8==0)
      {
        right();
        continue;
      }
       else if (s1==1 && s3==1 && s4==1 && s5==1 && 6==1 && s8==1)
      {
         stopme();
        analogWrite(A1,0);
        break;
      }
      else
      {
        Serial.print('S');
        dry[i]=2;
        i=i+1;
        continue;
      }
      continue;
    }
    else if(s1==1 && s3==1 && s4==1 && s5==1 && s6==1 && s8==1)
    {
      check();
      if (s1==1 && s3==1 && s4==1 && s5==1 && s6==1 && s8==1)
      {
        stopme();
        analogWrite(A1,0);
        break;
      }
      else
      {
        left();
        Serial.print('L');
        dry[i]=1;
        i=i+1;
      }
      continue;
    }
    else if (s1==0 && s3==0 && s4==0 && s5==0 && s6==0 && s8==0)
    {
      delay(2);
      reading();
      if (s1==0 && s3==0 && s4==0 && s5==0 && s6==0 && s8==0)
     {
      back();
       Serial.print('B');
      dry[i]=4;
      i=i+1;
     }
    }
//    else if (r1==1)
  //  {
    //  backed();
      //dry[i]=4;
     // i=i+1;
    //}
  }
simply();
  delay(500);
for(l=0;l<=i;l=l+1)
  {
    Serial.print(dry[l]);
  }
   //actual
 analogWrite(A1,150);
 delay(100);
 analogWrite(A1,0);
actual();
 
}
void ajstr()
{
    analogWrite(2,a-7);
    digitalWrite(3,0);
    analogWrite(4,0);
    digitalWrite(5,0);
}
void ajstl()
{
    analogWrite(2,0);
    digitalWrite(3,0);
    analogWrite(4,a);
    digitalWrite(5,0); 
}
void right()
{
  while(1)
  {
    analogWrite(2,t-7);
    digitalWrite(3,0);
    digitalWrite(4,0);
    analogWrite(5,t);
    reading();
      if (s1==0 && s3==0 && s4==1 && s5==1 && s8==0)
      {
        break;
      }
  }
}
void left()
{
    digitalWrite(2,0);
    analogWrite(3,t-7);
    analogWrite(4,t);
    digitalWrite(5,0);
    delay(200);
  while(1)
  {
    digitalWrite(2,0);
    analogWrite(3,t-7);
    analogWrite(4,t);
    digitalWrite(5,0);
    reading();
      if (s1==0 && s4==1 && s5==1 && s6==0 && s8==0)
      {
        break;
      }
  }
}
void back()
{
  while(1)
  {
    analogWrite(3,t);
    digitalWrite(2,0);
    digitalWrite(5,0);
    analogWrite(4,t);
    reading();
    if (s1==0 && s3==0 && s4==1 && s5==1 && s8==0)
    {
      break;
    }
  }
}
  void backed()
{
    analogWrite(2,0);
    digitalWrite(3,t);
    digitalWrite(4,0);
    analogWrite(5,t);
    delay (150);
  while(1)
  {
    analogWrite(3,t);
    digitalWrite(2,0);
    digitalWrite(5,0);
    analogWrite(4,t);
    reading();
    if (s1==0 && s3==0 && s4==1 && s5==1 && s8==0)
    {
      break;
    }
  }
}
void go()
{
  analogWrite(2,g-7);
  digitalWrite(3,0);
  analogWrite(4,g);
  digitalWrite(5,0);
}
void stopme()
{
  digitalWrite(2,0);
  digitalWrite(3,0);
  digitalWrite(4,0);
  digitalWrite(5,0);
  analogWrite(A1,150);
  delay (5000);
}
void check()
{
  analogWrite(2,t-7);
  digitalWrite(3,0);
  analogWrite(4,t);
  digitalWrite(5,0);
  delay(400);
  reading();
}
void reading()
{
    s8=digitalRead(6);
    s7=digitalRead(7);
    s6=digitalRead(8);
    s5=digitalRead(9);
    s4=digitalRead(10);
    s3=digitalRead(11);
    s2=digitalRead(12);
    s1=digitalRead(13);
    r1=digitalRead(22);
}
void arr()
{
  for (n=j+1;n<=i;n=n+2)
  {
    dry[n]=dry[n+2];
    dry[n+1]=dry[n+3];
  }
}
void simply()
{
 for (j=0;j<i-1;)
  {
    if (j==0 && dry[j]==4)
    {
      for (n=j+1;n<i;n=n+1)
       {
         dry[n]=dry[n+1];
         i=i-1;
       } 
      j=j+1;
    }
    else if (dry[j]==1 && dry[j+1]==4 && dry[j+2]==2)
    {
      dry[j]=3;
      arr();
      j=j+1;
      continue;
    }
    else if (dry[j]==2 && dry[j+1]==4 && dry[j+2]==1)
    {
      dry[j]=3;
      arr();
      j=j+1;
      continue;
    }
    else if (dry[j]==1 && dry[j+1]==4 && dry[j+2]==1)
    {
      dry[j]=2;
      arr();
      j=j+1;
      continue;
    }
    else if (dry[j]==1 && dry[j+1]==4 && dry[j+2]==3)
    {
      dry[j]=4;
      arr();
      j=j-1;
      continue;
    }
    else if (dry[j]==3 && dry[j+1]==4 && dry[j+2]==1)
    {
      dry[j]=4;
      arr();
      j=j-1;
      continue;
    }
    else if (dry[j]==2 && dry[j+1]==4 && dry[j+2]==2)
    {
      dry[j]=4;
      arr();
      j=j-1;
      continue;
    }
    else if (dry[j]==4)
    {
      j=j-1;
      continue;
    }
    else 
    {
      j=j+1;
    }
  }
}
void act()
{
  if (dry[k]==1)
  {
    left();
    k=k+1;
  }
  else if (dry[k]==2)
  {
    //straight();
    k=k+1;
  }
  else if (dry[k]==3)
  {
    right();
     k=k+1;
  }
}
void actual()
{
   while (1)
  {
    reading();
     if(s1==0 && s3==0 && s4==1 && s5==1 && s6==0 && s8==0)
    {
      go();
    }
    //ajst right
    else if(s1==0 && s3==0 && s5==1 && s6==1 && s8==0)
    {
       ajstr();
       continue;
    }
    //ajst left
    else if(s1==0 && s3==1 && s4==1 && s6==0 && s8==0)
    {
       ajstl();
       continue;
    }
    //left turn
    else if(s1==1 && s3==1 && s4==1 && s8==0)
    {
      check();
      if (s1==0 && s3==0 && s4==0 && s5==0 && s6==0 && s8==0)
      {
        left();
        continue;
      }
       else if (s1==1 && s3==1 && s4==1 && s5==1 && s6==1 && s8==1)
      {
         stopme();
        analogWrite(A1,0);
        break;
      }
      else if (s1==0 && s4==1 && s5==1 && s8==0)
      {
        act();
        continue;
      }
      continue;
    }
    //right turn
    else if(s1==0 && s5==1 && s6==1 && s8==1)
    {
      check();
      if (s1==0 && s3==0 && s4==0 && s5==0 && s6==0 && s8==0)
      {
        right();
        continue;
      }
       else if (s1==1 && s3==1 && s4==1 && s5==1 && s6==1 && s8==1)
      {
         stopme();
        analogWrite(A1,0);
        break;
      }
      else
      {
        act();
        continue;
      }
      continue;
    }
    else if(s1==1 && s3==1 && s4==1 && s5==1 && s6==1 && s8==1)
    {
      check();
      if (s1==1 && s3==1 && s4==1 && s5==1 && s6==1 && s8==1)
      {
        stopme();
        analogWrite(A1,0);
        break;
      }
      else
      {
        act();
      }
    }
    else if (s1==0 && s3==0 && s4==0 && s5==0 && s6==0 && s8==0)
     {
      back();
     }
 //   else if (r1==1)
   // {
     // backed();
    //}
  }
}

