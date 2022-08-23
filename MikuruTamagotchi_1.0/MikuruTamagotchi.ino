#include <SPI.h>
#include <TFT_eSPI.h>
//#include <WiFi.h>
#include "pest.h"
#include "weber.h"
#include "baby.h"
#include "freg.h"
#include "pancho.h"
#include "sushi.h"
#include "shop.h"
#include "door.h"
#include "box.h"
#include "computer.h"
#include "watercooler.h"
#include "salida.h"
#include "warn.h"
#include "mikurugif.h"
#include "mikurueat.h"
#include "mikurueat2.h"
#include "mikurueat3.h"
#include "mikurueat4.h"
#include "mikurueat5.h"
#include "mikurueat6.h"
#include "mikurueat7.h"
#include "mikurueat8.h"
#include "mikurueat9.h"
#include "mikurueat10.h"
#include "mikurueat11.h"
#include "roomred.h"
#include "roomblue.h"
#include "roomgray.h"
#include "roomwhite.h"
#include "roomgreen.h"
#include "roomblack.h"
#include "picture0.h"
#include "picture1.h"
#include "colorgif.h"
#include "f01.h"
#include "f02.h"
#include "f03.h"
#include "f04.h"
#include "f05.h"
#include "f06.h"
#include "f07.h"
#include "f08.h"
#include "f09.h"
#include "f10.h"
#include "f11.h"
#include "f12.h"
#include "f13.h"
#include "f14.h"
#include "f15.h"
#include "f16.h"
#include "f17.h"
#include "f18.h"
#include "f19.h"
#include "f20.h"
#include "f21.h"
#include "f22.h"

#include "forest1.h"
#include "forest2.h"

#include "cleangif.h"
#include "eatgif.h"
#include "gamegif.h"
#include "gardengif.h"
#include "sleepgif.h"
#include "gamewalk.h"


TFT_eSPI tft = TFT_eSPI();

int frame1 = 0;
int buttonbefore47 = 1, buttonstate47 = 1;
int buttonbefore0 = 1, buttonstate0 = 1;
int mainx1 = 1, mainy1 = 0, mainx2 = 30, mainy2 = 30;
int mainnum = 0;
int foodx1 = 22, foody1 = 22, foodx2 = 30, foody2 = 30;
int sleepx1 = 5, sleepy1 = 13, sleepx2 = 76, sleepy2 = 21;
int timex1 = 5, timey1 = 18, timex2 = 76, timey2 = 21;
int shopx1 = 0, shopy1 = 0, shopx2 = 128, shopy2 = 100;
int modex1 = 5, modey1 = 23, modex2 = 76, modey2 = 21;
int gamex1 = 5, gamey1 = 23, gamex2 = 76, gamey2 = 21;
int n_main = 32;
int n_food = 52;
int food_page = 0;
int sleeptime = 0, sleep_page = 0;
float Hun1, Fat1, Cle1;
int Hun, Fat, Cle, Exp;
int Hun_mas = 0, Fat_mas = 0, Cle_mas = 0;
int Hun_s = 0, Fat_s = 0, Cle_s = 0; //开始吃之前判断需要补充多少饥饿值所用的变量
int Exp_mas = 0;
int roomwhitex = 83, roomwhitey = 16;
int picture = 0;
unsigned long long picture_s = 86400000;//目前为每24小时刷新一次商店图片
int buy_j = 0;
int picture_group[100];
int pic = 0;//picture_group数组序号
int boxx1 = 101, boxy1 = 99, boxx2 = 26, boxy2 = 18;
bool darkmode = 0;//主屏幕模式0为亮，1为暗；

const int pwmFreq = 5000;
const int pwmResolution = 8;
const int pwmLedChannelTFT = 5;
int bright[] = {510, 490, 450, 430, 370, 300};//最低510
int b = 3;

int gamenum_left;
int gamenum_right;
int gamex = 9;
char buff[512];

//void wifi_scan()
//{
//  tft.setTextColor(TFT_WHITE, TFT_BLACK);
//  tft.fillScreen(TFT_BLACK);
//  tft.setTextDatum(MC_DATUM);
//  tft.setTextSize(1);
//
//  tft.drawString("Scan Network", tft.width() / 2, tft.height() / 2);
//  
//  WiFi.mode(WIFI_STA);
//  WiFi.disconnect();
//  delay(100);
//  int16_t wifi_n = WiFi.scanNetworks();//有一定延迟
//
//  tft.fillScreen(TFT_BLACK);
//  if (wifi_n == 0) 
//  {
//    tft.drawString("no networks found", tft.width() / 2, tft.height() / 2);
//  } 
//  else 
//  {
//    tft.setTextDatum(TL_DATUM);
//    tft.setCursor(0, 0);
//    Serial.printf("Found %d net\n", wifi_n);
//    for (int i = 0; i < wifi_n; ++i) 
//    {
//      sprintf(buff,
//              "[%d]:%s(%d)",
//              i + 1,
//              WiFi.SSID(i).c_str(),
//              WiFi.RSSI(i));
//      tft.println(buff);
//    }
//  }
//  //WiFi.mode( WIFI_OFF );
//  tft.setTextDatum(TL_DATUM);
//}

void mainicon()
{
  tft.fillScreen(TFT_BLACK);
  if(Hun < 60 || Fat < 60 || Cle < 60)
  {
    tft.pushImage(2, 1, 28, 28, warn);
  }
  else
  {
    tft.pushImage(2, 1, 28, 28, pest);
  }
  tft.pushImage(34, 1, 29, 29, weber);
  tft.pushImage(66, 1, 29, 29, baby);
  tft.pushImage(98, 1, 29, 29, freg);
  tft.pushImage(2, 99, 29, 29, shop);
  tft.pushImage(34, 99, 29, 29, door);
  tft.pushImage(66, 99, 29, 29, box);
  tft.pushImage(98, 99, 29, 29, computer);
}

void Generalmenu()
{
  if(digitalRead(0) == 0)
  {
    delay(300);
    tft.fillScreen(TFT_BLACK);
    while(digitalRead(0) == 1 && digitalRead(47) == 1)
    {
      tft.drawString("Hunger", 9, 9, 2);
      tft.drawString(String(Hun), 84, 9, 2);
      tft.drawString("%", 110, 9, 2);
    
      tft.drawString("Fatigue", 9, 39, 2);
      tft.drawString(String(Fat), 84, 39, 2);
      tft.drawString("%", 110, 39, 2);
    
      tft.drawString("Clean", 9, 69, 2);
      tft.drawString(String(Cle), 84, 69, 2);
      tft.drawString("%", 110, 69, 2);
    
      tft.drawString("Mikuru coins", 9, 99, 2);
      tft.drawString(String(Exp), 94, 99, 2);
    }
    delay(300);
    mainicon();
  }
}

void state_count()
{
  Hun1 = (0.5- (millis() / 86400000.00)) * 100;
  Fat1 = (0.5- (millis() / 259200000.00)) * 100;
  Cle1 = (0.5- (millis() / 172800000.00)) * 100;
  Hun = round(Hun1) + Hun_mas;
  Fat = round(Fat1) + Fat_mas;
  Cle = round(Cle1) + Cle_mas;
  Exp = (millis() / 600000 - Exp_mas + 300) / 10;

  if(Fat > 100)
  {
    Fat = 100;
  }

  else if(Cle > 100)
  {
    Cle = 100;
  }
}

