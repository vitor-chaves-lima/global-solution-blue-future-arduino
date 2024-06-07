#include <Adafruit_NeoPixel.h>
#include <LiquidCrystal.h>
#include <stdlib.h>
#include <math.h>

#define PIN 8
#define NUMPIXELS 10

typedef struct Product{
  bool isRecycled;
  int token;
};

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2);

Product products[NUMPIXELS];
int productedCount = 0;
int recycledCount = 0;
float irc;

void setup()
{
  pixels.begin();
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop()
{
  if (Serial.available()){
  	String prompt = Serial.readString();
    int promptValue = atoi(prompt.c_str());
    if (productedCount < NUMPIXELS){
      processMessage(promptValue);
    }
    else {
  	  lcd.clear();
      lcdWrap("Limite", "atingido!");
      delay(2000);
    }
  }
  displayProductCount(productedCount, recycledCount);
}

void processMessage(int token){
  if (productedCount > 0){
    
    int existingProductIndex = -1;
  	for (int i = 0; i < productedCount; i++){
      if (products[i].token == token){
      	existingProductIndex = i;
        break;
      }
 	}
    if (existingProductIndex != -1){
      Product tmp = products[existingProductIndex];
      if (tmp.isRecycled == true){
        lcdWrap("Produto ja", "reciclado");
        delay(2000);
        lcd.clear();
      }
      else {
      	tmp.isRecycled = true;
        products[existingProductIndex] = tmp;
        
        lcdWrap("Produdo foi", "reciclado!");
        recycledCount ++;
        delay(2000);
        lcd.clear();
        pixels.setPixelColor(existingProductIndex, pixels.Color(0, 255, 0));
        pixels.show();
      }
    }
    else {
      addProduct(token);
    }
  }
  else {
    addProduct(token);
  }
  
}

void addProduct(int token){
  Product product;
  product.isRecycled = false;
  product.token = token;
  products[productedCount] = product;
  
  lcdWrap("Produto", "adicionado");
  
  delay(2000);
  
  lcd.clear();
  
  pixels.setPixelColor(productedCount, pixels.Color(255, 0, 0));
  pixels.show();
  productedCount ++;
}

void lcdWrap(String first, String second){
  lcd.setCursor(0, 0);
  lcd.print(first);
  
  lcd.setCursor(0, 1);
  lcd.print(second);
}

void displayProductCount(int producted, int recycled){
  lcd.setCursor(0, 0);
  lcd.print("Prod: ");
  
  lcd.setCursor(12, 0);
  lcd.print("IRC");
  
  lcd.setCursor(6, 0);
  lcd.print(producted);
  
  lcd.setCursor(0, 1);
  lcd.print("Recicl: ");
  
  lcd.setCursor(8, 1);
  lcd.print(recycled);
  
  lcd.setCursor(12, 1);
  if(producted <= 0){
  	irc = 0;
  }
  else {  
    irc = ((float) recycled / (float) producted) * 100;
  }
  lcd.print(round(irc));
  lcd.print("%");
}
