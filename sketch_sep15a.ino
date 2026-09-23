int led1 = 6;
int led2 = 7;
int led3 = 8;
int led4 = 9;
int leds[] = {led1, led2,led3,led4};
bool gameOver = false;
int sequence[100];
int level = 1;

int button1 = 2;
int button2 = 3;
int button3 = 4;
int button4 = 5;


int color;

const int buzzer = 11;


void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);

  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  pinMode(button4, INPUT_PULLUP);

  pinMode(buzzer,OUTPUT);
  randomSeed(analogRead(A0));

  for (int i = 0; i < 4; i++) {
    digitalWrite(leds[i], HIGH);
   }
  delay(300);
  for (int i = 0; i < 4; i++) {
    digitalWrite(leds[i], LOW);
   }



  Serial.begin(9600);
  tone(buzzer, 900);
  delay(2000);
  noTone(buzzer);
  

}

void loop() {
// random(1,5);
   if (gameOver == false) {
      sequence[level-1] = random(1,5);
      for (int i = 0; i < level; i++){
         delay(1000);
         Serial.println(sequence[i]);
         playColor(sequence[i]);
      }

      for (int i=0; i<level; i++) {
         int playerChoice = checkButton();

         while (playerChoice == 0) {
            playerChoice = checkButton();
         }


         if (level == 3) {
         gameOver = true; 
         playColor(1);
         playColor(2);
         playColor(3);
         playColor(4);
         Serial.println("YOU WON!");
         Serial.println("Play Again?");
         break;
         }

         if (playerChoice == sequence[i]) {
            Serial.println("Correct!");
         } else {
            Serial.println("Wrong!");
            Serial.println("GAME OVER");
            Serial.print("Score: ");
            Serial.println(level - 1);
            Serial.println("PRESS ANY BUTTON");

            for (int i = 0; i < 4; i++) {
               digitalWrite(leds[i], HIGH);
            }
            delay(300);
            tone(buzzer, 900);
            delay(2000);
            noTone(buzzer);
            for (int i = 0; i < 4; i++) {
               digitalWrite(leds[i], LOW);
            }

            gameOver = true;
            break;
         }
      }
      if (gameOver == false) {
         level++;
      }
   }

   if (gameOver == true) {

         playColor(1);
         delay(2000);

         int restartButton = checkButton();

         if (restartButton != 0) {
            level = 1;
            gameOver = false;
         }
   }
}

void playColor (int color) {
   switch (color) {
      case 1:
         digitalWrite(led1, HIGH);
         tone(buzzer, 1047);
         delay(200);
         noTone(buzzer);
         digitalWrite(led1,LOW);
         break;
      case 2:
         digitalWrite(led2, HIGH);
         tone(buzzer, 784);
         delay(200);
         noTone(buzzer);
         digitalWrite(led2,LOW);
         break;
      case 3:
         digitalWrite(led3, HIGH);
         tone(buzzer, 659);
         delay(200);
         noTone(buzzer);
         digitalWrite(led3,LOW);
         break;
      case 4:
         digitalWrite(led4, HIGH);
         tone(buzzer, 523);
         delay(200);
         noTone(buzzer);
         digitalWrite(led4,LOW);
         break;
      
   }
}

int checkButton() {
   if(digitalRead(button1) == LOW) {
      playColor(1);
      while(digitalRead(button1) == LOW ) {
         delay(10);
      }

      return 1;
   }

   if(digitalRead(button2) == LOW) {
      playColor(2);
      while(digitalRead(button2) == LOW ) {
         delay(10);
      }
      return 2;
   }

   if(digitalRead(button3) == LOW) {
      playColor(3);
      while(digitalRead(button3) == LOW ) {
         delay(10);
      }
      return 3;
   }

   if(digitalRead(button4) == LOW) {
      playColor(4);
      while(digitalRead(button4) == LOW ) {
         delay(10);
      }
      return 4;
   }

   return 0;
}





