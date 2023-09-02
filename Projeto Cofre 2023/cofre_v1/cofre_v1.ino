// Projeto : COFRE
// INCLUIR AS BIBLIOTECAS

#include <Servo.h>
#include <LiquidCrystal.h>
#include <Keypad.h>

// DECLARAÇÃO DE VARIAVEIS
Servo servo_1; // SERVO 1
const int Buzzer = 50;

int variavel = 0;                                                                                        // VARIAVEL AUXILIAR PARA O ARMAZENAMENTO DA SENHA
int num1 = 0, num2 = 0, num3 = 0, num4 = 0, num5 = 0, num6 = 0, num7 = 0, num8 = 0, num9 = 0, num10 = 0; // NUMEROS DE AMARZENAMENTO DOS DIGITOS DA SENHA
int dig1 = 1, dig2 = 1, dig3 = 1, dig4 = 1, dig5 = 1, dig6 = 6, dig7 = 7, dig8 = 8, dig9 = 9, dig10 = 0; // DIGITOS DA SENHA
  // CONFIGURAÇÃO TECLADO

const byte filas = 4;
const byte columnas = 4;
char tecla[filas][columnas] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

// DECLARAÇÃO LIGAÇÃO ARDUINO
byte pinFilas[filas] = {7, 6, 5, 4}; // PINOS LIGADOS A linha

byte pinColumnas[columnas] = {3, 2, 1, 0}; // PINOS LIGADOS A COLUNA
Keypad keypad = Keypad(makeKeymap(tecla), pinFilas, pinColumnas, filas, columnas);
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
void setup()
{
  lcd.begin(16, 2);
  servo_1.attach(52);
  servo_1.write(0);
  pinMode(Buzzer, OUTPUT);
}
/*
void trocaSenha(){


}
*/
void loop()
{
  char key = keypad.getKey();
  if (key)
  {
    lcd.setCursor(3 + variavel, 1);
    lcd.print(key);
    key = key - 48; // CONVERÇÃO DOS DIGITOS DO TECLADO
    variavel++;
    switch (variavel) {
      case 1:
        num1 = key; // ARMAZENAR O 1o DIGITO DA SENHA
        break;
      case 2:
        num2 = key; // ARMAZENAR O 2o DIGITO DA SENHA
        break;
      case 3:
        num3 = key; // ARMAZENAR O 3o DIGITO DA SENHA
        break;
      case 4:
        num4 = key; // ARMAZENAR O 4o DIGITO DA SENHA
        break;
      case 5:
        num5 = key; // ARMAZENAR O 5o DIGITO DA SENHA
        delay(100);
    
    // testa se senha está correta
    if (num1 == dig1 && num2 == dig2 && num3 == dig3 && num4 == dig4 && num5 == dig5)
    { // COMPARANDO SE A SENHA DIGITADA É IGUAL A SENHA CORRETA
      lcd.clear();
      lcd.setCursor(6, 0);
      lcd.print("SENHA");
      lcd.setCursor(5, 1);
      lcd.print("CORRETA");
      servo_1.write(90);
      delay(2003);
      servo_1.write(0);
      lcd.clear();
    }
    else
    {
      lcd.clear();
      lcd.setCursor(6, 0);
      lcd.print("SENHA");
      lcd.setCursor(4, 1);
      lcd.print("INCORRETA");
      digitalWrite(Buzzer, HIGH); // BARULHO BUZZER
      delay(500);
      digitalWrite(Buzzer, LOW);// BUZZER DESLIGANDO
      delay(100);

      lcd.clear();
    }
    variavel = 0;
    lcd.clear(); // limpa lcd
    break;
    }
  }

  if (!key)
  {
    lcd.setCursor(1, 0), lcd.print("INSIRA A SENHA:");
  } // MENSAGEM INICIAL
  delay(2);
}
