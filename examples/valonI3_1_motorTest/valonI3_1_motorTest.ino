/*************************************************************
  Valon I3 电机驱动测试程序
  ----------------------------------------------------------------
  This example code is in the public domain.
  www.yfrobot.com.cn
  Creation Date: 20240510
  @ YFROBOT
*************************************************************/
#include <ValonI3.h>
ValonI3 valoni3;  // Create an Valon I3 object to be used throughout

unsigned long previousMillis = 0;  // 上次执行操作的时间
const long interval = 1000;        // 操作间隔时间，这里是1000毫秒

enum MotionState { FORWARD_FULL,
                   FORWARD_SLOW,
                   STOP,
                   BACKWARD_SLOW,
                   BACKWARD_FULL,
                   IDLE };
MotionState currentState = IDLE;
unsigned long motionStartTime = 0;
const unsigned long motionDuration = 1000;  // 每个动作持续时间

void setup() {
  Serial.begin(115200);
  Serial.println("Valon I3 motor control Example");
  // Call valoni3.begin(<address>) to initialize.
  //  If it successfully communicates, it'll return 1.
  if (!valoni3.begin(VALONI3_ADDRESS)) {
    Serial.println("Failed to communicate. Check wiring and address of SX1508.");
    while (1) delay(10);  // If we fail to communicate, loop forever.
  }

  valoni3.EnBarrier();  // 使能红外壁障传感器
  // valoni3.DisBarrier();  // 禁用红外壁障传感器

  valoni3.setMotor(0, 0);  // 停止
}

void loop() {

  unsigned long currentMillis = millis();

  int leftSensor = valoni3.readBarrier(BarrierL);   // BarrierL为左侧红外壁障传感器引脚
  int rightSensor = valoni3.readBarrier(BarrierR);  // BarrierR为右侧红外壁障传感器引脚
  Serial.print(leftSensor);
  Serial.print("    ");
  Serial.println(rightSensor);

  // 根据当前状态和时间控制电机
  switch (currentState) {
    case IDLE:
      if (currentMillis - motionStartTime >= motionDuration) {
        currentState = FORWARD_FULL;
        motionStartTime = currentMillis;
        valoni3.setMotor(255, 255);  // 前进
      }
      break;
    case FORWARD_FULL:
      if (currentMillis - motionStartTime >= motionDuration) {
        currentState = FORWARD_SLOW;
        motionStartTime = currentMillis;
        valoni3.setMotor(100, 100);  // 前进
      }
      break;
    case FORWARD_SLOW:
      if (currentMillis - motionStartTime >= motionDuration) {
        currentState = STOP;
        motionStartTime = currentMillis;
        valoni3.setMotor(0, 0);  // 停止
      }
      break;
    case STOP:
      if (currentMillis - motionStartTime >= motionDuration * 2) {  // 停留两倍的时间
        currentState = BACKWARD_FULL;
        motionStartTime = currentMillis;
        valoni3.setMotor(-255, -255);  // 后退
      }
      break;
    case BACKWARD_FULL:
      if (currentMillis - motionStartTime >= motionDuration) {
        currentState = BACKWARD_SLOW;
        motionStartTime = currentMillis;
        valoni3.setMotor(-100, -100);  // 后退
      }
      break;
    case BACKWARD_SLOW:
      if (currentMillis - motionStartTime >= motionDuration) {
        currentState = IDLE;
        motionStartTime = currentMillis;
        valoni3.setMotor(0, 0);  // 停止
      }
      break;
  }
}
