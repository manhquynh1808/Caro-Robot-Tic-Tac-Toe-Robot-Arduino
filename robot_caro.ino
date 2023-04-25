#include <AccelStepper.h>
#include <Servo.h>
#include <math.h>

int en =8;
// Define the stepper motors and the pins the will use
//AccelStepper stepper1(1, 3, 4); // (Type:driver, STEP, DIR)
//AccelStepper stepper2(1, 7, 6);
//AccelStepper stepper3(1, 10, 9);

AccelStepper stepper1(1, 2, 5); // (Type:driver, STEP, DIR)
AccelStepper stepper2(1, 3, 6);
AccelStepper stepper3(1, 4, 7);


int stepper1Position, stepper2Position, stepper3Position;
int val_1, val, dat=0;
float c1,s1,c2,s2,x,y,t1,t2;

const float pi= 3.14;
const float theta1AngleToSteps = 13.33;//(200*10)/360; // đổi độ sang số bước
const float theta2AngleToSteps = 13.33;//200/360;

int theta1Array;
int theta2Array;
int theta3Array = 360;//6000;//11.85
int positionsCounter = 40; // số vị trí cần di chuyển đến #######################################################

void setup() 
{
  Serial.begin(9600);

  // Stepper motors max speed
  stepper1.setMaxSpeed(10000);
  stepper1.setAcceleration(10000); // số bước trên giây
  stepper2.setMaxSpeed(10000);
  stepper2.setAcceleration(10000);
  stepper3.setMaxSpeed(10000);
  stepper3.setAcceleration(10000);
  //homing();
  pinMode(en, OUTPUT);
}

