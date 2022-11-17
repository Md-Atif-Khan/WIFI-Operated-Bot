/*
   PWM codes have been commented out and can be uncommented to use anytime
   PWM can be set according to the need
*/

#include <WiFi.h>
WiFiClient client;
WiFiServer server(80);

int i, j;
//LEFT_MOTOR:
int LM1 = 15;
int LM2 = 2;
//int LME = 3;

//RIGHT_MOTOR:
int RM1 = 4;
int RM2 = 5;
//int RME = 6;

void setup()
{
  Serial.begin(115200);
  WiFi.softAP("CRUCIFIERS", "1234567890");
  Serial.println();
  Serial.println("Wifi is connected");
  Serial.println(WiFi.softAPIP());
  Serial.println(WiFi.localIP());// IT WILL PRINT IP ADDRESS
  server.begin();

  // digitalWrite(LM2,HIGH);
  //  digitalWrite(RM1,HIGH);
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  // pinMode(LME, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
  // pinMode(RME, OUTPUT);
}

void loop()
{
  client = server.available();

  if (client)
  {
    String request =  client.readStringUntil('\n');


    //          Serial.println(request);
    request.trim();

    //BACKWARD:
    if (request == "GET /move?dir=BACKWARD HTTP/1.1")
    { digitalWrite(LM1, HIGH);
      digitalWrite(LM2, LOW);
      digitalWrite(RM1, HIGH);
      digitalWrite(RM2, LOW);
      Serial.println("BACKWARD");
    }

    /* CODE IF WE WANT TO USE PWM */

    /* for(i=1,j=1; i<256,j<256; i+=20,j+=20)
       {
         analogWrite(LME,i);
         analogWrite(RME,j);
         delay(1000);
          if(i>200 || j>200)
         {
           while(true)
           {
             analogWrite(LME,255);
             analogWrite(RME,255);
           }
         }
       } */

    //FORWARD:
    if (request == "GET /move?dir=FORWARD HTTP/1.1")
    {
      digitalWrite(LM1, LOW);
      digitalWrite(LM2, HIGH);
      digitalWrite(RM1, LOW);
      digitalWrite(RM2, HIGH);
    }


    /* CODE IF WE WANT TO USE PWM */
    /*for(i=0,j=0; i<256,j<256; i+=20,j+=20)
      {
        analogWrite(LME,i);
        analogWrite(RME,j);
        delay(1000);
        if(i>200 || j>200)
        {
          while(true)
          {
            analogWrite(LME,255);
            analogWrite(RME,255);
          }
        }
      } */

    //BACKWARD+BUMP:
    if (request == "GET /move?dir=BACKWARD_BUMP HTTP/1.1")
    {
      digitalWrite(LM1, HIGH);
      digitalWrite(LM2, LOW);
      digitalWrite(RM1, HIGH);
      digitalWrite(RM2, LOW);
    }


    /* CODE IF WE WANT TO USE PWM */
    /*
       for(i=0,j=0; i<256,j<256; i+=80,j+=80)
         {
           analogWrite(LME,i);
           analogWrite(RME,j);
           delay(1000);
           if(i>200 || j>200)
           {
             while(true)
             {
               analogWrite(LME,255);
               analogWrite(RME,255);
             }
           }
         } */

    //RIGHT:
    if (request == "GET /move?dir=RIGHT HTTP/1.1")
    {
      digitalWrite(LM1, LOW);
      digitalWrite(LM2, HIGH);
      digitalWrite(RM1, LOW);
      digitalWrite(RM2, LOW);
    }


    /* CODE IF WE WANT TO USE PWM */
    /*  for(i=0; i<256; i+=20)
        {
          analogWrite(LME,i);
          delay(1000);
          if(i>200)
          {
            while(true)
            {
              analogWrite(LME,255);
            }
          }
        } */

    //LEFT:
    if (request == "GET /move?dir=LEFT HTTP/1.1")
    {
      digitalWrite(LM1, LOW);
      digitalWrite(LM2, LOW);
      digitalWrite(RM1, LOW);
      digitalWrite(RM2, HIGH);
    }

    /* CODE IF WE WANT TO USE PWM */
    /*
      for(i=0; i<256; i+=20)
      {
        analogWrite(RME,i);
        delay(1000);
        if(i>200)
        {
          while(true)
          {
            analogWrite(RME,255);
          }
        }
      }  */


    //RIGHT_FORWARD:
    if (request == "GET /move?dir=RIGHT_FORWARD HTTP/1.1")
    {
      digitalWrite(LM1, LOW);
      digitalWrite(LM2, HIGH);
      digitalWrite(RM1, LOW);
      digitalWrite(RM2, HIGH);
    }

    /* CODE IF WE WANT TO USE PWM */
    /*
       for(i=20; i<256; i+=30)
         {
           analogWrite(LME,i);
           analogWrite(RME,20);
           delay(1000);
           if(i>200)
           {
             while(true)
             {
               analogWrite(LME,255);
             }
           }
         }*/

    //LEFT_FORWARD:
    if (request == "GET /move?dir=LEFT_FORWARD HTTP/1.1")
    {
      digitalWrite(LM1, LOW);
      digitalWrite(LM2, HIGH);
      digitalWrite(RM1, LOW);
      digitalWrite(RM2, HIGH);
    }

    /* CODE IF WE WANT TO USE PWM */
    /*
       for(i=20; i<256; i+=30)
         {
           analogWrite(RME,i);
           analogWrite(LME,20);
           delay(1000);
           if(i>200)
           {
             while(true)
             {
               analogWrite(RME,255);
             }
           }
         }  */

    //RIGHT_BACKWARD:
    if (request == "GET /move?dir=RIGHT_BACKWARD HTTP/1.1")
    {
      digitalWrite(LM1, HIGH);
      digitalWrite(LM2, LOW);
      digitalWrite(RM1, HIGH);
      digitalWrite(RM2, LOW);
    }


    /* CODE IF WE WANT TO USE PWM */
    /*
         for(i=20; i<256; i+=30)
           {
             analogWrite(LME,i);
             analogWrite(RME,20);
             delay(1000);
             if(i>200)
             {
               while(true)
               {
                 analogWrite(LME,255);
               }
             }
           } */

    //LEFT_BACKWARD:
    if (request == "GET /move?dir=LEFT_BACKWARD HTTP/1.1")
    {
      digitalWrite(LM1, HIGH);
      digitalWrite(LM2, LOW);
      digitalWrite(RM1, HIGH);
      digitalWrite(RM2, LOW);
    }


    /* CODE IF WE WANT TO USE PWM */
    /*
        for(i=20; i<256; i+=30)
          {
            analogWrite(RME,i);
            analogWrite(LME,20);
            delay(1000);
            if(i>200)
            {
              while(true)
              {
                analogWrite(RME,255);
              }
            }
          }  */

    //CLOCKWISE:
    if (request == "GET /move?dir=CLOCKWISE HTTP/1.1")
    {
      digitalWrite(LM1, LOW);
      digitalWrite(LM2, HIGH);
      digitalWrite(RM1, HIGH);
      digitalWrite(RM2, LOW);
    }


    /* CODE IF WE WANT TO USE PWM */
    /*
      for(i=0,j=0; i<256,j<256; i+=20,j+=20)
        {
          analogWrite(LME,i);
          analogWrite(RME,j);
          delay(1000);
          if(i>200 || j>200)
          {
            while(true)
            {
              analogWrite(LME,255);
              analogWrite(RME,255);
            }
          }
        }  */

    //ANTI_CLOCKWISE:
    if (request == "GET /move?dir=ANTI_CLOCKWISE HTTP/1.1")
    {
      digitalWrite(LM1, HIGH);
      digitalWrite(LM2, LOW);
      digitalWrite(RM1, LOW);
      digitalWrite(RM2, HIGH);
    }


    /* CODE IF WE WANT TO USE PWM */
    /*
       for(i=0,j=0; i<256,j<256; i+=20,j+=20)
         {
           analogWrite(LME,i);
           analogWrite(RME,j);
           delay(1000);
           if(i>200 || j>200)
           {
             while(true)
             {
               analogWrite(LME,255);
               analogWrite(RME,255);
             }
           }
         }  */
    if (request == "GET /move?dir=STOP HTTP/1.1")
    {
      digitalWrite(LM1, LOW);
      digitalWrite(LM2, LOW);
      digitalWrite(RM1, LOW);
      digitalWrite(RM1, LOW);
      Serial.println("Stop");
    }
    if (request == "GET /action?type=STOP HTTP/1.1")
    {
      digitalWrite(LM1, LOW);
      digitalWrite(LM2, LOW);
      digitalWrite(RM1, LOW);
      digitalWrite(RM2, LOW);
      Serial.println("STOP");
    }
  }
}