void Food()
{
  if(digitalRead(0) == 0)
  {
    delay(300);
    tft.fillScreen(TFT_BLACK);
    food_page = 0;
    tft.pushImage(23, 23, 29, 29, f01);
    tft.pushImage(75, 23, 29, 29, f02);
    tft.pushImage(23, 75, 29, 29, f03);
    tft.pushImage(75, 75, 29, 29, f22);

    Hun_s = Hun; //把饥饿值Hun赋值给判断用的Hun_s
    tft.drawRect(foodx1, foody1, foodx2, foody2, TFT_WHITE);
    while(!(digitalRead(0) == 0 && foodx1 == 74 && foody1 == 74))
    {
      if(digitalRead(47) == 0 && foodx1 == 22 && foody1 == 22)
      {
        tft.drawRect(foodx1, foody1, foodx2, foody2, TFT_BLACK);
        foodx1 += n_food;
        tft.drawRect(foodx1, foody1, foodx2, foody2, TFT_WHITE);
        delay(300);
      }
  
      else if(digitalRead(47) == 0 && foodx1 == 74 && foody1 == 22)
      {
        tft.drawRect(foodx1, foody1, foodx2, foody2, TFT_BLACK);
        foodx1 -= n_food;
        foody1 += n_food;
        tft.drawRect(foodx1, foody1, foodx2, foody2, TFT_WHITE);
        delay(300);
      }
  
      else if(digitalRead(47) == 0 && foodx1 == 22 && foody1 == 74)
      {
        tft.drawRect(foodx1, foody1, foodx2, foody2, TFT_BLACK);
        foodx1 += n_food;
        tft.drawRect(foodx1, foody1, foodx2, foody2, TFT_WHITE);
        delay(300);
      }
  
      else if(digitalRead(47) == 0 && foodx1 == 74 && foody1 == 74)
      {
        tft.drawRect(foodx1, foody1, foodx2, foody2, TFT_BLACK);
        foodx1 -= n_food;
        foody1 -= n_food;
        if(food_page < 6)
        {
          food_page += 1;
          if(food_page == 1)
          {
            tft.pushImage(23, 23, 29, 29, f04);
            tft.pushImage(75, 23, 29, 29, f05);
            tft.pushImage(23, 75, 29, 29, f06);
            tft.pushImage(75, 75, 29, 29, f22);
          }

          else if(food_page == 2)
          {
            tft.pushImage(23, 23, 29, 29, f07);
            tft.pushImage(75, 23, 29, 29, f08);
            tft.pushImage(23, 75, 29, 29, f09);
            tft.pushImage(75, 75, 29, 29, f22);
          }

          else if(food_page == 3)
          {
            tft.pushImage(23, 23, 29, 29, f10);
            tft.pushImage(75, 23, 29, 29, f11);
            tft.pushImage(23, 75, 29, 29, f12);
            tft.pushImage(75, 75, 29, 29, f22);
          }

          else if(food_page == 4)
          {
            tft.pushImage(23, 23, 29, 29, f13);
            tft.pushImage(75, 23, 29, 29, f14);
            tft.pushImage(23, 75, 29, 29, f15);
            tft.pushImage(75, 75, 29, 29, f22);
          }

          else if(food_page == 5)
          {
            tft.pushImage(23, 23, 29, 29, f16);
            tft.pushImage(75, 23, 29, 29, f17);
            tft.pushImage(23, 75, 29, 29, f18);
            tft.pushImage(75, 75, 29, 29, f22);
          }

          else if(food_page == 6)
          {
            tft.pushImage(23, 23, 29, 29, f19);
            tft.pushImage(75, 23, 29, 29, f20);
            tft.pushImage(23, 75, 29, 29, f21);
            tft.pushImage(75, 75, 29, 29, f22);
          }

        }
        else if(food_page >= 6)
        {
          food_page = 0;
          tft.pushImage(23, 23, 29, 29, f01);
          tft.pushImage(75, 23, 29, 29, f02);
          tft.pushImage(23, 75, 29, 29, f03);
          tft.pushImage(75, 75, 29, 29, f22);
        }
        tft.drawRect(foodx1, foody1, foodx2, foody2, TFT_WHITE);
        delay(300);
      }
      
      
      //以下为点击确认键（0）时的反应 00
      else if(digitalRead(0) == 0 && foodx1 == 22 && foody1 == 22 && food_page == 0)
      {
        if(Hun_s <= 85)
        {
          Hun_mas += 15;
          Hun_s += 15; //在饥饿值增加的同时，判断用的饥饿值也增加

          //以下为吃东西的动画
          tft.fillScreen(TFT_BLACK);
          tft.drawRect(0, 88, 128, 40, TFT_WHITE);
          tft.pushImage(49, 49, 29, 29, f01);
          delay(500);
          tft.fillRect(49, 49, 29, 29, TFT_BLACK);
          tft.pushImage(49, 74, 29, 29, f01);
          delay(500);
          tft.fillRect(49, 74, 29, 29, TFT_BLACK);
          tft.pushImage(49, 92, 29, 29, f01);
          tft.drawRect(0, 88, 128, 40, TFT_WHITE);
          delay(500);
          tft.pushImage(0, 0, 128, 88, mikurueat);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat2);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat3);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat4);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat5);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat6);
          delay(200);
          tft.fillRect(49, 92, 29, 29, TFT_BLACK);
          tft.pushImage(0, 0, 128, 88, mikurueat7);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat8);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat9);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat10);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat11);
          delay(200);
          tft.fillScreen(TFT_BLACK);
          tft.pushImage(23, 23, 29, 29, f01);
          tft.pushImage(75, 23, 29, 29, f02);
          tft.pushImage(23, 75, 29, 29, f03);
          tft.pushImage(75, 75, 29, 29, f22);
          tft.drawRect(foodx1, foody1, foodx2, foody2, TFT_WHITE);
          //以上为吃东西的动画
          
          tft.drawString("Hunger +15%", 26, 4, 2);
          delay(1000);
          tft.fillRect(2, 2, 125, 18, TFT_BLACK);
        }
        else
        {
          tft.drawString("Can't eat that much", 4, 4, 2);
          delay(1000);
          tft.fillRect(2, 2, 125, 18, TFT_BLACK);
        }
      }

      else if(digitalRead(0) == 0 && foodx1 == 74 && foody1 == 22 && food_page == 0)
      {
        if(Hun_s <= 95)
        {
          Hun_mas += 5;
          Hun_s += 5;

          //以下为吃东西的动画
          tft.fillScreen(TFT_BLACK);
          tft.drawRect(0, 88, 128, 40, TFT_WHITE);
          tft.pushImage(49, 49, 29, 29, f02);
          delay(500);
          tft.fillRect(49, 49, 29, 29, TFT_BLACK);
          tft.pushImage(49, 74, 29, 29, f02);
          delay(500);
          tft.fillRect(49, 74, 29, 29, TFT_BLACK);
          tft.pushImage(49, 92, 29, 29, f02);
          tft.drawRect(0, 88, 128, 40, TFT_WHITE);
          delay(500);
          tft.pushImage(0, 0, 128, 88, mikurueat);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat2);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat3);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat4);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat5);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat6);
          delay(200);
          tft.fillRect(49, 92, 29, 29, TFT_BLACK);
          tft.pushImage(0, 0, 128, 88, mikurueat7);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat8);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat9);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat10);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat11);
          delay(200);
          tft.fillScreen(TFT_BLACK);
          tft.pushImage(23, 23, 29, 29, f01);
          tft.pushImage(75, 23, 29, 29, f02);
          tft.pushImage(23, 75, 29, 29, f03);
          tft.pushImage(75, 75, 29, 29, f22);
          tft.drawRect(foodx1, foody1, foodx2, foody2, TFT_WHITE);
          //以上为吃东西的动画
          
          tft.drawString("Hunger +5%", 26, 4, 2);
          delay(1000);
          tft.fillRect(2, 2, 125, 18, TFT_BLACK);
        }
        else
        {
          tft.drawString("Can't eat that much", 4, 4, 2);
          delay(1000);
          tft.fillRect(2, 2, 125, 18, TFT_BLACK);
        }
      }

      else if(digitalRead(0) == 0 && foodx1 == 22 && foody1 == 74 && food_page == 0)
      {
        if(Hun_s <= 98)
        {
          Hun_mas += 2;
          Hun_s += 2;

          //以下为吃东西的动画
          tft.fillScreen(TFT_BLACK);
          tft.drawRect(0, 88, 128, 40, TFT_WHITE);
          tft.pushImage(49, 49, 29, 29, f03);
          delay(500);
          tft.fillRect(49, 49, 29, 29, TFT_BLACK);
          tft.pushImage(49, 74, 29, 29, f03);
          delay(500);
          tft.fillRect(49, 74, 29, 29, TFT_BLACK);
          tft.pushImage(49, 92, 29, 29, f03);
          tft.drawRect(0, 88, 128, 40, TFT_WHITE);
          delay(500);
          tft.pushImage(0, 0, 128, 88, mikurueat);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat2);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat3);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat4);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat5);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat6);
          delay(200);
          tft.fillRect(49, 92, 29, 29, TFT_BLACK);
          tft.pushImage(0, 0, 128, 88, mikurueat7);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat8);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat9);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat10);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat11);
          delay(200);
          tft.fillScreen(TFT_BLACK);
          tft.pushImage(23, 23, 29, 29, f01);
          tft.pushImage(75, 23, 29, 29, f02);
          tft.pushImage(23, 75, 29, 29, f03);
          tft.pushImage(75, 75, 29, 29, f22);
          tft.drawRect(foodx1, foody1, foodx2, foody2, TFT_WHITE);
          //以上为吃东西的动画
          
          tft.drawString("Hunger +2%", 26, 4, 2);
          delay(1000);
          tft.fillRect(2, 2, 125, 18, TFT_BLACK);
        }
        else
        {
          tft.drawString("Can't eat that much", 4, 4, 2);
          delay(1000);
          tft.fillRect(2, 2, 125, 18, TFT_BLACK);
        }
      }
      //以上为点击确认键（0）时的反应 00

      //以下为点击确认键（0）时的反应 01
      else if(digitalRead(0) == 0 && foodx1 == 22 && foody1 == 22 && food_page == 1)
      {
        if(Hun_s <= 85)
        {
          Hun_mas += 15;
          Hun_s += 15; //在饥饿值增加的同时，判断用的饥饿值也增加

          //以下为吃东西的动画
          tft.fillScreen(TFT_BLACK);
          tft.drawRect(0, 88, 128, 40, TFT_WHITE);
          tft.pushImage(49, 49, 29, 29, f04);
          delay(500);
          tft.fillRect(49, 49, 29, 29, TFT_BLACK);
          tft.pushImage(49, 74, 29, 29, f04);
          delay(500);
          tft.fillRect(49, 74, 29, 29, TFT_BLACK);
          tft.pushImage(49, 92, 29, 29, f04);
          tft.drawRect(0, 88, 128, 40, TFT_WHITE);
          delay(500);
          tft.pushImage(0, 0, 128, 88, mikurueat);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat2);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat3);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat4);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat5);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat6);
          delay(200);
          tft.fillRect(49, 92, 29, 29, TFT_BLACK);
          tft.pushImage(0, 0, 128, 88, mikurueat7);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat8);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat9);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat10);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat11);
          delay(200);
          tft.fillScreen(TFT_BLACK);
          tft.pushImage(23, 23, 29, 29, f04);
          tft.pushImage(75, 23, 29, 29, f05);
          tft.pushImage(23, 75, 29, 29, f06);
          tft.pushImage(75, 75, 29, 29, f22);
          tft.drawRect(foodx1, foody1, foodx2, foody2, TFT_WHITE);
          //以上为吃东西的动画
          
          tft.drawString("Hunger +15%", 26, 4, 2);
          delay(1000);
          tft.fillRect(2, 2, 125, 18, TFT_BLACK);
        }
        else
        {
          tft.drawString("Can't eat that much", 4, 4, 2);
          delay(1000);
          tft.fillRect(2, 2, 125, 18, TFT_BLACK);
        }
      }

      else if(digitalRead(0) == 0 && foodx1 == 74 && foody1 == 22 && food_page == 1)
      {
        if(Hun_s <= 95)
        {
          Hun_mas += 5;
          Hun_s += 5;

          //以下为吃东西的动画
          tft.fillScreen(TFT_BLACK);
          tft.drawRect(0, 88, 128, 40, TFT_WHITE);
          tft.pushImage(49, 49, 29, 29, f05);
          delay(500);
          tft.fillRect(49, 49, 29, 29, TFT_BLACK);
          tft.pushImage(49, 74, 29, 29, f05);
          delay(500);
          tft.fillRect(49, 74, 29, 29, TFT_BLACK);
          tft.pushImage(49, 92, 29, 29, f05);
          tft.drawRect(0, 88, 128, 40, TFT_WHITE);
          delay(500);
          tft.pushImage(0, 0, 128, 88, mikurueat);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat2);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat3);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat4);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat5);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat6);
          delay(200);
          tft.fillRect(49, 92, 29, 29, TFT_BLACK);
          tft.pushImage(0, 0, 128, 88, mikurueat7);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat8);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat9);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat10);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat11);
          delay(200);
          tft.fillScreen(TFT_BLACK);
          tft.pushImage(23, 23, 29, 29, f04);
          tft.pushImage(75, 23, 29, 29, f05);
          tft.pushImage(23, 75, 29, 29, f06);
          tft.pushImage(75, 75, 29, 29, f22);
          tft.drawRect(foodx1, foody1, foodx2, foody2, TFT_WHITE);
          //以上为吃东西的动画
          
          tft.drawString("Hunger +5%", 26, 4, 2);
          delay(1000);
          tft.fillRect(2, 2, 125, 18, TFT_BLACK);
        }
        else
        {
          tft.drawString("Can't eat that much", 4, 4, 2);
          delay(1000);
          tft.fillRect(2, 2, 125, 18, TFT_BLACK);
        }
      }

      else if(digitalRead(0) == 0 && foodx1 == 22 && foody1 == 74 && food_page == 1)
      {
        if(Hun_s <= 98)
        {
          Hun_mas += 2;
          Hun_s += 2;

          //以下为吃东西的动画
          tft.fillScreen(TFT_BLACK);
          tft.drawRect(0, 88, 128, 40, TFT_WHITE);
          tft.pushImage(49, 49, 29, 29, f06);
          delay(500);
          tft.fillRect(49, 49, 29, 29, TFT_BLACK);
          tft.pushImage(49, 74, 29, 29, f06);
          delay(500);
          tft.fillRect(49, 74, 29, 29, TFT_BLACK);
          tft.pushImage(49, 92, 29, 29, f06);
          tft.drawRect(0, 88, 128, 40, TFT_WHITE);
          delay(500);
          tft.pushImage(0, 0, 128, 88, mikurueat);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat2);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat3);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat4);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat5);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat6);
          delay(200);
          tft.fillRect(49, 92, 29, 29, TFT_BLACK);
          tft.pushImage(0, 0, 128, 88, mikurueat7);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat8);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat9);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat10);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat11);
          delay(200);
          tft.fillScreen(TFT_BLACK);
          tft.pushImage(23, 23, 29, 29, f04);
          tft.pushImage(75, 23, 29, 29, f05);
          tft.pushImage(23, 75, 29, 29, f06);
          tft.pushImage(75, 75, 29, 29, f22);
          tft.drawRect(foodx1, foody1, foodx2, foody2, TFT_WHITE);
          //以上为吃东西的动画
          
          tft.drawString("Hunger +2%", 26, 4, 2);
          delay(1000);
          tft.fillRect(2, 2, 125, 18, TFT_BLACK);
        }
        else
        {
          tft.drawString("Can't eat that much", 4, 4, 2);
          delay(1000);
          tft.fillRect(2, 2, 125, 18, TFT_BLACK);
        }
      }
      //以上为点击确认键（0）时的反应 01

      //以下为点击确认键（0）时的反应 02
      else if(digitalRead(0) == 0 && foodx1 == 22 && foody1 == 22 && food_page == 2)
      {
        if(Hun_s <= 85)
        {
          Hun_mas += 15;
          Hun_s += 15; //在饥饿值增加的同时，判断用的饥饿值也增加

          //以下为吃东西的动画
          tft.fillScreen(TFT_BLACK);
          tft.drawRect(0, 88, 128, 40, TFT_WHITE);
          tft.pushImage(49, 49, 29, 29, f07);
          delay(500);
          tft.fillRect(49, 49, 29, 29, TFT_BLACK);
          tft.pushImage(49, 74, 29, 29, f07);
          delay(500);
          tft.fillRect(49, 74, 29, 29, TFT_BLACK);
          tft.pushImage(49, 92, 29, 29, f07);
          tft.drawRect(0, 88, 128, 40, TFT_WHITE);
          delay(500);
          tft.pushImage(0, 0, 128, 88, mikurueat);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat2);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat3);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat4);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat5);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat6);
          delay(200);
          tft.fillRect(49, 92, 29, 29, TFT_BLACK);
          tft.pushImage(0, 0, 128, 88, mikurueat7);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat8);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat9);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat10);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat11);
          delay(200);
          tft.fillScreen(TFT_BLACK);
          tft.pushImage(23, 23, 29, 29, f07);
          tft.pushImage(75, 23, 29, 29, f08);
          tft.pushImage(23, 75, 29, 29, f09);
          tft.pushImage(75, 75, 29, 29, f22);
          tft.drawRect(foodx1, foody1, foodx2, foody2, TFT_WHITE);
          //以上为吃东西的动画
          
          tft.drawString("Hunger +15%", 26, 4, 2);
          delay(1000);
          tft.fillRect(2, 2, 125, 18, TFT_BLACK);
        }
        else
        {
          tft.drawString("Can't eat that much", 4, 4, 2);
          delay(1000);
          tft.fillRect(2, 2, 125, 18, TFT_BLACK);
        }
      }

      else if(digitalRead(0) == 0 && foodx1 == 74 && foody1 == 22 && food_page == 2)
      {
        if(Hun_s <= 95)
        {
          Hun_mas += 5;
          Hun_s += 5;

          //以下为吃东西的动画
          tft.fillScreen(TFT_BLACK);
          tft.drawRect(0, 88, 128, 40, TFT_WHITE);
          tft.pushImage(49, 49, 29, 29, f08);
          delay(500);
          tft.fillRect(49, 49, 29, 29, TFT_BLACK);
          tft.pushImage(49, 74, 29, 29, f08);
          delay(500);
          tft.fillRect(49, 74, 29, 29, TFT_BLACK);
          tft.pushImage(49, 92, 29, 29, f08);
          tft.drawRect(0, 88, 128, 40, TFT_WHITE);
          delay(500);
          tft.pushImage(0, 0, 128, 88, mikurueat);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat2);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat3);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat4);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat5);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat6);
          delay(200);
          tft.fillRect(49, 92, 29, 29, TFT_BLACK);
          tft.pushImage(0, 0, 128, 88, mikurueat7);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat8);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat9);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat10);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat11);
          delay(200);
          tft.fillScreen(TFT_BLACK);
          tft.pushImage(23, 23, 29, 29, f07);
          tft.pushImage(75, 23, 29, 29, f08);
          tft.pushImage(23, 75, 29, 29, f09);
          tft.pushImage(75, 75, 29, 29, f22);
          tft.drawRect(foodx1, foody1, foodx2, foody2, TFT_WHITE);
          //以上为吃东西的动画
          
          tft.drawString("Hunger +5%", 26, 4, 2);
          delay(1000);
          tft.fillRect(2, 2, 125, 18, TFT_BLACK);
        }
        else
        {
          tft.drawString("Can't eat that much", 4, 4, 2);
          delay(1000);
          tft.fillRect(2, 2, 125, 18, TFT_BLACK);
        }
      }

      else if(digitalRead(0) == 0 && foodx1 == 22 && foody1 == 74 && food_page == 2)
      {
        if(Hun_s <= 98)
        {
          Hun_mas += 2;
          Hun_s += 2;

          //以下为吃东西的动画
          tft.fillScreen(TFT_BLACK);
          tft.drawRect(0, 88, 128, 40, TFT_WHITE);
          tft.pushImage(49, 49, 29, 29, f09);
          delay(500);
          tft.fillRect(49, 49, 29, 29, TFT_BLACK);
          tft.pushImage(49, 74, 29, 29, f09);
          delay(500);
          tft.fillRect(49, 74, 29, 29, TFT_BLACK);
          tft.pushImage(49, 92, 29, 29, f09);
          tft.drawRect(0, 88, 128, 40, TFT_WHITE);
          delay(500);
          tft.pushImage(0, 0, 128, 88, mikurueat);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat2);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat3);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat4);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat5);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat6);
          delay(200);
          tft.fillRect(49, 92, 29, 29, TFT_BLACK);
          tft.pushImage(0, 0, 128, 88, mikurueat7);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat8);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat9);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat10);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat11);
          delay(200);
          tft.fillScreen(TFT_BLACK);
          tft.pushImage(23, 23, 29, 29, f07);
          tft.pushImage(75, 23, 29, 29, f08);
          tft.pushImage(23, 75, 29, 29, f09);
          tft.pushImage(75, 75, 29, 29, f22);
          tft.drawRect(foodx1, foody1, foodx2, foody2, TFT_WHITE);
          //以上为吃东西的动画
          
          tft.drawString("Hunger +2%", 26, 4, 2);
          delay(1000);
          tft.fillRect(2, 2, 125, 18, TFT_BLACK);
        }
        else
        {
          tft.drawString("Can't eat that much", 4, 4, 2);
          delay(1000);
          tft.fillRect(2, 2, 125, 18, TFT_BLACK);
        }
      }
      //以上为点击确认键（0）时的反应 02

      //以下为点击确认键（0）时的反应 03
      else if(digitalRead(0) == 0 && foodx1 == 22 && foody1 == 22 && food_page == 3)
      {
        if(Hun_s <= 85)
        {
          Hun_mas += 15;
          Hun_s += 15; //在饥饿值增加的同时，判断用的饥饿值也增加

          //以下为吃东西的动画
          tft.fillScreen(TFT_BLACK);
          tft.drawRect(0, 88, 128, 40, TFT_WHITE);
          tft.pushImage(49, 49, 29, 29, f10);
          delay(500);
          tft.fillRect(49, 49, 29, 29, TFT_BLACK);
          tft.pushImage(49, 74, 29, 29, f10);
          delay(500);
          tft.fillRect(49, 74, 29, 29, TFT_BLACK);
          tft.pushImage(49, 92, 29, 29, f10);
          tft.drawRect(0, 88, 128, 40, TFT_WHITE);
          delay(500);
          tft.pushImage(0, 0, 128, 88, mikurueat);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat2);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat3);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat4);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat5);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat6);
          delay(200);
          tft.fillRect(49, 92, 29, 29, TFT_BLACK);
          tft.pushImage(0, 0, 128, 88, mikurueat7);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat8);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat9);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat10);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat11);
          delay(200);
          tft.fillScreen(TFT_BLACK);
          tft.pushImage(23, 23, 29, 29, f10);
          tft.pushImage(75, 23, 29, 29, f11);
          tft.pushImage(23, 75, 29, 29, f12);
          tft.pushImage(75, 75, 29, 29, f22);
          tft.drawRect(foodx1, foody1, foodx2, foody2, TFT_WHITE);
          //以上为吃东西的动画
          
          tft.drawString("Hunger +15%", 26, 4, 2);
          delay(1000);
          tft.fillRect(2, 2, 125, 18, TFT_BLACK);
        }
        else
        {
          tft.drawString("Can't eat that much", 4, 4, 2);
          delay(1000);
          tft.fillRect(2, 2, 125, 18, TFT_BLACK);
        }
      }

      else if(digitalRead(0) == 0 && foodx1 == 74 && foody1 == 22 && food_page == 3)
      {
        if(Hun_s <= 95)
        {
          Hun_mas += 5;
          Hun_s += 5;

          //以下为吃东西的动画
          tft.fillScreen(TFT_BLACK);
          tft.drawRect(0, 88, 128, 40, TFT_WHITE);
          tft.pushImage(49, 49, 29, 29, f11);
          delay(500);
          tft.fillRect(49, 49, 29, 29, TFT_BLACK);
          tft.pushImage(49, 74, 29, 29, f11);
          delay(500);
          tft.fillRect(49, 74, 29, 29, TFT_BLACK);
          tft.pushImage(49, 92, 29, 29, f11);
          tft.drawRect(0, 88, 128, 40, TFT_WHITE);
          delay(500);
          tft.pushImage(0, 0, 128, 88, mikurueat);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat2);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat3);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat4);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat5);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat6);
          delay(200);
          tft.fillRect(49, 92, 29, 29, TFT_BLACK);
          tft.pushImage(0, 0, 128, 88, mikurueat7);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat8);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat9);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat10);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat11);
          delay(200);
          tft.fillScreen(TFT_BLACK);
          tft.pushImage(23, 23, 29, 29, f10);
          tft.pushImage(75, 23, 29, 29, f11);
          tft.pushImage(23, 75, 29, 29, f12);
          tft.pushImage(75, 75, 29, 29, f22);
          tft.drawRect(foodx1, foody1, foodx2, foody2, TFT_WHITE);
          //以上为吃东西的动画
          
          tft.drawString("Hunger +5%", 26, 4, 2);
          delay(1000);
          tft.fillRect(2, 2, 125, 18, TFT_BLACK);
        }
        else
        {
          tft.drawString("Can't eat that much", 4, 4, 2);
          delay(1000);
          tft.fillRect(2, 2, 125, 18, TFT_BLACK);
        }
      }

      else if(digitalRead(0) == 0 && foodx1 == 22 && foody1 == 74 && food_page == 3)
      {
        if(Hun_s <= 98)
        {
          Hun_mas += 2;
          Hun_s += 2;

          //以下为吃东西的动画
          tft.fillScreen(TFT_BLACK);
          tft.drawRect(0, 88, 128, 40, TFT_WHITE);
          tft.pushImage(49, 49, 29, 29, f12);
          delay(500);
          tft.fillRect(49, 49, 29, 29, TFT_BLACK);
          tft.pushImage(49, 74, 29, 29, f12);
          delay(500);
          tft.fillRect(49, 74, 29, 29, TFT_BLACK);
          tft.pushImage(49, 92, 29, 29, f12);
          tft.drawRect(0, 88, 128, 40, TFT_WHITE);
          delay(500);
          tft.pushImage(0, 0, 128, 88, mikurueat);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat2);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat3);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat4);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat5);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat6);
          delay(200);
          tft.fillRect(49, 92, 29, 29, TFT_BLACK);
          tft.pushImage(0, 0, 128, 88, mikurueat7);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat8);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat9);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat10);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat11);
          delay(200);
          tft.fillScreen(TFT_BLACK);
          tft.pushImage(23, 23, 29, 29, f10);
          tft.pushImage(75, 23, 29, 29, f11);
          tft.pushImage(23, 75, 29, 29, f12);
          tft.pushImage(75, 75, 29, 29, f22);
          tft.drawRect(foodx1, foody1, foodx2, foody2, TFT_WHITE);
          //以上为吃东西的动画
          
          tft.drawString("Hunger +2%", 26, 4, 2);
          delay(1000);
          tft.fillRect(2, 2, 125, 18, TFT_BLACK);
        }
        else
        {
          tft.drawString("Can't eat that much", 4, 4, 2);
          delay(1000);
          tft.fillRect(2, 2, 125, 18, TFT_BLACK);
        }
      }
      //以上为点击确认键（0）时的反应 03

      //以下为点击确认键（0）时的反应 04
      else if(digitalRead(0) == 0 && foodx1 == 22 && foody1 == 22 && food_page == 4)
      {
        if(Hun_s <= 85)
        {
          Hun_mas += 15;
          Hun_s += 15; //在饥饿值增加的同时，判断用的饥饿值也增加

          //以下为吃东西的动画
          tft.fillScreen(TFT_BLACK);
          tft.drawRect(0, 88, 128, 40, TFT_WHITE);
          tft.pushImage(49, 49, 29, 29, f13);
          delay(500);
          tft.fillRect(49, 49, 29, 29, TFT_BLACK);
          tft.pushImage(49, 74, 29, 29, f13);
          delay(500);
          tft.fillRect(49, 74, 29, 29, TFT_BLACK);
          tft.pushImage(49, 92, 29, 29, f13);
          tft.drawRect(0, 88, 128, 40, TFT_WHITE);
          delay(500);
          tft.pushImage(0, 0, 128, 88, mikurueat);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat2);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat3);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat4);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat5);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat6);
          delay(200);
          tft.fillRect(49, 92, 29, 29, TFT_BLACK);
          tft.pushImage(0, 0, 128, 88, mikurueat7);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat8);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat9);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat10);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat11);
          delay(200);
          tft.fillScreen(TFT_BLACK);
          tft.pushImage(23, 23, 29, 29, f13);
          tft.pushImage(75, 23, 29, 29, f14);
          tft.pushImage(23, 75, 29, 29, f15);
          tft.pushImage(75, 75, 29, 29, f22);
          tft.drawRect(foodx1, foody1, foodx2, foody2, TFT_WHITE);
          //以上为吃东西的动画
          
          tft.drawString("Hunger +15%", 26, 4, 2);
          delay(1000);
          tft.fillRect(2, 2, 125, 18, TFT_BLACK);
        }
        else
        {
          tft.drawString("Can't eat that much", 4, 4, 2);
          delay(1000);
          tft.fillRect(2, 2, 125, 18, TFT_BLACK);
        }
      }

      else if(digitalRead(0) == 0 && foodx1 == 74 && foody1 == 22 && food_page == 4)
      {
        if(Hun_s <= 95)
        {
          Hun_mas += 5;
          Hun_s += 5;

          //以下为吃东西的动画
          tft.fillScreen(TFT_BLACK);
          tft.drawRect(0, 88, 128, 40, TFT_WHITE);
          tft.pushImage(49, 49, 29, 29, f14);
          delay(500);
          tft.fillRect(49, 49, 29, 29, TFT_BLACK);
          tft.pushImage(49, 74, 29, 29, f14);
          delay(500);
          tft.fillRect(49, 74, 29, 29, TFT_BLACK);
          tft.pushImage(49, 92, 29, 29, f14);
          tft.drawRect(0, 88, 128, 40, TFT_WHITE);
          delay(500);
          tft.pushImage(0, 0, 128, 88, mikurueat);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat2);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat3);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat4);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat5);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat6);
          delay(200);
          tft.fillRect(49, 92, 29, 29, TFT_BLACK);
          tft.pushImage(0, 0, 128, 88, mikurueat7);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat8);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat9);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat10);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat11);
          delay(200);
          tft.fillScreen(TFT_BLACK);
          tft.pushImage(23, 23, 29, 29, f13);
          tft.pushImage(75, 23, 29, 29, f14);
          tft.pushImage(23, 75, 29, 29, f15);
          tft.pushImage(75, 75, 29, 29, f22);
          tft.drawRect(foodx1, foody1, foodx2, foody2, TFT_WHITE);
          //以上为吃东西的动画
          
          tft.drawString("Hunger +5%", 26, 4, 2);
          delay(1000);
          tft.fillRect(2, 2, 125, 18, TFT_BLACK);
        }
        else
        {
          tft.drawString("Can't eat that much", 4, 4, 2);
          delay(1000);
          tft.fillRect(2, 2, 125, 18, TFT_BLACK);
        }
      }

      else if(digitalRead(0) == 0 && foodx1 == 22 && foody1 == 74 && food_page == 4)
      {
        if(Hun_s <= 98)
        {
          Hun_mas += 2;
          Hun_s += 2;

          //以下为吃东西的动画
          tft.fillScreen(TFT_BLACK);
          tft.drawRect(0, 88, 128, 40, TFT_WHITE);
          tft.pushImage(49, 49, 29, 29, f15);
          delay(500);
          tft.fillRect(49, 49, 29, 29, TFT_BLACK);
          tft.pushImage(49, 74, 29, 29, f15);
          delay(500);
          tft.fillRect(49, 74, 29, 29, TFT_BLACK);
          tft.pushImage(49, 92, 29, 29, f15);
          tft.drawRect(0, 88, 128, 40, TFT_WHITE);
          delay(500);
          tft.pushImage(0, 0, 128, 88, mikurueat);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat2);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat3);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat4);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat5);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat6);
          delay(200);
          tft.fillRect(49, 92, 29, 29, TFT_BLACK);
          tft.pushImage(0, 0, 128, 88, mikurueat7);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat8);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat9);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat10);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat11);
          delay(200);
          tft.fillScreen(TFT_BLACK);
          tft.pushImage(23, 23, 29, 29, f13);
          tft.pushImage(75, 23, 29, 29, f14);
          tft.pushImage(23, 75, 29, 29, f15);
          tft.pushImage(75, 75, 29, 29, f22);
          tft.drawRect(foodx1, foody1, foodx2, foody2, TFT_WHITE);
          //以上为吃东西的动画
          
          tft.drawString("Hunger +2%", 26, 4, 2);
          delay(1000);
          tft.fillRect(2, 2, 125, 18, TFT_BLACK);
        }
        else
        {
          tft.drawString("Can't eat that much", 4, 4, 2);
          delay(1000);
          tft.fillRect(2, 2, 125, 18, TFT_BLACK);
        }
      }
      //以上为点击确认键（0）时的反应 04

      //以下为点击确认键（0）时的反应 05
      else if(digitalRead(0) == 0 && foodx1 == 22 && foody1 == 22 && food_page == 5)
      {
        if(Hun_s <= 85)
        {
          Hun_mas += 15;
          Hun_s += 15; //在饥饿值增加的同时，判断用的饥饿值也增加

          //以下为吃东西的动画
          tft.fillScreen(TFT_BLACK);
          tft.drawRect(0, 88, 128, 40, TFT_WHITE);
          tft.pushImage(49, 49, 29, 29, f16);
          delay(500);
          tft.fillRect(49, 49, 29, 29, TFT_BLACK);
          tft.pushImage(49, 74, 29, 29, f16);
          delay(500);
          tft.fillRect(49, 74, 29, 29, TFT_BLACK);
          tft.pushImage(49, 92, 29, 29, f16);
          tft.drawRect(0, 88, 128, 40, TFT_WHITE);
          delay(500);
          tft.pushImage(0, 0, 128, 88, mikurueat);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat2);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat3);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat4);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat5);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat6);
          delay(200);
          tft.fillRect(49, 92, 29, 29, TFT_BLACK);
          tft.pushImage(0, 0, 128, 88, mikurueat7);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat8);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat9);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat10);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat11);
          delay(200);
          tft.fillScreen(TFT_BLACK);
          tft.pushImage(23, 23, 29, 29, f16);
          tft.pushImage(75, 23, 29, 29, f17);
          tft.pushImage(23, 75, 29, 29, f18);
          tft.pushImage(75, 75, 29, 29, f22);
          tft.drawRect(foodx1, foody1, foodx2, foody2, TFT_WHITE);
          //以上为吃东西的动画
          
          tft.drawString("Hunger +15%", 26, 4, 2);
          delay(1000);
          tft.fillRect(2, 2, 125, 18, TFT_BLACK);
        }
        else
        {
          tft.drawString("Can't eat that much", 4, 4, 2);
          delay(1000);
          tft.fillRect(2, 2, 125, 18, TFT_BLACK);
        }
      }

      else if(digitalRead(0) == 0 && foodx1 == 74 && foody1 == 22 && food_page == 5)
      {
        if(Hun_s <= 95)
        {
          Hun_mas += 5;
          Hun_s += 5;

          //以下为吃东西的动画
          tft.fillScreen(TFT_BLACK);
          tft.drawRect(0, 88, 128, 40, TFT_WHITE);
          tft.pushImage(49, 49, 29, 29, f17);
          delay(500);
          tft.fillRect(49, 49, 29, 29, TFT_BLACK);
          tft.pushImage(49, 74, 29, 29, f17);
          delay(500);
          tft.fillRect(49, 74, 29, 29, TFT_BLACK);
          tft.pushImage(49, 92, 29, 29, f17);
          tft.drawRect(0, 88, 128, 40, TFT_WHITE);
          delay(500);
          tft.pushImage(0, 0, 128, 88, mikurueat);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat2);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat3);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat4);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat5);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat6);
          delay(200);
          tft.fillRect(49, 92, 29, 29, TFT_BLACK);
          tft.pushImage(0, 0, 128, 88, mikurueat7);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat8);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat9);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat10);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat11);
          delay(200);
          tft.fillScreen(TFT_BLACK);
          tft.pushImage(23, 23, 29, 29, f16);
          tft.pushImage(75, 23, 29, 29, f17);
          tft.pushImage(23, 75, 29, 29, f18);
          tft.pushImage(75, 75, 29, 29, f22);
          tft.drawRect(foodx1, foody1, foodx2, foody2, TFT_WHITE);
          //以上为吃东西的动画
          
          tft.drawString("Hunger +5%", 26, 4, 2);
          delay(1000);
          tft.fillRect(2, 2, 125, 18, TFT_BLACK);
        }
        else
        {
          tft.drawString("Can't eat that much", 4, 4, 2);
          delay(1000);
          tft.fillRect(2, 2, 125, 18, TFT_BLACK);
        }
      }

      else if(digitalRead(0) == 0 && foodx1 == 22 && foody1 == 74 && food_page == 5)
      {
        if(Hun_s <= 98)
        {
          Hun_mas += 2;
          Hun_s += 2;

          //以下为吃东西的动画
          tft.fillScreen(TFT_BLACK);
          tft.drawRect(0, 88, 128, 40, TFT_WHITE);
          tft.pushImage(49, 49, 29, 29, f18);
          delay(500);
          tft.fillRect(49, 49, 29, 29, TFT_BLACK);
          tft.pushImage(49, 74, 29, 29, f18);
          delay(500);
          tft.fillRect(49, 74, 29, 29, TFT_BLACK);
          tft.pushImage(49, 92, 29, 29, f18);
          tft.drawRect(0, 88, 128, 40, TFT_WHITE);
          delay(500);
          tft.pushImage(0, 0, 128, 88, mikurueat);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat2);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat3);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat4);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat5);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat6);
          delay(200);
          tft.fillRect(49, 92, 29, 29, TFT_BLACK);
          tft.pushImage(0, 0, 128, 88, mikurueat7);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat8);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat9);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat10);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat11);
          delay(200);
          tft.fillScreen(TFT_BLACK);
          tft.pushImage(23, 23, 29, 29, f16);
          tft.pushImage(75, 23, 29, 29, f17);
          tft.pushImage(23, 75, 29, 29, f18);
          tft.pushImage(75, 75, 29, 29, f22);
          tft.drawRect(foodx1, foody1, foodx2, foody2, TFT_WHITE);
          //以上为吃东西的动画
          
          tft.drawString("Hunger +2%", 26, 4, 2);
          delay(1000);
          tft.fillRect(2, 2, 125, 18, TFT_BLACK);
        }
        else
        {
          tft.drawString("Can't eat that much", 4, 4, 2);
          delay(1000);
          tft.fillRect(2, 2, 125, 18, TFT_BLACK);
        }
      }
      //以上为点击确认键（0）时的反应 05

      //以下为点击确认键（0）时的反应 06
      else if(digitalRead(0) == 0 && foodx1 == 22 && foody1 == 22 && food_page == 6)
      {
        if(Hun_s <= 85)
        {
          Hun_mas += 15;
          Hun_s += 15; //在饥饿值增加的同时，判断用的饥饿值也增加

          //以下为吃东西的动画
          tft.fillScreen(TFT_BLACK);
          tft.drawRect(0, 88, 128, 40, TFT_WHITE);
          tft.pushImage(49, 49, 29, 29, f19);
          delay(500);
          tft.fillRect(49, 49, 29, 29, TFT_BLACK);
          tft.pushImage(49, 74, 29, 29, f19);
          delay(500);
          tft.fillRect(49, 74, 29, 29, TFT_BLACK);
          tft.pushImage(49, 92, 29, 29, f19);
          tft.drawRect(0, 88, 128, 40, TFT_WHITE);
          delay(500);
          tft.pushImage(0, 0, 128, 88, mikurueat);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat2);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat3);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat4);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat5);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat6);
          delay(200);
          tft.fillRect(49, 92, 29, 29, TFT_BLACK);
          tft.pushImage(0, 0, 128, 88, mikurueat7);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat8);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat9);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat10);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat11);
          delay(200);
          tft.fillScreen(TFT_BLACK);
          tft.pushImage(23, 23, 29, 29, f19);
          tft.pushImage(75, 23, 29, 29, f20);
          tft.pushImage(23, 75, 29, 29, f21);
          tft.pushImage(75, 75, 29, 29, f22);
          tft.drawRect(foodx1, foody1, foodx2, foody2, TFT_WHITE);
          //以上为吃东西的动画
          
          tft.drawString("Hunger +15%", 26, 4, 2);
          delay(1000);
          tft.fillRect(2, 2, 125, 18, TFT_BLACK);
        }
        else
        {
          tft.drawString("Can't eat that much", 4, 4, 2);
          delay(1000);
          tft.fillRect(2, 2, 125, 18, TFT_BLACK);
        }
      }

      else if(digitalRead(0) == 0 && foodx1 == 74 && foody1 == 22 && food_page == 6)
      {
        if(Hun_s <= 95)
        {
          Hun_mas += 5;
          Hun_s += 5;

          //以下为吃东西的动画
          tft.fillScreen(TFT_BLACK);
          tft.drawRect(0, 88, 128, 40, TFT_WHITE);
          tft.pushImage(49, 49, 29, 29, f20);
          delay(500);
          tft.fillRect(49, 49, 29, 29, TFT_BLACK);
          tft.pushImage(49, 74, 29, 29, f20);
          delay(500);
          tft.fillRect(49, 74, 29, 29, TFT_BLACK);
          tft.pushImage(49, 92, 29, 29, f20);
          tft.drawRect(0, 88, 128, 40, TFT_WHITE);
          delay(500);
          tft.pushImage(0, 0, 128, 88, mikurueat);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat2);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat3);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat4);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat5);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat6);
          delay(200);
          tft.fillRect(49, 92, 29, 29, TFT_BLACK);
          tft.pushImage(0, 0, 128, 88, mikurueat7);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat8);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat9);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat10);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat11);
          delay(200);
          tft.fillScreen(TFT_BLACK);
          tft.pushImage(23, 23, 29, 29, f19);
          tft.pushImage(75, 23, 29, 29, f20);
          tft.pushImage(23, 75, 29, 29, f21);
          tft.pushImage(75, 75, 29, 29, f22);
          tft.drawRect(foodx1, foody1, foodx2, foody2, TFT_WHITE);
          //以上为吃东西的动画
          
          tft.drawString("Hunger +5%", 26, 4, 2);
          delay(1000);
          tft.fillRect(2, 2, 125, 18, TFT_BLACK);
        }
        else
        {
          tft.drawString("Can't eat that much", 4, 4, 2);
          delay(1000);
          tft.fillRect(2, 2, 125, 18, TFT_BLACK);
        }
      }

      else if(digitalRead(0) == 0 && foodx1 == 22 && foody1 == 74 && food_page == 6)
      {
        if(Hun_s <= 98)
        {
          Hun_mas += 2;
          Hun_s += 2;

          //以下为吃东西的动画
          tft.fillScreen(TFT_BLACK);
          tft.drawRect(0, 88, 128, 40, TFT_WHITE);
          tft.pushImage(49, 49, 29, 29, f21);
          delay(500);
          tft.fillRect(49, 49, 29, 29, TFT_BLACK);
          tft.pushImage(49, 74, 29, 29, f21);
          delay(500);
          tft.fillRect(49, 74, 29, 29, TFT_BLACK);
          tft.pushImage(49, 92, 29, 29, f21);
          tft.drawRect(0, 88, 128, 40, TFT_WHITE);
          delay(500);
          tft.pushImage(0, 0, 128, 88, mikurueat);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat2);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat3);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat4);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat5);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat6);
          delay(200);
          tft.fillRect(49, 92, 29, 29, TFT_BLACK);
          tft.pushImage(0, 0, 128, 88, mikurueat7);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat8);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat9);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat10);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat11);
          delay(200);
          tft.fillScreen(TFT_BLACK);
          tft.pushImage(23, 23, 29, 29, f19);
          tft.pushImage(75, 23, 29, 29, f20);
          tft.pushImage(23, 75, 29, 29, f21);
          tft.pushImage(75, 75, 29, 29, f22);
          tft.drawRect(foodx1, foody1, foodx2, foody2, TFT_WHITE);
          //以上为吃东西的动画
          
          tft.drawString("Hunger +2%", 26, 4, 2);
          delay(1000);
          tft.fillRect(2, 2, 125, 18, TFT_BLACK);
        }
        else
        {
          tft.drawString("Can't eat that much", 4, 4, 2);
          delay(1000);
          tft.fillRect(2, 2, 125, 18, TFT_BLACK);
        }
      }
      //以上为点击确认键（0）时的反应 06
    }
    foodx1 = 22, foody1 = 22, foodx2 = 30, foody2 = 30;
    delay(300);
    mainicon();
  }
}

