// Motor A

int enA = 9;
int in1 = 4;
int in2 = 5;

// Motor B

int enB = 10;
int in3 = 6;
int in4 = 7;

int data;
int direction;
int PWM = 0;

void setup() {
  Serial.begin(38400);

  // Set all the motor control pins to outputs

  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  // Start with motors disabled and direction forward

  // Motor A

  digitalWrite(enA, LOW);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);

  // Motor B

  digitalWrite(enB, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

}

void loop() {
  if (Serial.available() > 0) { //if some date is sent, reads it and saves in state
    data = Serial.read();
  }

  if ((data >= 0) && (data <= 4))
  {
    if (data == 1)
    {
      // This is Forward
      // Set Motor A forward
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      // Set Motor B forward
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
    }

    else if (data == 2)
    {
      // This is Backward
      // Set Motor A Backward
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      // Set Motor B Backward
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
    }
    else if (data == 3)
    {
      // This is left
      // Set Motor A backward
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      // Set Motor B forward
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
    }
    else if (data == 4)
    {
      //this is right
      // Set Motor A forward
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      // Set Motor B backward
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
    }

    else if (data == 0)
    {
      // Motor A
      digitalWrite(enA, LOW);
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      // Motor B
      digitalWrite(enB, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW);
    }

  }

  else
  {
    PWM = data;
  }
  delay(100);
  analogWrite(enA, PWM);
  analogWrite(enB, PWM);
}
