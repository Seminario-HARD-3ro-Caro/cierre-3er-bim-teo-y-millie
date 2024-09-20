// Ejercicio evaluatorio 3er bimestre
/*
  Integrantes
    Nombre:Milagros 
    Apellido: Loisi
    Curso: 3ETIC
    
    Nombre: Teo
    Apellido: Gonzalez
    Curso: 3ETIC
  
Congisgnas
  Conexionado:
    En la protoboard, conectar 4 LEDs para que cada uno pueda ser controlado individualmente. Cada LED deberá tener su respectiva resistencia.
    Se debe conectar tambien, un pulsador que permita recibir información de un usuario.
    Indicar a continuación los pines a los cuales se conectó cada elemento y el valor de resistencias utilizado:
      Pines:
        Boton:7
        LED1: 2
        LED2: 3
        LED3: 4
        LED4: 5
      Valor:
        R_boton: 
        R_LEDs: 330

  Progamas:
    Se deben entregar un programa distinto por cada punto. Los programas son una modificación entre ellos.
    El código deberá estar comentado indicando qué se propone hacer con cada línea de código
    1.  El primer programa sirve para corroborar la correcta conexión de los elementos de hardware.
        El mismo deberá encender TODOS los LEDs cuando se presione el pulsador y apagarlos cuando éste se suelte.
    2.  En el siguiente programa se deberá prender de a UN LED POR VEZ.
        Por cada pulsación se deberá apagar el LED prendido y prender el LED más próximo de la derecha.
        En caso de no haber, se deberá volver a empezar la vuelta, empezando desde el LED de la izquierda.
    3.  A continnuación se desea fabricar un contador binario de 4 bits.
        El programa deberá contar de 0 a 15 mostrando la cuenta actual a través de los 4 LEDs.
        Se interpreta 0 si el LED está apagado y 1 si el LED está prendido. 
        La cuenta aumenta cada vez que el pulsador es presionado, al llegar a 15 deberá volver a empezar en 0.
        IMPORTANTE: la cuenta debe aumentar UNA SOLA VEZ por cada pulsación.
    4. Opcional:
        Utilizando comunicación serie, se desea crear un programa que muestre mediante los LEDs, el nro ingresado en el monitor serie.
        El programa deberá mostrar el número binario prendiendo los LEDs según el criterio del programa 3.
        El nro mostrado será ingresado por el usuario mediante el monitor serie.
        IMPORTANTE: si el nro es mayor a 15 se deberá enviar un mensaje de error. 

*/ 
#define ROJO 2
#define AMARILLO 3
#define VERDE 4
#define AZUL 5
#define BOTON 7
bool flagbtn=false;

void setup() {
 //Definimos los pines
 pinMode(ROJO, OUTPUT);
  pinMode(AMARILLO, OUTPUT);
  pinMode(VERDE, OUTPUT);
  pinMode(AZUL, OUTPUT);
  pinMode(BOTON, INPUT);
//se prende solo el rojo
  digitalWrite(AMARILLO,1); 
digitalWrite(ROJO,0);
digitalWrite(AZUL,1);
digitalWrite(VERDE,1);
}

void loop() {
  //si el boton se apreto y estaba suelto
  if(digitalRead(BOTON)==1){
    //codigo para que pase de un led a otro y se levante la flag
    if(flagbtn==false){
      if(digitalRead(ROJO)==0){
       digitalWrite(AMARILLO,0);
       digitalWrite(ROJO,1);
       flagbtn=true;
      }else if(digitalRead(AMARILLO)==0){
       digitalWrite(AMARILLO,1);
       digitalWrite(VERDE,0);
       flagbtn=true;
      }else if(digitalRead(VERDE)==0){
       digitalWrite(AZUL,0);
       digitalWrite(VERDE,1);
       flagbtn=true;
      }else if(digitalRead(AZUL)==0){
       digitalWrite(AZUL,1);
       digitalWrite(ROJO,0);
       flagbtn=true;
      }
  
   }
  }
  //si el boton esta suelto se resetea la flag
  if(digitalRead(BOTON)==0){
    flagbtn=false;
    }
}