void maingif()
{
  if(millis() % 280 == 0 && darkmode == 0)
  {
    tft.pushImage(0, 34, 128, 60, forest1[frame1]);
    frame1 += 1;
    if(frame1 >= 75)
    {
      frame1 = 0;
    }
  }

  else if(millis() % 170 == 0 && darkmode == 1)
  {
    tft.pushImage(0, 35, 128, 58, forest2[frame1]);
    frame1 += 1;
    if(frame1 >= 20)
    {
      frame1 = 0;
    }
  }
}

void Sleep()
{
  if(digitalRead(0) == 0)
  {
    delay(300);
    tft.fillScreen(TFT_BLACK);
    tft.drawString("5 minutes", 10, 15, 2);
    tft.drawString("20 minutes", 10, 40, 2);
    tft.drawString("1 hour", 10, 65, 2);
    tft.drawString("8 hours", 10, 90, 2);
    sleepx1 = 5, sleepy1 = 13, sleepx2 = 76, sleepy2 = 21;
    sleep_page = 0;
    tft.drawRect(sleepx1, sleepy1, sleepx2, sleepy2, TFT_WHITE);
    
    while(!(sleeptime == 150 || sleeptime == 600 || sleeptime == 1800 || sleeptime == 14400))
    {
      if(digitalRead(47) == 0 && sleepy1 == 13 && sleep_page == 0)
      {
        tft.drawRect(sleepx1, sleepy1, sleepx2, sleepy2, TFT_BLACK);
        sleepy1 += 25;
        tft.drawRect(sleepx1, sleepy1, sleepx2, sleepy2, TFT_WHITE);
        delay(300);
      }
  
      else if(digitalRead(47) == 0 && sleepy1 == 38 && sleep_page == 0)
      {
        tft.drawRect(sleepx1, sleepy1, sleepx2, sleepy2, TFT_BLACK);
        sleepy1 += 25;
        tft.drawRect(sleepx1, sleepy1, sleepx2, sleepy2, TFT_WHITE);
        delay(300);
      }
  
      else if(digitalRead(47) == 0 && sleepy1 == 63 && sleep_page == 0)
      {
        tft.drawRect(sleepx1, sleepy1, sleepx2, sleepy2, TFT_BLACK);
        sleepy1 += 25;
        tft.drawRect(sleepx1, sleepy1, sleepx2, sleepy2, TFT_WHITE);
        delay(300);
      }
  
      else if(digitalRead(47) == 0 && sleepy1 == 88 && sleep_page == 0)
      {
        tft.fillScreen(TFT_BLACK);
        tft.drawString("Exit", 10, 15, 2);
        tft.drawRect(sleepx1, sleepy1, sleepx2, sleepy2, TFT_BLACK);
        sleepy1 = 13;
        sleep_page += 1;
        tft.drawRect(sleepx1, sleepy1, sleepx2, sleepy2, TFT_WHITE);
        delay(300);
      }

      else if(digitalRead(47) == 0 && sleepy1 == 13 && sleep_page == 1)
      {
        tft.fillScreen(TFT_BLACK);
        tft.drawString("5 minutes", 10, 15, 2);
        tft.drawString("20 minutes", 10, 40, 2);
        tft.drawString("1 hour", 10, 65, 2);
        tft.drawString("8 hours", 10, 90, 2);
        sleepy1 = 13;
        tft.drawRect(sleepx1, sleepy1, sleepx2, sleepy2, TFT_WHITE);
        sleep_page -= 1;
        delay(300);
      }

      else if(digitalRead(0) == 0 && sleepy1 == 13 && sleep_page == 0)
      {
        for(int i = 0; i < 150; ++i)
        {
          tft.fillScreen(TFT_BLACK);
          delay(500);
          tft.drawString("Z", 60, 60, 4);
          delay(500);
          tft.drawString("z", 75, 45, 2);
          delay(500);
          tft.drawString("z", 83, 37, 2);
          delay(500);
          sleeptime += 1;
        }
        Fat_mas += 2;
      }

      else if(digitalRead(0) == 0 && sleepy1 == 38 && sleep_page == 0)
      {
        for(int i = 0; i < 600; ++i)
        {
          tft.fillScreen(TFT_BLACK);
          delay(500);
          tft.drawString("Z", 60, 60, 4);
          delay(500);
          tft.drawString("z", 75, 45, 2);
          delay(500);
          tft.drawString("z", 83, 37, 2);
          delay(500);
          sleeptime += 1;
        }
        Fat_mas += 10;
      }

      else if(digitalRead(0) == 0 && sleepy1 == 63 && sleep_page == 0)
      {
        for(int i = 0; i < 1800; ++i)
        {
          tft.fillScreen(TFT_BLACK);
          delay(500);
          tft.drawString("Z", 60, 60, 4);
          delay(500);
          tft.drawString("z", 75, 45, 2);
          delay(500);
          tft.drawString("z", 83, 37, 2);
          delay(500);
          sleeptime += 1;
        }
        Fat_mas += 20;
      }

      else if(digitalRead(0) == 0 && sleepy1 == 88 && sleep_page == 0)
      {
        for(int i = 0; i < 14400; ++i)
        {
          tft.fillScreen(TFT_BLACK);
          delay(500);
          tft.drawString("Z", 60, 60, 4);
          delay(500);
          tft.drawString("z", 75, 45, 2);
          delay(500);
          tft.drawString("z", 83, 37, 2);
          delay(500);
          sleeptime += 1;
        }
        Fat_mas += 50;
      }

      else if(digitalRead(0) == 0 && sleepy1 == 13 && sleep_page == 1)
      {
        sleeptime = 600;//假装睡觉，实则退出
        delay(300);
      }
    }
    sleeptime = 0;
    mainicon();
  }
}

