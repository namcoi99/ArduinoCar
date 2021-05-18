#define inA1 2 //Định nghĩa chân in1 của động cơ A  //right
#define inA2 3 //Định nghĩa chân in2 của động cơ A
#define inB1 5 //Định nghĩa chân in1 của động cơ B  // left
#define inB2 4 //Định nghĩa chân in2 của động cơ B
#define enA 6
#define enB 11


 int M1_Speed = 100; // speed of motor 1
 int M2_Speed = 100; // speed of motor 2
 int LeftRotationSpeed = 120;  // Left Rotation Speed
 int RightRotationSpeed = 120; // Right Rotation Speed
int Sensor1 = 8;
int Sensor3 = 10;

 void setup() {

  pinMode(inA1,OUTPUT);
  pinMode(inA2,OUTPUT);
  pinMode(inB1,OUTPUT);
  pinMode(inB2,OUTPUT);

    pinMode(enA,OUTPUT);
    pinMode(enB,OUTPUT);

      pinMode(Sensor3, INPUT); // initialize Left sensor as an input
      pinMode(Sensor1, INPUT); // initialize Right sensor as an input

}

void loop() {

  int LEFT_SENSOR = digitalRead(Sensor3);
  int RIGHT_SENSOR = digitalRead(Sensor1);

if(RIGHT_SENSOR==0 && LEFT_SENSOR==0) {
    forward(); //FORWARD
}

  else if(RIGHT_SENSOR==0 && LEFT_SENSOR==1) {
    right(); //Move Right
 }

  else if(RIGHT_SENSOR==1 && LEFT_SENSOR==0) {
    left(); //Move Left
}

  else if(RIGHT_SENSOR==1 && LEFT_SENSOR==1) {
    Stop();  //STOP
 }
}



void forward()
{
            digitalWrite(inA1, HIGH);
            digitalWrite(inA2, LOW);
            digitalWrite(inB1, HIGH);
            digitalWrite(inB2, LOW);

                analogWrite(enA, M1_Speed);
                analogWrite(enB, M2_Speed);
}

void backward()
{
            digitalWrite(inA1, LOW);
            digitalWrite(inA2, HIGH);
            digitalWrite(inB1, LOW);
            digitalWrite(inB2, HIGH);

                analogWrite(enA, M1_Speed);
                analogWrite(enB, M2_Speed);
}

void right()
{
            digitalWrite(inA1, LOW);
            digitalWrite(inA2, HIGH);
            digitalWrite(inB1, HIGH);
            digitalWrite(inB2, LOW);

                analogWrite(enA, LeftRotationSpeed);
                analogWrite(enB, RightRotationSpeed);
}

void left()
{
            digitalWrite(inA1, HIGH);
            digitalWrite(inA2, LOW);
            digitalWrite(inB1, LOW);
            digitalWrite(inB2, HIGH);

                analogWrite(enA, LeftRotationSpeed);
                analogWrite(enB, RightRotationSpeed);
}

void Stop()
{
            digitalWrite(inA1, LOW);
            digitalWrite(inA2, LOW);
            digitalWrite(inB1, LOW);
            digitalWrite(inB2, LOW);
}
