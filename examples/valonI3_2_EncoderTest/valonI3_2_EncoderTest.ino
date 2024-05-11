/*************************************************************
  Valon I3 双电机测速测试程序
    both Motor speed measurement - 双电机速度测量
  ----------------------------------------------------------------
  This example code is in the public domain.
  www.yfrobot.com.cn
  Creation Date: 20240511
  @ YFROBOT
*************************************************************/
#include <ValonI3.h>
ValonI3 valoni3;  // Create an Valon I3 object to be used throughout

unsigned long previousMillis = 0;  // 记录上一次时间
int intervalTime = 100;            // 采样时间
int Speed = 150;                   // 电机运行速度

char report[80];

int16_t countsLeft = 0;
int16_t countsRight = 0;

void setup() {
  Serial.begin(115200);
  if (!valoni3.begin(VALONI3_ADDRESS)) {
    Serial.println("Failed to communicate. Check wiring and address of SX1508.");
    while (1) delay(10);  // If we fail to communicate, loop forever.
  }

  valoni3.setMotor(255, 255);  // 前进
  valoni3.startISR();          // 启动测速中断，模式：CHANGE 每当引脚改变值时触发中断
  previousMillis = millis();
}

void loop() {
  if ((unsigned long)(millis() - previousMillis) >= intervalTime) {
    valoni3.stopISR();
    previousMillis = millis();

    // countsLeft = valoni3.getCountsLeft();    // 获取左侧编码器的数值
    // countsRight = valoni3.getCountsRight();  // 获取左侧编码器的数值

    countsLeft = valoni3.getCountsAndResetLeft();    // 获取左侧编码器的数值并重置
    countsRight = valoni3.getCountsAndResetRight();  // 获取左侧编码器的数值并重置

    bool errorsLeft = valoni3.checkErrorLeft();
    bool errorsRight = valoni3.checkErrorRight();

    // Send the information to the serial monitor.
    snprintf_P(report, sizeof(report), PSTR("%6d %6d %1d %1d"), countsLeft, countsRight, errorsLeft, errorsRight);
    Serial.println(report);
    valoni3.startISR();
  }
}