void Roomfood()
{
  if(digitalRead(0) == 0)
  {
    delay(300);
    frame1 = 0;
    tft.pushImage(0, 12, 128, 104, eatgif[frame1]);
    delay(300);
    for(int i = 0; i < 6; ++i)
    {
      tft.pushImage(0, 12, 128, 104, eatgif[frame1]);
      frame1++;
      delay(300);
    }
    tft.fillScreen(TFT_BLACK);
    food_page = 0;
    tft.pushImage(23, 23, 29, 29, f01);
    tft.pushImage(75, 23, 29, 29, f02);
    tft.pushImage(23, 75, 29, 29, f03);
    tft.pushImage(75, 75, 29, 29, f22);

    Hun_s = Hun; //把饥饿值Hun赋值给判断用的Hun_s
    tft.drawRect(foodx1, foody1, foodx2, foody2, TFT_WHITE);
    while(!(digitalRead(0) == 0 && foodx1 == 74 && foody1 == 74))
    {
      if(digitalRead(47) == 0 && foodx1 == 22 && foody1 == 22)
      {
        tft.drawRect(foodx1, foody1, foodx2, foody2, TFT_BLACK);
        foodx1 += n_food;
        tft.drawRect(foodx1, foody1, foodx2, foody2, TFT_WHITE);
        delay(300);
      }
  
      else if(digitalRead(47) == 0 && foodx1 == 74 && foody1 == 22)
      {
        tft.drawRect(foodx1, foody1, foodx2, foody2, TFT_BLACK);
        foodx1 -= n_food;
        foody1 += n_food;
        tft.drawRect(foodx1, foody1, foodx2, foody2, TFT_WHITE);
        delay(300);
      }
  
      else if(digitalRead(47) == 0 && foodx1 == 22 && foody1 == 74)
      {
        tft.drawRect(foodx1, foody1, foodx2, foody2, TFT_BLACK);
        foodx1 += n_food;
        tft.drawRect(foodx1, foody1, foodx2, foody2, TFT_WHITE);
        delay(300);
      }
  
      else if(digitalRead(47) == 0 && foodx1 == 74 && foody1 == 74)
      {
        tft.drawRect(foodx1, foody1, foodx2, foody2, TFT_BLACK);
        foodx1 -= n_food;
        foody1 -= n_food;
        if(food_page < 6)
        {
          food_page += 1;
          if(food_page == 1)
          {
            tft.pushImage(23, 23, 29, 29, f04);
            tft.pushImage(75, 23, 29, 29, f05);
            tft.pushImage(23, 75, 29, 29, f06);
            tft.pushImage(75, 75, 29, 29, f22);
          }

          else if(food_page == 2)
          {
            tft.pushImage(23, 23, 29, 29, f07);
            tft.pushImage(75, 23, 29, 29, f08);
            tft.pushImage(23, 75, 29, 29, f09);
            tft.pushImage(75, 75, 29, 29, f22);
          }

          else if(food_page == 3)
          {
            tft.pushImage(23, 23, 29, 29, f10);
            tft.pushImage(75, 23, 29, 29, f11);
            tft.pushImage(23, 75, 29, 29, f12);
            tft.pushImage(75, 75, 29, 29, f22);
          }

          else if(food_page == 4)
          {
            tft.pushImage(23, 23, 29, 29, f13);
            tft.pushImage(75, 23, 29, 29, f14);
            tft.pushImage(23, 75, 29, 29, f15);
            tft.pushImage(75, 75, 29, 29, f22);
          }

          else if(food_page == 5)
          {
            tft.pushImage(23, 23, 29, 29, f16);
            tft.pushImage(75, 23, 29, 29, f17);
            tft.pushImage(23, 75, 29, 29, f18);
            tft.pushImage(75, 75, 29, 29, f22);
          }

          else if(food_page == 6)
          {
            tft.pushImage(23, 23, 29, 29, f19);
            tft.pushImage(75, 23, 29, 29, f20);
            tft.pushImage(23, 75, 29, 29, f21);
            tft.pushImage(75, 75, 29, 29, f22);
          }

        }
        else if(food_page >= 6)
        {
          food_page = 0;
          tft.pushImage(23, 23, 29, 29, f01);
          tft.pushImage(75, 23, 29, 29, f02);
          tft.pushImage(23, 75, 29, 29, f03);
          tft.pushImage(75, 75, 29, 29, f22);
        }
        tft.drawRect(foodx1, foody1, foodx2, foody2, TFT_WHITE);
        delay(300);
      }
      
      
      //以下为点击确认键（0）时的反应 00
      else if(digitalRead(0) == 0 && foodx1 == 22 && foody1 == 22 && food_page == 0)
      {
        if(Hun_s <= 85)
        {
          Hun_mas += 15;
          Hun_s += 15; //在饥饿值增加的同时，判断用的饥饿值也增加

          //以下为吃东西的动画
          tft.fillScreen(TFT_BLACK);
          tft.drawRect(0, 88, 128, 40, TFT_WHITE);
          tft.pushImage(49, 49, 29, 29, f01);
          delay(500);
          tft.fillRect(49, 49, 29, 29, TFT_BLACK);
          tft.pushImage(49, 74, 29, 29, f01);
          delay(500);
          tft.fillRect(49, 74, 29, 29, TFT_BLACK);
          tft.pushImage(49, 92, 29, 29, f01);
          tft.drawRect(0, 88, 128, 40, TFT_WHITE);
          delay(500);
          tft.pushImage(0, 0, 128, 88, mikurueat);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat2);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat3);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat4);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat5);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat6);
          delay(200);
          tft.fillRect(49, 92, 29, 29, TFT_BLACK);
          tft.pushImage(0, 0, 128, 88, mikurueat7);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat8);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat9);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat10);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat11);
          delay(200);
          tft.fillScreen(TFT_BLACK);
          tft.pushImage(23, 23, 29, 29, f01);
          tft.pushImage(75, 23, 29, 29, f02);
          tft.pushImage(23, 75, 29, 29, f03);
          tft.pushImage(75, 75, 29, 29, f22);
          tft.drawRect(foodx1, foody1, foodx2, foody2, TFT_WHITE);
          //以上为吃东西的动画
          
          tft.drawString("Hunger +15%", 26, 4, 2);
          delay(1000);
          tft.fillRect(2, 2, 125, 18, TFT_BLACK);
        }
        else
        {
          tft.drawString("Can't eat that much", 4, 4, 2);
          delay(1000);
          tft.fillRect(2, 2, 125, 18, TFT_BLACK);
        }
      }

      else if(digitalRead(0) == 0 && foodx1 == 74 && foody1 == 22 && food_page == 0)
      {
        if(Hun_s <= 95)
        {
          Hun_mas += 5;
          Hun_s += 5;

          //以下为吃东西的动画
          tft.fillScreen(TFT_BLACK);
          tft.drawRect(0, 88, 128, 40, TFT_WHITE);
          tft.pushImage(49, 49, 29, 29, f02);
          delay(500);
          tft.fillRect(49, 49, 29, 29, TFT_BLACK);
          tft.pushImage(49, 74, 29, 29, f02);
          delay(500);
          tft.fillRect(49, 74, 29, 29, TFT_BLACK);
          tft.pushImage(49, 92, 29, 29, f02);
          tft.drawRect(0, 88, 128, 40, TFT_WHITE);
          delay(500);
          tft.pushImage(0, 0, 128, 88, mikurueat);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat2);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat3);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat4);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat5);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat6);
          delay(200);
          tft.fillRect(49, 92, 29, 29, TFT_BLACK);
          tft.pushImage(0, 0, 128, 88, mikurueat7);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat8);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat9);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat10);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat11);
          delay(200);
          tft.fillScreen(TFT_BLACK);
          tft.pushImage(23, 23, 29, 29, f01);
          tft.pushImage(75, 23, 29, 29, f02);
          tft.pushImage(23, 75, 29, 29, f03);
          tft.pushImage(75, 75, 29, 29, f22);
          tft.drawRect(foodx1, foody1, foodx2, foody2, TFT_WHITE);
          //以上为吃东西的动画
          
          tft.drawString("Hunger +5%", 26, 4, 2);
          delay(1000);
          tft.fillRect(2, 2, 125, 18, TFT_BLACK);
        }
        else
        {
          tft.drawString("Can't eat that much", 4, 4, 2);
          delay(1000);
          tft.fillRect(2, 2, 125, 18, TFT_BLACK);
        }
      }

      else if(digitalRead(0) == 0 && foodx1 == 22 && foody1 == 74 && food_page == 0)
      {
        if(Hun_s <= 98)
        {
          Hun_mas += 2;
          Hun_s += 2;

          //以下为吃东西的动画
          tft.fillScreen(TFT_BLACK);
          tft.drawRect(0, 88, 128, 40, TFT_WHITE);
          tft.pushImage(49, 49, 29, 29, f03);
          delay(500);
          tft.fillRect(49, 49, 29, 29, TFT_BLACK);
          tft.pushImage(49, 74, 29, 29, f03);
          delay(500);
          tft.fillRect(49, 74, 29, 29, TFT_BLACK);
          tft.pushImage(49, 92, 29, 29, f03);
          tft.drawRect(0, 88, 128, 40, TFT_WHITE);
          delay(500);
          tft.pushImage(0, 0, 128, 88, mikurueat);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat2);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat3);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat4);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat5);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat6);
          delay(200);
          tft.fillRect(49, 92, 29, 29, TFT_BLACK);
          tft.pushImage(0, 0, 128, 88, mikurueat7);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat8);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat9);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat10);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat11);
          delay(200);
          tft.fillScreen(TFT_BLACK);
          tft.pushImage(23, 23, 29, 29, f01);
          tft.pushImage(75, 23, 29, 29, f02);
          tft.pushImage(23, 75, 29, 29, f03);
          tft.pushImage(75, 75, 29, 29, f22);
          tft.drawRect(foodx1, foody1, foodx2, foody2, TFT_WHITE);
          //以上为吃东西的动画
          
          tft.drawString("Hunger +2%", 26, 4, 2);
          delay(1000);
          tft.fillRect(2, 2, 125, 18, TFT_BLACK);
        }
        else
        {
          tft.drawString("Can't eat that much", 4, 4, 2);
          delay(1000);
          tft.fillRect(2, 2, 125, 18, TFT_BLACK);
        }
      }
      //以上为点击确认键（0）时的反应 00

      //以下为点击确认键（0）时的反应 01
      else if(digitalRead(0) == 0 && foodx1 == 22 && foody1 == 22 && food_page == 1)
      {
        if(Hun_s <= 85)
        {
          Hun_mas += 15;
          Hun_s += 15; //在饥饿值增加的同时，判断用的饥饿值也增加

          //以下为吃东西的动画
          tft.fillScreen(TFT_BLACK);
          tft.drawRect(0, 88, 128, 40, TFT_WHITE);
          tft.pushImage(49, 49, 29, 29, f04);
          delay(500);
          tft.fillRect(49, 49, 29, 29, TFT_BLACK);
          tft.pushImage(49, 74, 29, 29, f04);
          delay(500);
          tft.fillRect(49, 74, 29, 29, TFT_BLACK);
          tft.pushImage(49, 92, 29, 29, f04);
          tft.drawRect(0, 88, 128, 40, TFT_WHITE);
          delay(500);
          tft.pushImage(0, 0, 128, 88, mikurueat);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat2);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat3);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat4);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat5);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat6);
          delay(200);
          tft.fillRect(49, 92, 29, 29, TFT_BLACK);
          tft.pushImage(0, 0, 128, 88, mikurueat7);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat8);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat9);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat10);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat11);
          delay(200);
          tft.fillScreen(TFT_BLACK);
          tft.pushImage(23, 23, 29, 29, f04);
          tft.pushImage(75, 23, 29, 29, f05);
          tft.pushImage(23, 75, 29, 29, f06);
          tft.pushImage(75, 75, 29, 29, f22);
          tft.drawRect(foodx1, foody1, foodx2, foody2, TFT_WHITE);
          //以上为吃东西的动画
          
          tft.drawString("Hunger +15%", 26, 4, 2);
          delay(1000);
          tft.fillRect(2, 2, 125, 18, TFT_BLACK);
        }
        else
        {
          tft.drawString("Can't eat that much", 4, 4, 2);
          delay(1000);
          tft.fillRect(2, 2, 125, 18, TFT_BLACK);
        }
      }

      else if(digitalRead(0) == 0 && foodx1 == 74 && foody1 == 22 && food_page == 1)
      {
        if(Hun_s <= 95)
        {
          Hun_mas += 5;
          Hun_s += 5;

          //以下为吃东西的动画
          tft.fillScreen(TFT_BLACK);
          tft.drawRect(0, 88, 128, 40, TFT_WHITE);
          tft.pushImage(49, 49, 29, 29, f05);
          delay(500);
          tft.fillRect(49, 49, 29, 29, TFT_BLACK);
          tft.pushImage(49, 74, 29, 29, f05);
          delay(500);
          tft.fillRect(49, 74, 29, 29, TFT_BLACK);
          tft.pushImage(49, 92, 29, 29, f05);
          tft.drawRect(0, 88, 128, 40, TFT_WHITE);
          delay(500);
          tft.pushImage(0, 0, 128, 88, mikurueat);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat2);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat3);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat4);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat5);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat6);
          delay(200);
          tft.fillRect(49, 92, 29, 29, TFT_BLACK);
          tft.pushImage(0, 0, 128, 88, mikurueat7);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat8);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat9);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat10);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat11);
          delay(200);
          tft.fillScreen(TFT_BLACK);
          tft.pushImage(23, 23, 29, 29, f04);
          tft.pushImage(75, 23, 29, 29, f05);
          tft.pushImage(23, 75, 29, 29, f06);
          tft.pushImage(75, 75, 29, 29, f22);
          tft.drawRect(foodx1, foody1, foodx2, foody2, TFT_WHITE);
          //以上为吃东西的动画
          
          tft.drawString("Hunger +5%", 26, 4, 2);
          delay(1000);
          tft.fillRect(2, 2, 125, 18, TFT_BLACK);
        }
        else
        {
          tft.drawString("Can't eat that much", 4, 4, 2);
          delay(1000);
          tft.fillRect(2, 2, 125, 18, TFT_BLACK);
        }
      }

      else if(digitalRead(0) == 0 && foodx1 == 22 && foody1 == 74 && food_page == 1)
      {
        if(Hun_s <= 98)
        {
          Hun_mas += 2;
          Hun_s += 2;

          //以下为吃东西的动画
          tft.fillScreen(TFT_BLACK);
          tft.drawRect(0, 88, 128, 40, TFT_WHITE);
          tft.pushImage(49, 49, 29, 29, f06);
          delay(500);
          tft.fillRect(49, 49, 29, 29, TFT_BLACK);
          tft.pushImage(49, 74, 29, 29, f06);
          delay(500);
          tft.fillRect(49, 74, 29, 29, TFT_BLACK);
          tft.pushImage(49, 92, 29, 29, f06);
          tft.drawRect(0, 88, 128, 40, TFT_WHITE);
          delay(500);
          tft.pushImage(0, 0, 128, 88, mikurueat);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat2);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat3);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat4);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat5);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat6);
          delay(200);
          tft.fillRect(49, 92, 29, 29, TFT_BLACK);
          tft.pushImage(0, 0, 128, 88, mikurueat7);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat8);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat9);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat10);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat11);
          delay(200);
          tft.fillScreen(TFT_BLACK);
          tft.pushImage(23, 23, 29, 29, f04);
          tft.pushImage(75, 23, 29, 29, f05);
          tft.pushImage(23, 75, 29, 29, f06);
          tft.pushImage(75, 75, 29, 29, f22);
          tft.drawRect(foodx1, foody1, foodx2, foody2, TFT_WHITE);
          //以上为吃东西的动画
          
          tft.drawString("Hunger +2%", 26, 4, 2);
          delay(1000);
          tft.fillRect(2, 2, 125, 18, TFT_BLACK);
        }
        else
        {
          tft.drawString("Can't eat that much", 4, 4, 2);
          delay(1000);
          tft.fillRect(2, 2, 125, 18, TFT_BLACK);
        }
      }
      //以上为点击确认键（0）时的反应 01

      //以下为点击确认键（0）时的反应 02
      else if(digitalRead(0) == 0 && foodx1 == 22 && foody1 == 22 && food_page == 2)
      {
        if(Hun_s <= 85)
        {
          Hun_mas += 15;
          Hun_s += 15; //在饥饿值增加的同时，判断用的饥饿值也增加

          //以下为吃东西的动画
          tft.fillScreen(TFT_BLACK);
          tft.drawRect(0, 88, 128, 40, TFT_WHITE);
          tft.pushImage(49, 49, 29, 29, f07);
          delay(500);
          tft.fillRect(49, 49, 29, 29, TFT_BLACK);
          tft.pushImage(49, 74, 29, 29, f07);
          delay(500);
          tft.fillRect(49, 74, 29, 29, TFT_BLACK);
          tft.pushImage(49, 92, 29, 29, f07);
          tft.drawRect(0, 88, 128, 40, TFT_WHITE);
          delay(500);
          tft.pushImage(0, 0, 128, 88, mikurueat);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat2);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat3);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat4);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat5);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat6);
          delay(200);
          tft.fillRect(49, 92, 29, 29, TFT_BLACK);
          tft.pushImage(0, 0, 128, 88, mikurueat7);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat8);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat9);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat10);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat11);
          delay(200);
          tft.fillScreen(TFT_BLACK);
          tft.pushImage(23, 23, 29, 29, f07);
          tft.pushImage(75, 23, 29, 29, f08);
          tft.pushImage(23, 75, 29, 29, f09);
          tft.pushImage(75, 75, 29, 29, f22);
          tft.drawRect(foodx1, foody1, foodx2, foody2, TFT_WHITE);
          //以上为吃东西的动画
          
          tft.drawString("Hunger +15%", 26, 4, 2);
          delay(1000);
          tft.fillRect(2, 2, 125, 18, TFT_BLACK);
        }
        else
        {
          tft.drawString("Can't eat that much", 4, 4, 2);
          delay(1000);
          tft.fillRect(2, 2, 125, 18, TFT_BLACK);
        }
      }

      else if(digitalRead(0) == 0 && foodx1 == 74 && foody1 == 22 && food_page == 2)
      {
        if(Hun_s <= 95)
        {
          Hun_mas += 5;
          Hun_s += 5;

          //以下为吃东西的动画
          tft.fillScreen(TFT_BLACK);
          tft.drawRect(0, 88, 128, 40, TFT_WHITE);
          tft.pushImage(49, 49, 29, 29, f08);
          delay(500);
          tft.fillRect(49, 49, 29, 29, TFT_BLACK);
          tft.pushImage(49, 74, 29, 29, f08);
          delay(500);
          tft.fillRect(49, 74, 29, 29, TFT_BLACK);
          tft.pushImage(49, 92, 29, 29, f08);
          tft.drawRect(0, 88, 128, 40, TFT_WHITE);
          delay(500);
          tft.pushImage(0, 0, 128, 88, mikurueat);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat2);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat3);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat4);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat5);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat6);
          delay(200);
          tft.fillRect(49, 92, 29, 29, TFT_BLACK);
          tft.pushImage(0, 0, 128, 88, mikurueat7);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat8);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat9);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat10);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat11);
          delay(200);
          tft.fillScreen(TFT_BLACK);
          tft.pushImage(23, 23, 29, 29, f07);
          tft.pushImage(75, 23, 29, 29, f08);
          tft.pushImage(23, 75, 29, 29, f09);
          tft.pushImage(75, 75, 29, 29, f22);
          tft.drawRect(foodx1, foody1, foodx2, foody2, TFT_WHITE);
          //以上为吃东西的动画
          
          tft.drawString("Hunger +5%", 26, 4, 2);
          delay(1000);
          tft.fillRect(2, 2, 125, 18, TFT_BLACK);
        }
        else
        {
          tft.drawString("Can't eat that much", 4, 4, 2);
          delay(1000);
          tft.fillRect(2, 2, 125, 18, TFT_BLACK);
        }
      }

      else if(digitalRead(0) == 0 && foodx1 == 22 && foody1 == 74 && food_page == 2)
      {
        if(Hun_s <= 98)
        {
          Hun_mas += 2;
          Hun_s += 2;

          //以下为吃东西的动画
          tft.fillScreen(TFT_BLACK);
          tft.drawRect(0, 88, 128, 40, TFT_WHITE);
          tft.pushImage(49, 49, 29, 29, f09);
          delay(500);
          tft.fillRect(49, 49, 29, 29, TFT_BLACK);
          tft.pushImage(49, 74, 29, 29, f09);
          delay(500);
          tft.fillRect(49, 74, 29, 29, TFT_BLACK);
          tft.pushImage(49, 92, 29, 29, f09);
          tft.drawRect(0, 88, 128, 40, TFT_WHITE);
          delay(500);
          tft.pushImage(0, 0, 128, 88, mikurueat);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat2);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat3);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat4);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat5);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat6);
          delay(200);
          tft.fillRect(49, 92, 29, 29, TFT_BLACK);
          tft.pushImage(0, 0, 128, 88, mikurueat7);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat8);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat9);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat10);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat11);
          delay(200);
          tft.fillScreen(TFT_BLACK);
          tft.pushImage(23, 23, 29, 29, f07);
          tft.pushImage(75, 23, 29, 29, f08);
          tft.pushImage(23, 75, 29, 29, f09);
          tft.pushImage(75, 75, 29, 29, f22);
          tft.drawRect(foodx1, foody1, foodx2, foody2, TFT_WHITE);
          //以上为吃东西的动画
          
          tft.drawString("Hunger +2%", 26, 4, 2);
          delay(1000);
          tft.fillRect(2, 2, 125, 18, TFT_BLACK);
        }
        else
        {
          tft.drawString("Can't eat that much", 4, 4, 2);
          delay(1000);
          tft.fillRect(2, 2, 125, 18, TFT_BLACK);
        }
      }
      //以上为点击确认键（0）时的反应 02

      //以下为点击确认键（0）时的反应 03
      else if(digitalRead(0) == 0 && foodx1 == 22 && foody1 == 22 && food_page == 3)
      {
        if(Hun_s <= 85)
        {
          Hun_mas += 15;
          Hun_s += 15; //在饥饿值增加的同时，判断用的饥饿值也增加

          //以下为吃东西的动画
          tft.fillScreen(TFT_BLACK);
          tft.drawRect(0, 88, 128, 40, TFT_WHITE);
          tft.pushImage(49, 49, 29, 29, f10);
          delay(500);
          tft.fillRect(49, 49, 29, 29, TFT_BLACK);
          tft.pushImage(49, 74, 29, 29, f10);
          delay(500);
          tft.fillRect(49, 74, 29, 29, TFT_BLACK);
          tft.pushImage(49, 92, 29, 29, f10);
          tft.drawRect(0, 88, 128, 40, TFT_WHITE);
          delay(500);
          tft.pushImage(0, 0, 128, 88, mikurueat);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat2);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat3);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat4);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat5);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat6);
          delay(200);
          tft.fillRect(49, 92, 29, 29, TFT_BLACK);
          tft.pushImage(0, 0, 128, 88, mikurueat7);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat8);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat9);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat10);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat11);
          delay(200);
          tft.fillScreen(TFT_BLACK);
          tft.pushImage(23, 23, 29, 29, f10);
          tft.pushImage(75, 23, 29, 29, f11);
          tft.pushImage(23, 75, 29, 29, f12);
          tft.pushImage(75, 75, 29, 29, f22);
          tft.drawRect(foodx1, foody1, foodx2, foody2, TFT_WHITE);
          //以上为吃东西的动画
          
          tft.drawString("Hunger +15%", 26, 4, 2);
          delay(1000);
          tft.fillRect(2, 2, 125, 18, TFT_BLACK);
        }
        else
        {
          tft.drawString("Can't eat that much", 4, 4, 2);
          delay(1000);
          tft.fillRect(2, 2, 125, 18, TFT_BLACK);
        }
      }

      else if(digitalRead(0) == 0 && foodx1 == 74 && foody1 == 22 && food_page == 3)
      {
        if(Hun_s <= 95)
        {
          Hun_mas += 5;
          Hun_s += 5;

          //以下为吃东西的动画
          tft.fillScreen(TFT_BLACK);
          tft.drawRect(0, 88, 128, 40, TFT_WHITE);
          tft.pushImage(49, 49, 29, 29, f11);
          delay(500);
          tft.fillRect(49, 49, 29, 29, TFT_BLACK);
          tft.pushImage(49, 74, 29, 29, f11);
          delay(500);
          tft.fillRect(49, 74, 29, 29, TFT_BLACK);
          tft.pushImage(49, 92, 29, 29, f11);
          tft.drawRect(0, 88, 128, 40, TFT_WHITE);
          delay(500);
          tft.pushImage(0, 0, 128, 88, mikurueat);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat2);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat3);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat4);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat5);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat6);
          delay(200);
          tft.fillRect(49, 92, 29, 29, TFT_BLACK);
          tft.pushImage(0, 0, 128, 88, mikurueat7);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat8);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat9);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat10);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat11);
          delay(200);
          tft.fillScreen(TFT_BLACK);
          tft.pushImage(23, 23, 29, 29, f10);
          tft.pushImage(75, 23, 29, 29, f11);
          tft.pushImage(23, 75, 29, 29, f12);
          tft.pushImage(75, 75, 29, 29, f22);
          tft.drawRect(foodx1, foody1, foodx2, foody2, TFT_WHITE);
          //以上为吃东西的动画
          
          tft.drawString("Hunger +5%", 26, 4, 2);
          delay(1000);
          tft.fillRect(2, 2, 125, 18, TFT_BLACK);
        }
        else
        {
          tft.drawString("Can't eat that much", 4, 4, 2);
          delay(1000);
          tft.fillRect(2, 2, 125, 18, TFT_BLACK);
        }
      }

      else if(digitalRead(0) == 0 && foodx1 == 22 && foody1 == 74 && food_page == 3)
      {
        if(Hun_s <= 98)
        {
          Hun_mas += 2;
          Hun_s += 2;

          //以下为吃东西的动画
          tft.fillScreen(TFT_BLACK);
          tft.drawRect(0, 88, 128, 40, TFT_WHITE);
          tft.pushImage(49, 49, 29, 29, f12);
          delay(500);
          tft.fillRect(49, 49, 29, 29, TFT_BLACK);
          tft.pushImage(49, 74, 29, 29, f12);
          delay(500);
          tft.fillRect(49, 74, 29, 29, TFT_BLACK);
          tft.pushImage(49, 92, 29, 29, f12);
          tft.drawRect(0, 88, 128, 40, TFT_WHITE);
          delay(500);
          tft.pushImage(0, 0, 128, 88, mikurueat);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat2);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat3);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat4);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat5);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat6);
          delay(200);
          tft.fillRect(49, 92, 29, 29, TFT_BLACK);
          tft.pushImage(0, 0, 128, 88, mikurueat7);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat8);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat9);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat10);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat11);
          delay(200);
          tft.fillScreen(TFT_BLACK);
          tft.pushImage(23, 23, 29, 29, f10);
          tft.pushImage(75, 23, 29, 29, f11);
          tft.pushImage(23, 75, 29, 29, f12);
          tft.pushImage(75, 75, 29, 29, f22);
          tft.drawRect(foodx1, foody1, foodx2, foody2, TFT_WHITE);
          //以上为吃东西的动画
          
          tft.drawString("Hunger +2%", 26, 4, 2);
          delay(1000);
          tft.fillRect(2, 2, 125, 18, TFT_BLACK);
        }
        else
        {
          tft.drawString("Can't eat that much", 4, 4, 2);
          delay(1000);
          tft.fillRect(2, 2, 125, 18, TFT_BLACK);
        }
      }
      //以上为点击确认键（0）时的反应 03

      //以下为点击确认键（0）时的反应 04
      else if(digitalRead(0) == 0 && foodx1 == 22 && foody1 == 22 && food_page == 4)
      {
        if(Hun_s <= 85)
        {
          Hun_mas += 15;
          Hun_s += 15; //在饥饿值增加的同时，判断用的饥饿值也增加

          //以下为吃东西的动画
          tft.fillScreen(TFT_BLACK);
          tft.drawRect(0, 88, 128, 40, TFT_WHITE);
          tft.pushImage(49, 49, 29, 29, f13);
          delay(500);
          tft.fillRect(49, 49, 29, 29, TFT_BLACK);
          tft.pushImage(49, 74, 29, 29, f13);
          delay(500);
          tft.fillRect(49, 74, 29, 29, TFT_BLACK);
          tft.pushImage(49, 92, 29, 29, f13);
          tft.drawRect(0, 88, 128, 40, TFT_WHITE);
          delay(500);
          tft.pushImage(0, 0, 128, 88, mikurueat);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat2);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat3);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat4);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat5);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat6);
          delay(200);
          tft.fillRect(49, 92, 29, 29, TFT_BLACK);
          tft.pushImage(0, 0, 128, 88, mikurueat7);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat8);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat9);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat10);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat11);
          delay(200);
          tft.fillScreen(TFT_BLACK);
          tft.pushImage(23, 23, 29, 29, f13);
          tft.pushImage(75, 23, 29, 29, f14);
          tft.pushImage(23, 75, 29, 29, f15);
          tft.pushImage(75, 75, 29, 29, f22);
          tft.drawRect(foodx1, foody1, foodx2, foody2, TFT_WHITE);
          //以上为吃东西的动画
          
          tft.drawString("Hunger +15%", 26, 4, 2);
          delay(1000);
          tft.fillRect(2, 2, 125, 18, TFT_BLACK);
        }
        else
        {
          tft.drawString("Can't eat that much", 4, 4, 2);
          delay(1000);
          tft.fillRect(2, 2, 125, 18, TFT_BLACK);
        }
      }

      else if(digitalRead(0) == 0 && foodx1 == 74 && foody1 == 22 && food_page == 4)
      {
        if(Hun_s <= 95)
        {
          Hun_mas += 5;
          Hun_s += 5;

          //以下为吃东西的动画
          tft.fillScreen(TFT_BLACK);
          tft.drawRect(0, 88, 128, 40, TFT_WHITE);
          tft.pushImage(49, 49, 29, 29, f14);
          delay(500);
          tft.fillRect(49, 49, 29, 29, TFT_BLACK);
          tft.pushImage(49, 74, 29, 29, f14);
          delay(500);
          tft.fillRect(49, 74, 29, 29, TFT_BLACK);
          tft.pushImage(49, 92, 29, 29, f14);
          tft.drawRect(0, 88, 128, 40, TFT_WHITE);
          delay(500);
          tft.pushImage(0, 0, 128, 88, mikurueat);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat2);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat3);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat4);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat5);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat6);
          delay(200);
          tft.fillRect(49, 92, 29, 29, TFT_BLACK);
          tft.pushImage(0, 0, 128, 88, mikurueat7);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat8);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat9);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat10);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat11);
          delay(200);
          tft.fillScreen(TFT_BLACK);
          tft.pushImage(23, 23, 29, 29, f13);
          tft.pushImage(75, 23, 29, 29, f14);
          tft.pushImage(23, 75, 29, 29, f15);
          tft.pushImage(75, 75, 29, 29, f22);
          tft.drawRect(foodx1, foody1, foodx2, foody2, TFT_WHITE);
          //以上为吃东西的动画
          
          tft.drawString("Hunger +5%", 26, 4, 2);
          delay(1000);
          tft.fillRect(2, 2, 125, 18, TFT_BLACK);
        }
        else
        {
          tft.drawString("Can't eat that much", 4, 4, 2);
          delay(1000);
          tft.fillRect(2, 2, 125, 18, TFT_BLACK);
        }
      }

      else if(digitalRead(0) == 0 && foodx1 == 22 && foody1 == 74 && food_page == 4)
      {
        if(Hun_s <= 98)
        {
          Hun_mas += 2;
          Hun_s += 2;

          //以下为吃东西的动画
          tft.fillScreen(TFT_BLACK);
          tft.drawRect(0, 88, 128, 40, TFT_WHITE);
          tft.pushImage(49, 49, 29, 29, f15);
          delay(500);
          tft.fillRect(49, 49, 29, 29, TFT_BLACK);
          tft.pushImage(49, 74, 29, 29, f15);
          delay(500);
          tft.fillRect(49, 74, 29, 29, TFT_BLACK);
          tft.pushImage(49, 92, 29, 29, f15);
          tft.drawRect(0, 88, 128, 40, TFT_WHITE);
          delay(500);
          tft.pushImage(0, 0, 128, 88, mikurueat);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat2);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat3);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat4);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat5);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat6);
          delay(200);
          tft.fillRect(49, 92, 29, 29, TFT_BLACK);
          tft.pushImage(0, 0, 128, 88, mikurueat7);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat8);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat9);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat10);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat11);
          delay(200);
          tft.fillScreen(TFT_BLACK);
          tft.pushImage(23, 23, 29, 29, f13);
          tft.pushImage(75, 23, 29, 29, f14);
          tft.pushImage(23, 75, 29, 29, f15);
          tft.pushImage(75, 75, 29, 29, f22);
          tft.drawRect(foodx1, foody1, foodx2, foody2, TFT_WHITE);
          //以上为吃东西的动画
          
          tft.drawString("Hunger +2%", 26, 4, 2);
          delay(1000);
          tft.fillRect(2, 2, 125, 18, TFT_BLACK);
        }
        else
        {
          tft.drawString("Can't eat that much", 4, 4, 2);
          delay(1000);
          tft.fillRect(2, 2, 125, 18, TFT_BLACK);
        }
      }
      //以上为点击确认键（0）时的反应 04

      //以下为点击确认键（0）时的反应 05
      else if(digitalRead(0) == 0 && foodx1 == 22 && foody1 == 22 && food_page == 5)
      {
        if(Hun_s <= 85)
        {
          Hun_mas += 15;
          Hun_s += 15; //在饥饿值增加的同时，判断用的饥饿值也增加

          //以下为吃东西的动画
          tft.fillScreen(TFT_BLACK);
          tft.drawRect(0, 88, 128, 40, TFT_WHITE);
          tft.pushImage(49, 49, 29, 29, f16);
          delay(500);
          tft.fillRect(49, 49, 29, 29, TFT_BLACK);
          tft.pushImage(49, 74, 29, 29, f16);
          delay(500);
          tft.fillRect(49, 74, 29, 29, TFT_BLACK);
          tft.pushImage(49, 92, 29, 29, f16);
          tft.drawRect(0, 88, 128, 40, TFT_WHITE);
          delay(500);
          tft.pushImage(0, 0, 128, 88, mikurueat);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat2);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat3);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat4);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat5);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat6);
          delay(200);
          tft.fillRect(49, 92, 29, 29, TFT_BLACK);
          tft.pushImage(0, 0, 128, 88, mikurueat7);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat8);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat9);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat10);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat11);
          delay(200);
          tft.fillScreen(TFT_BLACK);
          tft.pushImage(23, 23, 29, 29, f16);
          tft.pushImage(75, 23, 29, 29, f17);
          tft.pushImage(23, 75, 29, 29, f18);
          tft.pushImage(75, 75, 29, 29, f22);
          tft.drawRect(foodx1, foody1, foodx2, foody2, TFT_WHITE);
          //以上为吃东西的动画
          
          tft.drawString("Hunger +15%", 26, 4, 2);
          delay(1000);
          tft.fillRect(2, 2, 125, 18, TFT_BLACK);
        }
        else
        {
          tft.drawString("Can't eat that much", 4, 4, 2);
          delay(1000);
          tft.fillRect(2, 2, 125, 18, TFT_BLACK);
        }
      }

      else if(digitalRead(0) == 0 && foodx1 == 74 && foody1 == 22 && food_page == 5)
      {
        if(Hun_s <= 95)
        {
          Hun_mas += 5;
          Hun_s += 5;

          //以下为吃东西的动画
          tft.fillScreen(TFT_BLACK);
          tft.drawRect(0, 88, 128, 40, TFT_WHITE);
          tft.pushImage(49, 49, 29, 29, f17);
          delay(500);
          tft.fillRect(49, 49, 29, 29, TFT_BLACK);
          tft.pushImage(49, 74, 29, 29, f17);
          delay(500);
          tft.fillRect(49, 74, 29, 29, TFT_BLACK);
          tft.pushImage(49, 92, 29, 29, f17);
          tft.drawRect(0, 88, 128, 40, TFT_WHITE);
          delay(500);
          tft.pushImage(0, 0, 128, 88, mikurueat);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat2);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat3);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat4);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat5);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat6);
          delay(200);
          tft.fillRect(49, 92, 29, 29, TFT_BLACK);
          tft.pushImage(0, 0, 128, 88, mikurueat7);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat8);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat9);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat10);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat11);
          delay(200);
          tft.fillScreen(TFT_BLACK);
          tft.pushImage(23, 23, 29, 29, f16);
          tft.pushImage(75, 23, 29, 29, f17);
          tft.pushImage(23, 75, 29, 29, f18);
          tft.pushImage(75, 75, 29, 29, f22);
          tft.drawRect(foodx1, foody1, foodx2, foody2, TFT_WHITE);
          //以上为吃东西的动画
          
          tft.drawString("Hunger +5%", 26, 4, 2);
          delay(1000);
          tft.fillRect(2, 2, 125, 18, TFT_BLACK);
        }
        else
        {
          tft.drawString("Can't eat that much", 4, 4, 2);
          delay(1000);
          tft.fillRect(2, 2, 125, 18, TFT_BLACK);
        }
      }

      else if(digitalRead(0) == 0 && foodx1 == 22 && foody1 == 74 && food_page == 5)
      {
        if(Hun_s <= 98)
        {
          Hun_mas += 2;
          Hun_s += 2;

          //以下为吃东西的动画
          tft.fillScreen(TFT_BLACK);
          tft.drawRect(0, 88, 128, 40, TFT_WHITE);
          tft.pushImage(49, 49, 29, 29, f18);
          delay(500);
          tft.fillRect(49, 49, 29, 29, TFT_BLACK);
          tft.pushImage(49, 74, 29, 29, f18);
          delay(500);
          tft.fillRect(49, 74, 29, 29, TFT_BLACK);
          tft.pushImage(49, 92, 29, 29, f18);
          tft.drawRect(0, 88, 128, 40, TFT_WHITE);
          delay(500);
          tft.pushImage(0, 0, 128, 88, mikurueat);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat2);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat3);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat4);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat5);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat6);
          delay(200);
          tft.fillRect(49, 92, 29, 29, TFT_BLACK);
          tft.pushImage(0, 0, 128, 88, mikurueat7);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat8);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat9);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat10);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat11);
          delay(200);
          tft.fillScreen(TFT_BLACK);
          tft.pushImage(23, 23, 29, 29, f16);
          tft.pushImage(75, 23, 29, 29, f17);
          tft.pushImage(23, 75, 29, 29, f18);
          tft.pushImage(75, 75, 29, 29, f22);
          tft.drawRect(foodx1, foody1, foodx2, foody2, TFT_WHITE);
          //以上为吃东西的动画
          
          tft.drawString("Hunger +2%", 26, 4, 2);
          delay(1000);
          tft.fillRect(2, 2, 125, 18, TFT_BLACK);
        }
        else
        {
          tft.drawString("Can't eat that much", 4, 4, 2);
          delay(1000);
          tft.fillRect(2, 2, 125, 18, TFT_BLACK);
        }
      }
      //以上为点击确认键（0）时的反应 05

      //以下为点击确认键（0）时的反应 06
      else if(digitalRead(0) == 0 && foodx1 == 22 && foody1 == 22 && food_page == 6)
      {
        if(Hun_s <= 85)
        {
          Hun_mas += 15;
          Hun_s += 15; //在饥饿值增加的同时，判断用的饥饿值也增加

          //以下为吃东西的动画
          tft.fillScreen(TFT_BLACK);
          tft.drawRect(0, 88, 128, 40, TFT_WHITE);
          tft.pushImage(49, 49, 29, 29, f19);
          delay(500);
          tft.fillRect(49, 49, 29, 29, TFT_BLACK);
          tft.pushImage(49, 74, 29, 29, f19);
          delay(500);
          tft.fillRect(49, 74, 29, 29, TFT_BLACK);
          tft.pushImage(49, 92, 29, 29, f19);
          tft.drawRect(0, 88, 128, 40, TFT_WHITE);
          delay(500);
          tft.pushImage(0, 0, 128, 88, mikurueat);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat2);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat3);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat4);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat5);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat6);
          delay(200);
          tft.fillRect(49, 92, 29, 29, TFT_BLACK);
          tft.pushImage(0, 0, 128, 88, mikurueat7);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat8);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat9);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat10);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat11);
          delay(200);
          tft.fillScreen(TFT_BLACK);
          tft.pushImage(23, 23, 29, 29, f19);
          tft.pushImage(75, 23, 29, 29, f20);
          tft.pushImage(23, 75, 29, 29, f21);
          tft.pushImage(75, 75, 29, 29, f22);
          tft.drawRect(foodx1, foody1, foodx2, foody2, TFT_WHITE);
          //以上为吃东西的动画
          
          tft.drawString("Hunger +15%", 26, 4, 2);
          delay(1000);
          tft.fillRect(2, 2, 125, 18, TFT_BLACK);
        }
        else
        {
          tft.drawString("Can't eat that much", 4, 4, 2);
          delay(1000);
          tft.fillRect(2, 2, 125, 18, TFT_BLACK);
        }
      }

      else if(digitalRead(0) == 0 && foodx1 == 74 && foody1 == 22 && food_page == 6)
      {
        if(Hun_s <= 95)
        {
          Hun_mas += 5;
          Hun_s += 5;

          //以下为吃东西的动画
          tft.fillScreen(TFT_BLACK);
          tft.drawRect(0, 88, 128, 40, TFT_WHITE);
          tft.pushImage(49, 49, 29, 29, f20);
          delay(500);
          tft.fillRect(49, 49, 29, 29, TFT_BLACK);
          tft.pushImage(49, 74, 29, 29, f20);
          delay(500);
          tft.fillRect(49, 74, 29, 29, TFT_BLACK);
          tft.pushImage(49, 92, 29, 29, f20);
          tft.drawRect(0, 88, 128, 40, TFT_WHITE);
          delay(500);
          tft.pushImage(0, 0, 128, 88, mikurueat);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat2);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat3);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat4);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat5);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat6);
          delay(200);
          tft.fillRect(49, 92, 29, 29, TFT_BLACK);
          tft.pushImage(0, 0, 128, 88, mikurueat7);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat8);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat9);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat10);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat11);
          delay(200);
          tft.fillScreen(TFT_BLACK);
          tft.pushImage(23, 23, 29, 29, f19);
          tft.pushImage(75, 23, 29, 29, f20);
          tft.pushImage(23, 75, 29, 29, f21);
          tft.pushImage(75, 75, 29, 29, f22);
          tft.drawRect(foodx1, foody1, foodx2, foody2, TFT_WHITE);
          //以上为吃东西的动画
          
          tft.drawString("Hunger +5%", 26, 4, 2);
          delay(1000);
          tft.fillRect(2, 2, 125, 18, TFT_BLACK);
        }
        else
        {
          tft.drawString("Can't eat that much", 4, 4, 2);
          delay(1000);
          tft.fillRect(2, 2, 125, 18, TFT_BLACK);
        }
      }

      else if(digitalRead(0) == 0 && foodx1 == 22 && foody1 == 74 && food_page == 6)
      {
        if(Hun_s <= 98)
        {
          Hun_mas += 2;
          Hun_s += 2;

          //以下为吃东西的动画
          tft.fillScreen(TFT_BLACK);
          tft.drawRect(0, 88, 128, 40, TFT_WHITE);
          tft.pushImage(49, 49, 29, 29, f21);
          delay(500);
          tft.fillRect(49, 49, 29, 29, TFT_BLACK);
          tft.pushImage(49, 74, 29, 29, f21);
          delay(500);
          tft.fillRect(49, 74, 29, 29, TFT_BLACK);
          tft.pushImage(49, 92, 29, 29, f21);
          tft.drawRect(0, 88, 128, 40, TFT_WHITE);
          delay(500);
          tft.pushImage(0, 0, 128, 88, mikurueat);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat2);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat3);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat4);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat5);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat6);
          delay(200);
          tft.fillRect(49, 92, 29, 29, TFT_BLACK);
          tft.pushImage(0, 0, 128, 88, mikurueat7);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat8);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat9);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat10);
          delay(200);
          tft.pushImage(0, 0, 128, 88, mikurueat11);
          delay(200);
          tft.fillScreen(TFT_BLACK);
          tft.pushImage(23, 23, 29, 29, f19);
          tft.pushImage(75, 23, 29, 29, f20);
          tft.pushImage(23, 75, 29, 29, f21);
          tft.pushImage(75, 75, 29, 29, f22);
          tft.drawRect(foodx1, foody1, foodx2, foody2, TFT_WHITE);
          //以上为吃东西的动画
          
          tft.drawString("Hunger +2%", 26, 4, 2);
          delay(1000);
          tft.fillRect(2, 2, 125, 18, TFT_BLACK);
        }
        else
        {
          tft.drawString("Can't eat that much", 4, 4, 2);
          delay(1000);
          tft.fillRect(2, 2, 125, 18, TFT_BLACK);
        }
      }
      //以上为点击确认键（0）时的反应 06
    }
    foodx1 = 22, foody1 = 22, foodx2 = 30, foody2 = 30;
    delay(300);
    tft.pushImage(0, 12, 128, 104, roomred);
    roomwhitex = 9;
    roomwhitey = 93;
    tft.drawCircle(roomwhitex, roomwhitey, 2, TFT_WHITE);
    delay(300);
  }
}

