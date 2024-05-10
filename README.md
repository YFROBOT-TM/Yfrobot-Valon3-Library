# Yfrobot-VALON-I3-Library
YFROBOT Motor Driver Library for VALON-I3

适配VALON-I3小车套件：VALON-I3_Arduino

适用对象：[VALON-I3](https://item.taobao.com/item.htm?id=622871845399)、[VALON-I3简介](http://www.yfrobot.com.cn/wiki/index.php?title=Arduino_Valon-I3)


![](./assets/YF_VALONI3.jpg)


#### Valon-I 使用说明：

创建对象：

`MotorDriver motorDirver = MotorDriver(YF_VALON);`

Methods：

设置电机方向，参数：1-默认，-1-反向 (可选，不使用该函数，电机方向默认)

`motorDirver.motorConfig(1, 1);// 左右电机默认方向`

`motorDirver.motorConfig(1); // 所有电机默认方向`

驱动电机，参数：电机速度 -255 ~ 255

`motorDirver.setMotor(255, 128);  // 左电机全速正转,右电机 50%速度正转`

`motorDirver.setMotor(0, 0);  // 左右电机停止`


#### 库版本说明：

*  V0.0.1 初始版本-20240510