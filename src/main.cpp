
#include <Arduino.h>
#include <NeoPixelBus.h>
//#include <NeoPixelBusLg.h>
#include "math.h"

const uint8_t DATA_PIN = 4;

const uint8_t PANEL_WIDTH = 8;
const uint8_t PANEL_HEIGHT = 8;
constexpr uint8_t NUM_LEDS = PANEL_WIDTH * PANEL_HEIGHT;

//const uint8_t SPRITE_LENGTH = 3;

const RgbColor blackColor = RgbColor(0, 0, 0);

//NeoPixelBusLg<NeoGrbFeature, NeoWs2812xMethod> strip(NUM_LEDS, DATA_PIN);
NeoTopology<ColumnMajor180Layout> layout(PANEL_WIDTH,PANEL_HEIGHT);
NeoPixelBus<NeoGrbFeature, NeoWs2812xMethod> panel(NUM_LEDS, DATA_PIN);

uint8_t pixelX = 0;
uint8_t pixelY = 0;

void setup()
{
    // Serial.begin(9600);
    // this resets all the neopixels to an off state

    //strip.SetLuminance(255);

    panel.Begin();
   
    // pre-init colors
    // for(uint8_t i = 0; i < SPRITE_LENGTH; i++) {

    //     // uint8_t r = random(1, 10);
    //     // uint8_t g = random(1, 10);
    //     // uint8_t b = random(1, 10);
    //     //RgbwColor color = RgbwColor(r, g, b, 0);
    //     //RgbColor color = RgbColor(0, i*20+1, 0);
    //     RgbColor color = RgbColor(0,  0, 1); 
    //     strip.SetPixelColor(i, color);
    // }

    // for (uint8_t i = 0; i < NUM_LEDS; i++)
    // {
    //     if (i % 5 == 0)
    //     {
    //         uint8_t r = random(1, 10);
    //         uint8_t g = random(1, 10);
    //         uint8_t b = random(1, 10);

    //         RgbwColor color = RgbwColor(r, g, b, 0);
    //         strip.SetPixelColor(i, color);
    //     }
    //     else
    //     {
    //         strip.SetPixelColor(i, blackColor);
    //     }
    // }
    panel.Show();
}

void scanXY(uint8_t& outX, uint8_t &outY) {

    static uint8_t x = 0;
    static uint8_t y = 0;

    x++; y++;
    if(x >= PANEL_WIDTH) {
        x = 0;
        //y++;
    }

    if(y >= PANEL_HEIGHT) {
        //x = 0;
        y = 0;
    }

    outX = x;
    outY = y;
}

void drawRandomDot() {

    uint8_t x = random(0,PANEL_WIDTH);
    uint8_t y = random(0,PANEL_HEIGHT);

    float hue = randomBoundFloat(0.45f, 0.8f);
    float saturation = 1.0f;
    float brightness = randomBoundFloat(0.05f, 0.25f);

    HsbColor hsbColor = HsbColor(hue, saturation, brightness);
    panel.SetPixelColor(layout.Map(x, y), hsbColor);
}

void drawFullCross(const int& x, const int& y, const HsbColor& color) {

    for(int i = 0; i < NUM_LEDS; i++) {
        panel.SetPixelColor(i, blackColor);
    }
    
    for(int i = 0; i < PANEL_WIDTH; i++) {
        panel.SetPixelColor(layout.Map(i, y), color);
    }

    for(int i = 0; i < PANEL_HEIGHT; i++) {
         panel.SetPixelColor(layout.Map(x, i), color);
    }
}

void loop()
{
    // uint8_t x = random(0,PANEL_WIDTH);
    // uint8_t y = random(0,PANEL_HEIGHT);
    uint8_t x,y = {0};
    scanXY(x,y);

    //float hue = randomBoundFloat(0.05f, 0.95f);
    float hue = 0.4f;
    //float saturation = 1.0f;
    float saturation = randomBoundFloat(0.5f, 1.0f);
    
    //float brightness = randomBoundFloat(0.01f, 0.15f);
    float brightness = 0.01f;

    HsbColor hsbColor = HsbColor(hue, saturation, brightness);

    drawFullCross(x,y, hsbColor);

    panel.Show();
    delay(100);

    //panel.Begin(); // clear
}

// --------------------- Junk ----------------------

     // uint8_t r = random(1, 20);
    // uint8_t g = random(1, 20);
    // uint8_t b = random(1, 20);
    // RgbColor color = RgbColor(r, g, b);

    // panel.SetPixelColor(layout.Map(pixelX, pixelY), color);

    // for (uint8_t i = 0; i < NUM_LEDS; i++)
    // {
    //     uint8_t r = random(1, 5);
    //     uint8_t g = random(1, 5);
    //     uint8_t b = random(1, 5);

    //     RgbwColor color = RgbwColor(r, g, b, 0);
    //     strip.SetPixelColor(i, color);


    //     // if (i % 2 == 0)
    //     // {
    //     //     uint8_t r = random(1, 10);
    //     //     uint8_t g = random(1, 10);
    //     //     uint8_t b = random(1, 10);

    //     //     RgbwColor color = RgbwColor(r, g, b, 0);
    //     //     strip.SetPixelColor(i, color);
    //     // }
    //     // else
    //     // {
    //     //     strip.SetPixelColor(i, blackColor);
    //     // }

    //     strip.Show();
    // }
    
   

    // pixelX++;
    // if(pixelX >= PANEL_WIDTH) {
    //     pixelX = 0;
    //     pixelY++;
    // }

    // if(pixelY >= PANEL_HEIGHT) {
    //     pixelX = 0;
    //     pixelY = 0;
    //     panel.Begin();
    // }

    //strip.RotateRight(1);
    
    // if(spritePosition < limit && direction == 0) {           
    //      spritePosition++;
    // } 

    // Serial.println("Hello world!");