void Roomsleep()
{
  if(digitalRead(0) == 0)
  {
    delay(300);
    tft.fillScreen(TFT_BLACK);
    tft.drawString("5 minutes", 10, 15, 2);
    tft.drawString("20 minutes", 10, 40, 2);
    tft.drawString("1 hour", 10, 65, 2);
    tft.drawString("8 hours", 10, 90, 2);
    sleepx1 = 5, sleepy1 = 13, sleepx2 = 76, sleepy2 = 21;
    sleep_page = 0;
    tft.drawRect(sleepx1, sleepy1, sleepx2, sleepy2, TFT_WHITE);
    
    while(!(sleeptime == 150 || sleeptime == 600 || sleeptime == 1800 || sleeptime == 3))////////////把3改回14400
    {
      if(digitalRead(47) == 0 && sleepy1 == 13 && sleep_page == 0)
      {
        tft.drawRect(sleepx1, sleepy1, sleepx2, sleepy2, TFT_BLACK);
        sleepy1 += 25;
        tft.drawRect(sleepx1, sleepy1, sleepx2, sleepy2, TFT_WHITE);
        delay(300);
      }
  
      else if(digitalRead(47) == 0 && sleepy1 == 38 && sleep_page == 0)
      {
        tft.drawRect(sleepx1, sleepy1, sleepx2, sleepy2, TFT_BLACK);
        sleepy1 += 25;
        tft.drawRect(sleepx1, sleepy1, sleepx2, sleepy2, TFT_WHITE);
        delay(300);
      }
  
      else if(digitalRead(47) == 0 && sleepy1 == 63 && sleep_page == 0)
      {
        tft.drawRect(sleepx1, sleepy1, sleepx2, sleepy2, TFT_BLACK);
        sleepy1 += 25;
        tft.drawRect(sleepx1, sleepy1, sleepx2, sleepy2, TFT_WHITE);
        delay(300);
      }
  
      else if(digitalRead(47) == 0 && sleepy1 == 88 && sleep_page == 0)
      {
        tft.fillScreen(TFT_BLACK);
        tft.drawString("Exit", 10, 15, 2);
        tft.drawRect(sleepx1, sleepy1, sleepx2, sleepy2, TFT_BLACK);
        sleepy1 = 13;
        sleep_page += 1;
        tft.drawRect(sleepx1, sleepy1, sleepx2, sleepy2, TFT_WHITE);
        delay(300);
      }

      else if(digitalRead(47) == 0 && sleepy1 == 13 && sleep_page == 1)
      {
        tft.fillScreen(TFT_BLACK);
        tft.drawString("5 minutes", 10, 15, 2);
        tft.drawString("20 minutes", 10, 40, 2);
        tft.drawString("1 hour", 10, 65, 2);
        tft.drawString("8 hours", 10, 90, 2);
        sleepy1 = 13;
        tft.drawRect(sleepx1, sleepy1, sleepx2, sleepy2, TFT_WHITE);
        sleep_page -= 1;
        delay(300);
      }

      else if(digitalRead(0) == 0 && sleepy1 == 13 && sleep_page == 0)
      {
        frame1 = 0;
        tft.pushImage(0, 12, 128, 104, sleepgif[frame1]);
        delay(300);
        for(int i = 0; i < 6; ++i)
        {
          tft.pushImage(0, 12, 128, 104, sleepgif[frame1]);
          frame1++;
          delay(300);
        }
        for(int i = 0; i < 150; ++i)
        {
          tft.fillScreen(TFT_BLACK);
          delay(500);
          tft.drawString("Z", 60, 60, 4);
          delay(500);
          tft.drawString("z", 75, 45, 2);
          delay(500);
          tft.drawString("z", 83, 37, 2);
          delay(500);
          sleeptime += 1;
        }
        Fat_mas += 2;
      }

      else if(digitalRead(0) == 0 && sleepy1 == 38 && sleep_page == 0)
      {
        frame1 = 0;
        tft.pushImage(0, 12, 128, 104, sleepgif[frame1]);
        delay(300);
        for(int i = 0; i < 6; ++i)
        {
          tft.pushImage(0, 12, 128, 104, sleepgif[frame1]);
          frame1++;
          delay(300);
        }
        for(int i = 0; i < 600; ++i)
        {
          tft.fillScreen(TFT_BLACK);
          delay(500);
          tft.drawString("Z", 60, 60, 4);
          delay(500);
          tft.drawString("z", 75, 45, 2);
          delay(500);
          tft.drawString("z", 83, 37, 2);
          delay(500);
          sleeptime += 1;
        }
        Fat_mas += 10;
      }

      else if(digitalRead(0) == 0 && sleepy1 == 63 && sleep_page == 0)
      {
        frame1 = 0;
        tft.pushImage(0, 12, 128, 104, sleepgif[frame1]);
        delay(300);
        for(int i = 0; i < 6; ++i)
        {
          tft.pushImage(0, 12, 128, 104, sleepgif[frame1]);
          frame1++;
          delay(300);
        }
        for(int i = 0; i < 1800; ++i)
        {
          tft.fillScreen(TFT_BLACK);
          delay(500);
          tft.drawString("Z", 60, 60, 4);
          delay(500);
          tft.drawString("z", 75, 45, 2);
          delay(500);
          tft.drawString("z", 83, 37, 2);
          delay(500);
          sleeptime += 1;
        }
        Fat_mas += 20;
      }

      else if(digitalRead(0) == 0 && sleepy1 == 88 && sleep_page == 0)
      {
        frame1 = 0;
        tft.pushImage(0, 12, 128, 104, sleepgif[frame1]);
        delay(300);
        for(int i = 0; i < 6; ++i)
        {
          tft.pushImage(0, 12, 128, 104, sleepgif[frame1]);
          frame1++;
          delay(300);
        }
        for(int i = 0; i < 3; ++i)//////////////////////////////////这里改回14400
        {
          tft.fillScreen(TFT_BLACK);
          delay(500);
          tft.drawString("Z", 60, 60, 4);
          delay(500);
          tft.drawString("z", 75, 45, 2);
          delay(500);
          tft.drawString("z", 83, 37, 2);
          delay(500);
          sleeptime += 1;
        }
        Fat_mas += 50;
      }

      else if(digitalRead(0) == 0 && sleepy1 == 13 && sleep_page == 1)
      {
        sleeptime = 600;//假装睡觉，实则退出
        delay(300);
      }
    }
    sleeptime = 0;
    tft.pushImage(0, 12, 128, 104, roomgray);
    roomwhitex = 58;
    roomwhitey = 117;
    tft.drawCircle(roomwhitex, roomwhitey, 2, TFT_WHITE);
    delay(300);
  }
}

