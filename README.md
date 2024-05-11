# Yfrobot-VALON-I3-Library
YFROBOT Motor Driver Library for VALON-I3

适配VALON-I3小车套件：VALON-I3_Arduino，功能：电机驱动、红外壁障、电机测速。

适用对象：[VALON-I3](https://item.taobao.com/item.htm?id=622871845399)、[VALON-I3简介](http://www.yfrobot.com.cn/wiki/index.php?title=Arduino_Valon-I3)


![](./assets/YF_VALONI3.jpg)


#### Valon-I 使用说明：

创建对象：

`ValonI3 valoni3;`

Methods：

初始化

`valoni3.begin(VALONI3_ADDRESS) `

使能红外壁障

`valoni3.EnBarrier();  // 使能红外壁障传感器`

禁用红外壁障

`valoni3.DisBarrier();  // 禁用红外壁障传感器`

驱动电机，参数：电机速度 -255 ~ 255

`valoni3.setMotor(0, 0);`

读取红外壁障传感器，参数：BarrierL、BarrierR

`valoni3.readBarrier(BarrierR)`

读取红外壁障传感器，参数：BarrierL、BarrierR

`valoni3.readBarrier(BarrierR)`

读取红外壁障传感器，参数：BarrierL、BarrierR

`valoni3.readBarrier(BarrierR)`

启用引脚中断

`valoni3.startISR();`

关闭引脚中断

`valoni3.stopISR();`

获取左侧编码器的数值

`valoni3.getCountsLeft();`

获取左侧编码器的数值

`valoni3.getCountsRight();`

获取左侧编码器的数值并重置

`valoni3.getCountsAndResetLeft();`

获取左侧编码器的数值并重置

`valoni3.getCountsAndResetRight();`

检查左侧编码器错误

`valoni3.checkErrorLeft();`

检查右侧编码器错误

`valoni3.checkErrorRight();`


#### 库版本说明：

*  V0.0.3 增加双电机测速函数-20240511
*  V0.0.2 错误发布已删除-20240511
*  V0.0.1 初始版本-20240510