void loop() 
{
  digitalWrite(en,0);
  Serial.println("Nhap vao o va ky tu can danh:");
  val_1 = Serial.parseFloat();
  if(val_1==55)
  {val=66;}
val_1 = 10;

  //ĐIỂM O1/@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@1
  if(val_1 == 10)
  {
    float l2=22;
    float l3=19.5;
    for(float t=0;t<=(2.1*pi);t=t+0.05)//đường tròn
    {
      x=-10+7*cos(t);//pt đường tròn x = a +R sint với I(a,b) tâm
      y=35+7*sin(t);// y = b + R cos t
      
      c2=(pow(x,2)+ pow(y,2)-pow(l2,2)-pow(l3,2))/(2*l2*l3);
      s2=sqrt(1 - pow(c2,2));
      //
      c1=(x*(l2+l3*c2)+y*l3*s2);
      s1=(y*(l2+l3*c2)-x*l3*s2);
      //ĐỔI RAD SANG ĐỘ
      float theta1=(atan2(s1,c1)*180)/3.14;
      float theta2=(atan2(s2,c2)*180)/3.14;

      theta1Array = theta1 * theta1AngleToSteps; //store the values in steps = angles * angleToSteps variable
      theta2Array = theta2 * theta2AngleToSteps;
      
      stepper1.setSpeed(3000);//1000
      stepper2.setSpeed(3000);//500
      stepper3.setSpeed(2000);//200
      stepper1.setAcceleration(3000);
      stepper2.setAcceleration(3000);
      stepper3.setAcceleration(2000); 
      
      stepper1.moveTo(theta1Array);
      stepper2.moveTo(theta2Array);
      //stepper3.moveTo(theta3Array);

        
      Serial.print("theta1_xung:");
      Serial.println(theta1Array);
      Serial.print("theta2_xung:");
      Serial.println(theta2Array);

      while (stepper1.currentPosition() != theta1Array || stepper2.currentPosition() != theta2Array)
      {
        stepper2.run();
        stepper1.run();        
      }
      theta3Array=15000;
      stepper3.moveTo(theta3Array);
      while (stepper3.currentPosition() != theta3Array)
      {
        stepper3.run();
      }
    }
    theta3Array=0;
    stepper3.moveTo(theta3Array);
    while (stepper3.currentPosition() != theta3Array)
    {
      stepper3.run();
    }
  }

//______________________________________________________999999999999999999999999999999999999999999999999_______________________________________________________//
//______________________________________________________999999999999999999999999999999999999999999999999_______________________________________________________//
//______________________________________________________999999999999999999999999999999999999999999999999_______________________________________________________//

  //ĐIỂM X1/@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
  if(val_1 == 11)
  {
    float l2=22;
    float l3=19.5;
    for(float t=0;t<=1;t=t+0.05)
    { 
      x=-11+(-9+11)*t;// pt đường thẳng thứ nhất x = x0 +at với điểm đi qua là M(x0,y0), vecto chỉ phương U=(a,b)
      y=16+(14-16)*t;// y = y0 +bt vecto chỉ phương lấy tọa độ sau rừ tọa độ đàu
      
      c2=(pow(x,2)+ pow(y,2)-pow(l2,2)-pow(l3,2))/(2*l2*l3);
      s2=sqrt(1 - pow(c2,2));
      //
      c1=(x*(l2+l3*c2)+y*l3*s2);
      s1=(y*(l2+l3*c2)-x*l3*s2);
      //ĐỔI RAD SANG ĐỘ
      float theta1=(atan2(s1,c1)*180)/3.14;
      float theta2=(atan2(s2,c2)*180)/3.14;

      theta1Array = theta1 * theta1AngleToSteps; //store the values in steps = angles * angleToSteps variable
      theta2Array = theta2 * theta2AngleToSteps;
      
      stepper1.setSpeed(3000);//1000
      stepper2.setSpeed(3000);//500
      stepper3.setSpeed(2000);//200
      stepper1.setAcceleration(3000);
      stepper2.setAcceleration(3000);
      stepper3.setAcceleration(2000); 
      
      stepper1.moveTo(theta1Array);
      stepper2.moveTo(theta2Array);
      //stepper3.moveTo(theta3Array);

      while (stepper1.currentPosition() != theta1Array || stepper2.currentPosition() != theta2Array)
      {
        stepper2.run();
        stepper1.run();        
      }
      theta3Array=15000;
      stepper3.moveTo(theta3Array);
      while (stepper3.currentPosition() != theta3Array)
      {
        stepper3.run();
      }
    }

    theta3Array=8000;
    stepper3.moveTo(theta3Array);
    while (stepper3.currentPosition() != theta3Array)
    {
      stepper3.run();
    }
    //########################################################
    for(float t=0;t<=1;t=t+0.05)
    { 
      x=-11+(-9+11)*t;// pt đường thẳng thứ nhất x = x0 +at với điểm đi qua là M(x0,y0), vecto chỉ phương U=(a,b)
      y=14+(16-14)*t;// y = y0 +bt vecto chỉ phương lấy tọa độ sau rừ tọa độ đàu
      
      c2=(pow(x,2)+ pow(y,2)-pow(l2,2)-pow(l3,2))/(2*l2*l3);
      s2=sqrt(1 - pow(c2,2));
      //
      c1=(x*(l2+l3*c2)+y*l3*s2);
      s1=(y*(l2+l3*c2)-x*l3*s2);
      //ĐỔI RAD SANG ĐỘ
      float theta1=(atan2(s1,c1)*180)/3.14;
      float theta2=(atan2(s2,c2)*180)/3.14;

      theta1Array = theta1 * theta1AngleToSteps; //store the values in steps = angles * angleToSteps variable
      theta2Array = theta2 * theta2AngleToSteps;
      
      stepper1.setSpeed(300);//1000
      stepper2.setSpeed(300);//500
      stepper3.setSpeed(200);//200
      stepper1.setAcceleration(300);
      stepper2.setAcceleration(300);
      stepper3.setAcceleration(200); 
      
      stepper1.moveTo(theta1Array);
      stepper2.moveTo(theta2Array);
      //stepper3.moveTo(theta3Array);

      while (stepper1.currentPosition() != theta1Array || stepper2.currentPosition() != theta2Array)
      {
        stepper2.run();
        stepper1.run();        
      }
      theta3Array=15000;
      stepper3.moveTo(theta3Array);
      while (stepper3.currentPosition() != theta3Array)
      {
        stepper3.run();
      }
    }
    theta3Array=0;
    stepper3.moveTo(theta3Array);
    while (stepper3.currentPosition() != theta3Array)
    {
      stepper3.run();
    }
  }

 
  //////////////////////////////// QUAY VỀ HOME
  if (val_1 == 55) 
  { 
    stepper1.moveTo(0);
    stepper2.moveTo(0);
    stepper3.moveTo(0);
    theta3Array=0;

    while (stepper3.currentPosition() != theta3Array)
    {
      stepper3.run();
    }  

    while (stepper3.currentPosition() == 0)
    {
      stepper1.run();
      stepper2.run();       
    }
  }    
}

 