void Roomshower()
{
  if(digitalRead(0) == 0)
  {
    delay(300);
    if(Cle <= 90)
    {
      frame1 = 0;
      tft.pushImage(0, 12, 128, 104, cleangif[frame1]);
      delay(300);
      for(int i = 0; i < 15; ++i)
      {
        tft.pushImage(0, 12, 128, 104, cleangif[frame1]);
        frame1++;
        delay(200);
      }
      tft.pushImage(0, 12, 128, 104, cleangif[14]);
      delay(350);
      for(int i = 0; i < 3; ++i)
      {
        tft.fillScreen(TFT_BLACK);
        delay(500);
        tft.drawString(".", 50, 60, 2);
        delay(500);
        tft.drawString(".", 60, 60, 2);
        delay(500);
        tft.drawString(".", 70, 60, 2);
        delay(500);
      }
      Cle_mas += 50;
    }
    else
    {
      tft.fillScreen(TFT_BLACK);
      tft.drawString("No need to shower", 7, 50, 2);
      delay(1000);
    }
    tft.pushImage(0, 12, 128, 104, roomblue);
    roomwhitex = 107;
    roomwhitey = 27;
    tft.drawCircle(roomwhitex, roomwhitey, 2, TFT_WHITE);
    delay(300);
  }
}

