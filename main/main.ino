int MotorEsq2 = 7; //pino esquerdo do motor 2
int blue1 = 0; //pino1 de encaixe do bluetooth
int blue2 = 1; //pino2 de encaixe do ''


void setup()
{
 pinMode(MotorDir1,OUTPUT); //
 pinMode(MotorDir2,OUTPUT); //
 pinMode(MotorEsq1,OUTPUT); //
 pinMode(MotorEsq2,OUTPUT); //
}

void loop()
{
 digitalWrite(4, LOW); //
 digitalWrite(5, LOW);
 digitalWrite(6, LOW);
 digitalWrite(7, LOW);
}
input (controle());
if (controle == 1) //1 = ir para frente
{
 digitalWrite(4, HIGH); 
 digitalWrite(5, HIGH);
 digitalWrite(6, HIGH);
 digitalWrite(7, HIGH);
}
if (controle == 2) // 2 = virar pra direita
{
 digitalWrite(4, LOW); 
 digitalWrite(5, LOW);
 digitalWrite(6, HIGH); //roda direita
 digitalWrite(7, HIGH);
}
if (controle == 3) //3 = Virar pra esquerda
{
   digitalWrite(4, HIGH); //roda esquerda
 digitalWrite(5, HIGH);
 digitalWrite(6, LOW);
 digitalWrite(7, LOW);
}
