# NDKDome
### android studio 3.0 使用CMake来配置ndk进行jni开发
### dome中包含 java调用c++代码，c++调用java 静态方法，修改静态成员变量，以及调用非静态方法，修改非静态成员变量

## 使用命令
### 1.编译
##### cd app/src/main/java
##### javah -encoding UTF-8 -d ../jni com.ndk.dome.Hello

### 2.查看方法签名
##### cd app\build\intermediates\classes\debug
##### javap -s com.lqm.ndkjnistudy.Hello

## 注意事项
### 1.创建类的对象时
##### 构造函数默认方法名为：<<int>>
##### 方法签名为：()V