void Shower()
{
  if(digitalRead(0) == 0)
  {
    tft.fillScreen(TFT_BLACK);
    delay(300);
    if(Cle <= 90)
    {
      for(int i = 0; i < 3; ++i)
      {
        tft.fillScreen(TFT_BLACK);
        delay(500);
        tft.drawString(".", 50, 60, 2);
        delay(500);
        tft.drawString(".", 60, 60, 2);
        delay(500);
        tft.drawString(".", 70, 60, 2);
        delay(500);
      }
      Cle_mas += 50;
    }
    else
    {
      tft.fillScreen(TFT_BLACK);
      tft.drawString("No need to shower", 7, 50, 2);
      delay(1000);
    }
    mainicon();
  }
}

void Shop()//图片尺寸为：x轴不超过126，y轴不超过98，出发点为1，1.即（1，1，126，98）
{
  if(digitalRead(0) == 0)
  {
    shopx1 = 101;
    shopy1 = 99;
    shopx2 = 26;
    shopy2 = 18;
    tft.fillScreen(TFT_BLACK);
    tft.drawRect(shopx1, shopy1, shopx2, shopy2, TFT_WHITE);
    tft.drawString("Exit", 103, 100, 2);
    delay(300);
    while(!(shopx1 == 101 && shopy1 == 99 && digitalRead(0) == 0))
    {
      if(shopx1 == 0 && shopy1 == 0 && shopx2 == 128 && shopy2 == 100 && digitalRead(47) == 0)
      {
        tft.drawRect(shopx1, shopy1, shopx2, shopy2, TFT_BLACK);
        shopx1 = 101;
        shopy1 = 99;
        shopx2 = 26;
        shopy2 = 18;
        tft.drawRect(shopx1, shopy1, shopx2, shopy2, TFT_WHITE);
        delay(200);
      }

      else if(shopx1 == 101 && shopy1 == 99 && shopx2 == 26 && shopy2 == 18 && digitalRead(47) == 0)
      {
        tft.drawRect(shopx1, shopy1, shopx2, shopy2, TFT_BLACK);
        shopx1 = 0;
        shopy1 = 0;
        shopx2 = 128;
        shopy2 = 100;
        tft.drawRect(shopx1, shopy1, shopx2, shopy2, TFT_WHITE);
        delay(200);
      }
      switch(picture)
      {
        case 0:
        {
          tft.pushImage(1, 1, 126, 83, colorgif[0]);
        }
        break;
    
        case 1:
        {
          tft.pushImage(1, 1, 126, 83, colorgif[1]);
        }
        break;
    
        case 2:
        {
          tft.pushImage(1, 1, 126, 83, colorgif[2]);
        }
        break;

        case 3:
        {
          tft.pushImage(1, 1, 126, 83, colorgif[3]);
        }
        break;

        case 4:
        {
          tft.pushImage(1, 1, 126, 83, colorgif[4]);
        }
        break;

        case 5:
        {
          tft.pushImage(1, 1, 126, 83, colorgif[5]);
        }
        break;
      }

      //以下为确认购买图片
      if(shopx1 == 0 && shopy1 == 0 && shopx2 == 128 && shopy2 == 100 && digitalRead(0) == 0)
      {
        if(Exp >= 10 && picture_group[pic] == 0)
        {
          tft.fillScreen(TFT_BLACK);
          tft.drawString("Buy this picture", 15, 20, 2);
          tft.drawString("with", 55, 40, 2);
          tft.drawString("10 coins?", 32, 60, 2);
          tft.drawString("Yes", 25, 87, 2);
          tft.drawString("No", 93, 87, 2);
          shopx1 = 22;
          shopy1 = 86;
          shopx2 = 27;
          shopy2 = 18;
          tft.drawRect(shopx1, shopy1, shopx2, shopy2, TFT_WHITE);
          delay(300);
          while(buy_j != 1)
          {
            if(shopx1 == 22 && shopy1 == 86 && digitalRead(47) == 0)
            {
              tft.drawRect(shopx1, shopy1, shopx2, shopy2, TFT_BLACK);
              shopx1 = 90;
              shopy1 = 86;
              tft.drawRect(shopx1, shopy1, shopx2, shopy2, TFT_WHITE);
              delay(300);
            }
    
            else if(shopx1 == 90 && shopy1 == 86 && digitalRead(47) == 0)
            {
              tft.drawRect(shopx1, shopy1, shopx2, shopy2, TFT_BLACK);
              shopx1 = 22;
              shopy1 = 86;
              tft.drawRect(shopx1, shopy1, shopx2, shopy2, TFT_WHITE);
              delay(300);
            }
  
            else if(shopx1 == 22 && shopy1 == 86 && digitalRead(0) == 0)//确认购买Yes
            {
              tft.fillScreen(TFT_BLACK);
              tft.drawString("Success", 40, 50, 2);
              Exp_mas += 100;
              buy_j += 1;
              picture_group[pic] += 1;
              delay(1000);
            }
  
            else if(shopx1 == 90 && shopy1 == 86 && digitalRead(0) == 0)//放弃购买No
            {
              tft.fillScreen(TFT_BLACK);
              buy_j += 1;
            }
          }
          buy_j = 0;
          delay(300);
          shopx1 = 101;
          shopy1 = 99;
          shopx2 = 26;
          shopy2 = 18;
          tft.drawRect(shopx1, shopy1, shopx2, shopy2, TFT_WHITE);
          tft.drawString("Exit", 103, 100, 2);
        }

        else if(picture_group[pic] >= 1)
        {
          tft.fillScreen(TFT_BLACK);
          tft.drawString("You have bought", 11, 40, 2);
          tft.drawString("this picture", 28, 60, 2);
          delay(1000);
          shopx1 = 101;
          shopy1 = 99;
          shopx2 = 26;
          shopy2 = 18;
          tft.drawRect(shopx1, shopy1, shopx2, shopy2, TFT_WHITE);
          tft.drawString("Exit", 103, 100, 2);
        }

        else if(Exp < 10)
        {
          tft.fillScreen(TFT_BLACK);
          tft.drawString("Not enough coins", 10, 50, 2);
          delay(1000);
          shopx1 = 101;
          shopy1 = 99;
          shopx2 = 26;
          shopy2 = 18;
          tft.drawRect(shopx1, shopy1, shopx2, shopy2, TFT_WHITE);
          tft.drawString("Exit", 103, 100, 2);
        }
      }
    }
    mainicon();
    delay(300);
  }
}

void Box()
{
  int i = 0;
  if(digitalRead(0) == 0)
  {
    tft.fillScreen(TFT_BLACK);
    tft.drawString("Welcome To The", 17, 40, 2);
    tft.drawString("Collection Box", 22, 60, 2);
    tft.drawString("Exit", 100, 100, 2);
    //tft.drawRect(boxx1, boxy1, boxx2, boxy2, TFT_WHITE);
    delay(300);
    while(digitalRead(0) != 0)
    {
      if(digitalRead(47) == 0)
      {
        if(picture_group[i] == 1)
        {
          tft.pushImage(1, 1, 126, 83, colorgif[i]);
          tft.drawString(String(i + 1), 10, 100, 2);
        }
        else if(picture_group[i] != 1)
        {
          tft.fillScreen(TFT_BLACK);
          tft.drawString("Did not buy", 28, 40, 2);
          tft.drawString("this picture", 28, 60, 2);
          tft.drawString(String(i + 1), 10, 100, 2);
          tft.drawString("Exit", 100, 100, 2);
          //tft.drawRect(boxx1, boxy1, boxx2, boxy2, TFT_WHITE);
        }
        ++i;
        delay(300);
      }
    }
    i = 0;
    mainicon();
    delay(300);
  }
}

void peace()
{
  if(Hun < 0 || Fat < 0 || Cle < 0)
  {
    tft.fillScreen(TFT_BLACK);
    tft.drawString("GameOver", 3, 30, 4);
    delay(800);
    tft.drawString("Experience", 33, 65, 2);
    delay(800);
    tft.drawString(String(Exp), 33, 85, 2);
    while(1);
  }
}

void Rooms()
{
  if(digitalRead(0) == 0)
  {
    delay(300);
    tft.fillScreen(TFT_BLACK);
    roomwhitex = 83, roomwhitey = 16;
    tft.pushImage(0, 12, 128, 104, roomwhite);
    tft.drawCircle(roomwhitex, roomwhitey, 2, TFT_WHITE);//上左
    while(!(roomwhitex == 95 && roomwhitey == 105 && digitalRead(0) == 0))
    {
      if(digitalRead(47) == 0 && roomwhitex == 83)
      {
        tft.drawCircle(roomwhitex, roomwhitey, 2, TFT_BLACK);
        roomwhitex =107 , roomwhitey = 28;
        tft.drawCircle(roomwhitex, roomwhitey, 2, TFT_WHITE);
        delay(300);
      }
      else if(digitalRead(47) == 0 && roomwhitex == 107)
      {
        tft.drawCircle(roomwhitex, roomwhitey, 2, TFT_BLACK);
        roomwhitex =95 , roomwhitey = 105;
        tft.drawCircle(roomwhitex, roomwhitey, 2, TFT_WHITE);
        delay(300);
      }
      else if(digitalRead(47) == 0 && roomwhitex == 95)
      {
        tft.drawCircle(roomwhitex, roomwhitey, 2, TFT_BLACK);
        roomwhitex =45 , roomwhitey = 110;
        tft.drawCircle(roomwhitex, roomwhitey, 2, TFT_WHITE);
        delay(300);
      }
      else if(digitalRead(47) == 0 && roomwhitex == 45)
      {
        tft.drawCircle(roomwhitex, roomwhitey, 2, TFT_BLACK);
        roomwhitex =21 , roomwhitey = 98;
        tft.drawCircle(roomwhitex, roomwhitey, 2, TFT_WHITE);
        delay(300);
      }
      else if(digitalRead(47) == 0 && roomwhitex == 21)
      {
        tft.drawCircle(roomwhitex, roomwhitey, 2, TFT_BLACK);
        roomwhitex =83 , roomwhitey = 16;
        tft.drawCircle(roomwhitex, roomwhitey, 2, TFT_WHITE);
        delay(300);
      }
  //    tft.drawCircle(107, 28, 2, TFT_WHITE);//上右
  //    tft.drawCircle(21, 99, 2, TFT_WHITE);//下左
  //    tft.drawCircle(45, 111, 2, TFT_WHITE);//下中
  //    tft.drawCircle(95, 105, 2, TFT_WHITE);//下右
      //以下为按下确认（0）时的反应
      else if(digitalRead(0) == 0 && roomwhitex == 83)
      {
        tft.pushImage(0, 12, 128, 104, roomgray);
        //tft.drawCircle(45, 16, 2, TFT_WHITE);
        roomwhitex = 58;
        roomwhitey = 117;
        tft.drawCircle(roomwhitex, roomwhitey, 2, TFT_WHITE);
        delay(300);
        while(!(digitalRead(0) == 0 && roomwhitex == 58 && roomwhitey == 117))
        {
          tft.drawCircle(roomwhitex, roomwhitey, 2, TFT_WHITE);
          if(digitalRead(47) == 0 && roomwhitex == 58 && roomwhitey == 117)
          {
            tft.drawCircle(roomwhitex, roomwhitey, 2, TFT_BLACK);
            roomwhitex = 45;
            roomwhitey = 16;
            tft.drawCircle(roomwhitex, roomwhitey, 2, TFT_WHITE);
            delay(300);
          }
          else if(digitalRead(47) == 0 && roomwhitex == 45 && roomwhitey == 16)
          {
            tft.drawCircle(roomwhitex, roomwhitey, 2, TFT_BLACK);
            roomwhitex = 100;
            roomwhitey = 102;
            tft.drawCircle(roomwhitex, roomwhitey, 2, TFT_WHITE);
            delay(300);
          }
          else if(digitalRead(47) == 0 && roomwhitex == 100 && roomwhitey == 102)
          {
            tft.drawCircle(roomwhitex, roomwhitey, 2, TFT_BLACK);
            roomwhitex = 58;
            roomwhitey = 117;
            tft.drawCircle(roomwhitex, roomwhitey, 2, TFT_WHITE);
            delay(300);
          }
          else if(digitalRead(0) == 0 && roomwhitex == 100 && roomwhitey == 102)
          {
            Roomsleep();
          }
          
          else if(digitalRead(0) == 0 && roomwhitex == 45 && roomwhitey == 16)//////////////////这里（游戏）
          {
            frame1 = 0;
            tft.pushImage(0, 12, 128, 104, gamegif[frame1]);
            delay(300);
            for(int i = 0; i < 7; ++i)
            {
              tft.pushImage(0, 12, 128, 104, gamegif[frame1]);
              frame1 += 1;
              delay(200);
            }
            
            //以下开始写电脑游戏
              tft.fillScreen(TFT_BLACK);
              tft.drawString("Sic bo", 10, 25, 2);
              //tft.drawString("WiFi scan", 10, 50, 2);//这个功能太占地方还发热，暂时不用
              tft.drawString("Exit", 10, 75, 2);
              gamex1 = 5, gamey1 = 23, gamex2 = 76, gamey2 = 21;
              tft.drawRect(gamex1, gamey1, gamex2, gamey2, TFT_WHITE);

              while(!(gamey1 == 73 && digitalRead(0) == 0))
              {
                tft.drawRect(gamex1, gamey1, gamex2, gamey2, TFT_WHITE);
                if(gamey1 == 23 && digitalRead(47) == 0)
                {
                  tft.drawRect(gamex1, gamey1, gamex2, gamey2, TFT_BLACK);
                  gamey1 = 73;
                  tft.drawRect(gamex1, gamey1, gamex2, gamey2, TFT_WHITE);
                  delay(300);
                }
            
//                else if(gamey1 == 48 && digitalRead(47) == 0)
//                {
//                  tft.drawRect(gamex1, gamey1, gamex2, gamey2, TFT_BLACK);
//                  gamey1 += 25;
//                  tft.drawRect(gamex1, gamey1, gamex2, gamey2, TFT_WHITE);
//                  delay(300);
//                }
            
                else if(gamey1 == 73 && digitalRead(47) == 0)
                {
                  tft.drawRect(gamex1, gamey1, gamex2, gamey2, TFT_BLACK);
                  gamey1 = 23;
                  tft.drawRect(gamex1, gamey1, gamex2, gamey2, TFT_WHITE);
                  delay(300);
                }

                //以下为确认游戏
                else if(gamey1 == 23 && digitalRead(0) == 0)//第一个游戏sic_bo
                {
                  tft.fillScreen(TFT_BLACK);
                  tft.drawString("Sic bo", 30, 30, 4);
                  int gamex = 9;
                  delay(1500);
                  while(!(gamex == 83 && digitalRead(0) == 0))
                  {
                    tft.fillScreen(TFT_BLACK); 
                    gamenum_left = random(1, 7);
                    tft.drawString(String(gamenum_left), 33, 30, 4);
                    delay(400);
                    gamenum_left = random(1, 7);
                    tft.drawString(String(gamenum_left), 33, 30, 4);
                    delay(400);
                    gamenum_left = random(1, 7);
                    tft.drawString(String(gamenum_left), 33, 30, 4);
                    delay(400);
                    tft.drawString("?", 33, 30, 4);//左面数字结束
                    delay(700);
      
                    gamenum_right = random(1, 7);
                    tft.drawString(String(gamenum_right), 83, 30, 4);
                    delay(400);
                    gamenum_right = random(1, 7);
                    tft.drawString(String(gamenum_right), 83, 30, 4);
                    delay(400);
                    gamenum_right = random(1, 7);
                    tft.drawString(String(gamenum_right), 83, 30, 4);
                    delay(400);
                    tft.drawString("?", 83, 30, 4);//右面数字结束
                    delay(400);
      
                    gamenum_left = random(1, 7);
                    gamenum_right = random(1, 7);
      
                    while(digitalRead(0) != 0)
                    {
                      tft.drawString("Big", 18, 90, 2);
                      tft.drawString("Small", 50, 90, 2);
                      tft.drawString("Exit", 90, 90, 2);
                      tft.drawRect(gamex, 89, 37, 20, TFT_WHITE);
                      if(gamex == 9 && digitalRead(47) == 0)
                      {
                        tft.drawRect(gamex, 89, 37, 20, TFT_BLACK);
                        gamex += 37;
                        tft.drawRect(gamex, 89, 37, 20, TFT_WHITE);
                        delay(300);
                      }
        
                      else if(gamex == 46 && digitalRead(47) == 0)
                      {
                        tft.drawRect(gamex, 89, 37, 20, TFT_BLACK);
                        gamex += 37;
                        tft.drawRect(gamex, 89, 37, 20, TFT_WHITE);
                        delay(300);
                      }
      
                      else if(gamex == 83 && digitalRead(47) == 0)
                      {
                        tft.drawRect(gamex, 89, 37, 20, TFT_BLACK);
                        gamex = 9;
                        tft.drawRect(gamex, 89, 37, 20, TFT_WHITE);
                        delay(300);
                      }
                    }
      
                    if(gamex == 9 && digitalRead(0) == 0)
                    {
                      tft.drawString(String(gamenum_left), 33, 30, 4);
                      tft.drawString(String(gamenum_right), 83, 30, 4);
                      delay(1200);
                      if(gamenum_left + gamenum_right >= 7)
                      {
                        tft.fillScreen(TFT_BLACK);
                        tft.drawString("Win", 40, 30, 4);
                        Exp_mas -= 20;
                        delay(500);
                        tft.drawString("Mikuru coins +2", 20, 70, 2);
                        delay(1000);
                        tft.fillScreen(TFT_BLACK);
                      }
                      else
                      {
                        tft.fillScreen(TFT_BLACK);
                        tft.drawString("Lose", 35, 30, 4);
                        Exp_mas += 20;
                        delay(500);
                        tft.drawString("Mikuru coins -2", 20, 70, 2);
                        delay(1000);
                        tft.fillScreen(TFT_BLACK);
                      }
                    }
      
                    else if(gamex == 46 && digitalRead(0) == 0)
                    {
                      tft.drawString(String(gamenum_left), 33, 30, 4);
                      tft.drawString(String(gamenum_right), 83, 30, 4);
                      delay(1200);
                      if(gamenum_left + gamenum_right <= 6)
                      {
                        tft.fillScreen(TFT_BLACK);
                        tft.drawString("Win", 40, 30, 4);
                        Exp_mas -= 20;
                        delay(500);
                        tft.drawString("Mikuru coins +2", 20, 70, 2);
                        delay(1000);
                        tft.fillScreen(TFT_BLACK);
                      }
                      else
                      {
                        tft.fillScreen(TFT_BLACK);
                        tft.drawString("Lose", 35, 30, 4);
                        Exp_mas += 20;
                        delay(500);
                        tft.drawString("Mikuru coins -2", 20, 70, 2);
                        delay(1000);
                        tft.fillScreen(TFT_BLACK);
                      }
                    }
                  }
                  delay(300);
                  tft.fillScreen(TFT_BLACK);
                  tft.drawString("Sic bo", 10, 25, 2);
                  //tft.drawString("WiFi scan", 10, 50, 2);
                  tft.drawString("Exit", 10, 75, 2);
                }

//                else if(gamey1 == 48 && digitalRead(0) == 0)//第二个游戏wifi_scan
//                {
//                  delay(300);
//                  int wifitime = 0;
//                  while(!(digitalRead(0) == 0 || digitalRead(47) == 0))//这个括号可以删掉
//                  {
//                    if(wifitime == 0)//让wifi_scan只执行一次
//                    {
//                      wifi_scan();
//                      ++wifitime;
//                    }
//                  }
//                  delay(300);
//                  tft.fillScreen(TFT_BLACK);
//                  tft.drawString("Sic bo", 10, 25, 2);
//                  tft.drawString("WiFi scan", 10, 50, 2);
//                  tft.drawString("Exit", 10, 75, 2);
//                }
              }
            tft.pushImage(0, 12, 128, 104, roomgray);
            delay(300);
          }
        }
        tft.drawCircle(roomwhitex, roomwhitey, 2, TFT_BLACK);
        tft.pushImage(0, 12, 128, 104, roomwhite);
        roomwhitex = 83;
        roomwhitey = 16;
        tft.drawCircle(roomwhitex, roomwhitey, 2, TFT_WHITE);
        delay(300);
      }
      else if(digitalRead(0) == 0 && roomwhitex == 107)
      {

//          roomwhitex = 96;
//          roomwhitey = 23;
//          roomwhitex = 9;
//          roomwhitey = 93;
        tft.pushImage(0, 12, 128, 104, roomred);
        roomwhitex = 9;
        roomwhitey = 93;
        tft.drawCircle(roomwhitex, roomwhitey, 2, TFT_WHITE);
        delay(300);
        while(!(digitalRead(0) == 0 && roomwhitex == 9 && roomwhitey == 93))
        {
          if(digitalRead(47) == 0 && roomwhitex == 9 && roomwhitey == 93)
          {
            tft.drawCircle(roomwhitex, roomwhitey, 2, TFT_BLACK);
            roomwhitex = 96;
            roomwhitey = 23;
            tft.drawCircle(roomwhitex, roomwhitey, 2, TFT_WHITE);
            delay(300);
          }
          else if(digitalRead(47) == 0 && roomwhitex == 96 && roomwhitey == 23)
          {
            tft.drawCircle(roomwhitex, roomwhitey, 2, TFT_BLACK);
            roomwhitex = 9;
            roomwhitey = 93;
            tft.drawCircle(roomwhitex, roomwhitey, 2, TFT_WHITE);
            delay(300);
          }
          else if(digitalRead(0) == 0 && roomwhitex == 96 && roomwhitey == 23)
          {
            Roomfood();
          }
        }
        tft.drawCircle(roomwhitex, roomwhitey, 2, TFT_BLACK);
        tft.pushImage(0, 12, 128, 104, roomwhite);
        roomwhitex = 107;
        roomwhitey = 28;
        tft.drawCircle(roomwhitex, roomwhitey, 2, TFT_WHITE);
        delay(300);     
      }

      else if(digitalRead(0) == 0 && roomwhitex == 45)
      {
//          roomwhitex = 119;
//          roomwhitey = 34;
//          roomwhitex = 49;
//          roomwhitey = 114;
        tft.pushImage(0, 12, 128, 104, roomgreen);
        roomwhitex = 119;
        roomwhitey = 34;
        tft.drawCircle(roomwhitex, roomwhitey, 2, TFT_WHITE);
        delay(300);
        while(!(digitalRead(0) == 0 && roomwhitex == 119 && roomwhitey == 34))
        {
          if(digitalRead(47) == 0 && roomwhitex == 119 && roomwhitey == 34)
          {
            tft.drawCircle(roomwhitex, roomwhitey, 2, TFT_BLACK);
            roomwhitex = 49;
            roomwhitey = 114;
            tft.drawCircle(roomwhitex, roomwhitey, 2, TFT_WHITE);
            delay(300);
          }
          else if(digitalRead(47) == 0 && roomwhitex == 49 && roomwhitey == 114)
          {
            tft.drawCircle(roomwhitex, roomwhitey, 2, TFT_BLACK);
            roomwhitex = 119;
            roomwhitey = 34;
            tft.drawCircle(roomwhitex, roomwhitey, 2, TFT_WHITE);
            delay(300);
          }
          else if(digitalRead(0) == 0 && roomwhitex == 49 && roomwhitey == 114)
          {
            delay(300);
//            frame1 = 0;
//            for(int i = 0; i < 19; ++i)
//            {
//              tft.pushImage(0, 12, 128, 104, gardengif[frame1]);
//              frame1++;
//              delay(100);
//            }
            while(digitalRead(0) != 0)
            {
              tft.drawCircle(roomwhitex, roomwhitey, 2, TFT_BLACK);
              tft.pushImage(0, 12, 128, 104, roomblack);
            }
            tft.pushImage(0, 12, 128, 104, roomgreen);
            roomwhitex = 49;
            roomwhitey = 114;
            tft.drawCircle(roomwhitex, roomwhitey, 2, TFT_WHITE);
            delay(300);
          }
        }
        tft.drawCircle(roomwhitex, roomwhitey, 2, TFT_BLACK);
        tft.pushImage(0, 12, 128, 104, roomwhite);
        roomwhitex = 45;
        roomwhitey = 111;
        tft.drawCircle(roomwhitex, roomwhitey, 2, TFT_WHITE);
        delay(300);
      }
      
      else if(digitalRead(0) == 0 && roomwhitex == 21)
      {
//          roomwhitex = 20;
//          roomwhitey = 27;
//          roomwhitex = 107;
//          roomwhitey = 27;
        tft.pushImage(0, 12, 128, 104, roomblue);
        roomwhitex = 107;
        roomwhitey = 27;
        tft.drawCircle(roomwhitex, roomwhitey, 2, TFT_WHITE);
        delay(300);
        while(!(digitalRead(0) == 0 && roomwhitex == 107 && roomwhitey == 27))
        {
          if(digitalRead(47) == 0 && roomwhitex == 107 && roomwhitey == 27)
          {
            tft.drawCircle(roomwhitex, roomwhitey, 2, TFT_BLACK);
            roomwhitex = 20;
            roomwhitey = 27;
            tft.drawCircle(roomwhitex, roomwhitey, 2, TFT_WHITE);
            delay(300);
          }
          else if(digitalRead(47) == 0 && roomwhitex == 20 && roomwhitey == 27)
          {
            tft.drawCircle(roomwhitex, roomwhitey, 2, TFT_BLACK);
            roomwhitex = 107;
            roomwhitey = 27;
            tft.drawCircle(roomwhitex, roomwhitey, 2, TFT_WHITE);
            delay(300);
          }
          else if(digitalRead(0) == 0 && roomwhitex == 20 && roomwhitey == 27)
          {
            Roomshower();
          }
        }
        tft.drawCircle(roomwhitex, roomwhitey, 2, TFT_BLACK);
        tft.pushImage(0, 12, 128, 104, roomwhite);
        roomwhitex = 21;
        roomwhitey = 99;
        tft.drawCircle(roomwhitex, roomwhitey, 2, TFT_WHITE);
        delay(300);  
      }
    }
    mainicon();
    delay(300);
  }
}

void Time()
{
  if(digitalRead(0) == 0)
  {
    delay(300);
    tft.fillScreen(TFT_BLACK);
    //tft.drawString("Mikuru Tamagotchi", 13, 10);
    tft.drawString("Mode", 10, 25, 2);
    tft.drawString("Brightness", 10, 50, 2);
    tft.drawString("Exit", 10, 75, 2);
    timex1 = 5, timey1 = 23, timex2 = 76, timey2 = 21;
    tft.drawRect(timex1, timey1, timex2, timey2, TFT_WHITE);

    while(!(timey1 == 73 && digitalRead(0) == 0))
    {
      tft.drawRect(timex1, timey1, timex2, timey2, TFT_WHITE);
      if(timey1 == 23 && digitalRead(47) == 0)
      {
        tft.drawRect(timex1, timey1, timex2, timey2, TFT_BLACK);
        timey1 += 25;
        tft.drawRect(timex1, timey1, timex2, timey2, TFT_WHITE);
        delay(300);
      }
  
      else if(timey1 == 48 && digitalRead(47) == 0)
      {
        tft.drawRect(timex1, timey1, timex2, timey2, TFT_BLACK);
        timey1 += 25;
        tft.drawRect(timex1, timey1, timex2, timey2, TFT_WHITE);
        delay(300);
      }
  
      else if(timey1 == 73 && digitalRead(47) == 0)
      {
        tft.drawRect(timex1, timey1, timex2, timey2, TFT_BLACK);
        timey1 = 23;
        tft.drawRect(timex1, timey1, timex2, timey2, TFT_WHITE);
        delay(300);
      }
  
      else if(timey1 == 23 && digitalRead(0) == 0)//选择模式子菜单
      {
        delay(300);
        tft.fillScreen(TFT_BLACK);
        tft.drawString("Light", 10, 25, 2);
        tft.drawString("Dark", 10, 50, 2);
        while(digitalRead(0) != 0)
        {
          tft.drawRect(modex1, modey1, modex2, modey2, TFT_WHITE);
          if(digitalRead(47) == 0 && modey1 == 23)
          {
            tft.drawRect(modex1, modey1, modex2, modey2, TFT_BLACK);
            modey1 += 25;
            tft.drawRect(modex1, modey1, modex2, modey2, TFT_WHITE);
            delay(300);
          }
  
          else if(digitalRead(47) == 0 && modey1 == 48)
          {
            tft.drawRect(modex1, modey1, modex2, modey2, TFT_BLACK);
            modey1 = 23;
            tft.drawRect(modex1, modey1, modex2, modey2, TFT_WHITE);
            delay(300);
          }
  
          else if(digitalRead(0) == 0 && modey1 == 23)
          {
            darkmode = 0;
          }
  
          else if(digitalRead(0) == 0 && modey1 == 48)
          {
            darkmode = 1;
          }
        }
        delay(300);
        tft.fillScreen(TFT_BLACK);
        tft.drawString("Mode", 10, 25, 2);
        tft.drawString("Brightness", 10, 50, 2);
        tft.drawString("Exit", 10, 75, 2);
      }
  
      else if(timey1 == 48 && digitalRead(0) == 0)//选择亮度子菜单
      {
        delay(300);
        tft.fillScreen(TFT_BLACK);
        while(digitalRead(0) != 0)
        {
          tft.drawString("Mikuru Tamagotchi", 13, 10);
          tft.drawString(String(b), 35, 40, 4);
          if(digitalRead(47) == 0)
          {
            b += 1;
            if(b == 6)
            {
              b = 0;
            }
            ledcWrite(pwmLedChannelTFT, bright[b]);
            tft.drawString(String(b), 35, 40, 4);
            delay(300);
          }
        }
        delay(300);
        tft.fillScreen(TFT_BLACK);
        tft.drawString("Mode", 10, 25, 2);
        tft.drawString("Brightness", 10, 50, 2);
        tft.drawString("Exit", 10, 75, 2);
      }
    }
    delay(300);
    mainicon();
  }
}

void mainselect()
{
  tft.drawRect(mainx1, mainy1, mainx2, mainy2, TFT_WHITE); 
  buttonstate47 = digitalRead(47);
  if(buttonstate47 == LOW && buttonbefore47 == HIGH)
  {
    tft.drawRect(mainx1, mainy1, mainx2, mainy2, TFT_BLACK); 
    mainx1 += n_main;
    mainnum += 1;
    if(mainx1 == 129 && mainy1 == 0)
    {
      mainx1 = 1; //mainx1有1，33，65，97四种。
      mainy1 = 98;
    }

    else if(mainx1 == 129 && mainy1 == 98)
    {
      mainx1 = 1;
      mainy1 = 0;
      mainnum = 0;
    }
  }
  buttonbefore47 = buttonstate47;
  tft.drawRect(mainx1, mainy1, mainx2, mainy2, TFT_WHITE);

  switch(mainnum)
  {
    case 0: 
    {
      Generalmenu(); 
    }
    break;

    case 1:
    {
      Food();
    }
    break;

    case 2:
    {
      Sleep();
    }
    break;

    case 3:
    {
      Shower();
    }
    break;

    case 4:
    {
      Shop();
    }
    break;

    case 5:
    {
      Rooms();
    }
    break;

    case 6:
    {
      Box();
    }
    break;

    case 7:
    {
      Time();
    }
    break;
  }
}


void setup() 
{
  pinMode(0, INPUT_PULLUP);
  pinMode(47, INPUT_PULLUP);
  tft.begin();
  tft.setRotation(3);
  tft.fillScreen(TFT_BLACK);
  tft.setSwapBytes(true);

  //tft.drawRect(0, 0, 128, 128, TFT_WHITE); 

  mainicon();

  for(int i = 0; i < 100; ++i)
  {
    picture_group[i] = 0;
  }

  ledcSetup(pwmLedChannelTFT, pwmFreq, pwmResolution);
  ledcAttachPin(10, pwmLedChannelTFT);
  ledcWrite(pwmLedChannelTFT, bright[b]);
}


void loop()
{  
  if(millis() >= picture_s)
  {
    pic += 1;
    picture += 1;
    picture_s += 120000;//每（）毫秒刷新一次商店图片
  }
      
  mainselect();

  if(Hun < 60 || Fat < 60 || Cle < 60)
  {
    tft.pushImage(2, 1, 28, 28, warn);
  }
  else
  {
    tft.pushImage(2, 1, 28, 28, pest);
  }

  state_count();
  
  maingif();

  peace();
  
}
