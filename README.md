[![Open Source Love](https://badges.frapsoft.com/os/v1/open-source.svg?style=flat)](https://github.com/ellerbrock/open-source-badges/)
[![License: GPL-3.0](https://img.shields.io/badge/License-GPL-%2D3.0-blue.svg?logo=github&color=%23F7DF1E)](https://opensource.org/license/gpl-3.0)
![GitHub last commit](https://img.shields.io/github/last-commit/cakraawijaya/Automatic-Weather-System?logo=Codeforces&logoColor=white&color=%23F7DF1E)
![Project](https://img.shields.io/badge/Project-ESP32-light.svg?style=flat&logo=espressif&logoColor=white&color=%23F7DF1E)
![Type](https://img.shields.io/badge/Type-BNSP%20IIoT%20Project-light.svg?style=flat&logo=gitbook&logoColor=white&color=%23F7DF1E)

# Automatic Weather System
Real-time weather monitoring system — monitors river water level, temperature, and humidity with live dashboard visualization, historical data logging, early warning alerts, and synchronized threshold control via Telegram.

<br><br>

## Project Requirements
| Part | Description |
| --- | --- |
| Development Board | DOIT ESP32 DEVKIT V1 |
| Code Editor | Arduino IDE 1.8.19 (Stable Legacy Version) |
| Driver | CP210X USB Driver |
| Application Support | • Node.js<br>• Telegram Bot |
| Integration Platform | Node-RED |
| MQTT Broker | EMQX |
| Communications Protocol | Message Queuing Telemetry Transport (MQTT) |
| IoT Architecture | 3 Layer |
| Programming Language | C/C++ |
| Arduino Library | • WiFi (default)<br>• DHT sensor library by Adafruit (Version: 1.4.6)<br>• PubSubClient by Nick O'Leary (Version: 2.8)<br>• ArduinoJson by Benoit Blanchon (Version: 6.19.4) |
| Node-RED Pallete | • node-red (default)<br>• node-red-dashboard<br>• node-red-node-mysql<br>• node-red-contrib-telegrambot |
| Sensor | • DHT11: Air Temperature & Humidity (x1)<br>• HC-SR04: Ultrasonic Sensor (x1) |
| Other Components | • Micro USB cable - USB type A (x1)<br>• ESP32 expansion board (x1)<br>• Adaptor DC 9V 1A (x1)<br>• Jumper cable (1 set)<br>• Breadboard (x1) |

<br><br>

## Download & Install
1. Arduino IDE

   <table><tr><td width="810">

   ```
   https://bit.ly/ArduinoIDE_Installer
   ```

   </td></tr></table><br>

2. CP210X USB Driver

   <table><tr><td width="810">
   
   ```
   https://bit.ly/CP210X_USBdriver
   ```

   </td></tr></table><br>

3. NodeJS
   <table><tr><td width="810">

   ```
   https://nodejs.org/en/download/prebuilt-installer
   ```

   </td></tr></table>
   
<br><br>

## Project Designs

<table>
<tr>
<th width="840">Architecture</th>
</tr>
<tr>
<td align="center"><img src="Assets/Documentation/Diagram/Architecture.jpg" alt="architecture"></td>
</tr>
</table>
<table>
<tr>
<th width="840">Software Design</th>
</tr>
<tr>
<td align="center"><img src="Assets/Documentation/Diagram/Flowchart Firmware.jpg" alt="flowchart"></td>
</tr>
</table>
<table>
<tr>
<th width="420">Pictorial Diagram</th>
<th width="420">Block Diagram</th>
</tr>
<tr>
<td align="center"><img src="Assets/Documentation/Diagram/Pictorial Diagram.jpg" alt="pictorial-diagram"></td>
<td align="center"><img src="Assets/Documentation/Diagram/Block Diagram.jpg" alt="block-diagram"></td>
</tr>
</table>
<table>
<tr>
<th width="840">Wiring</th>
</tr>
<tr>
<td align="center"><img src="Assets/Documentation/Table/Device Wiring.jpg" alt="wiring"></td>
</tr>
</table>

<br><br>

## Arduino IDE Setup
1. Open the ``` Arduino IDE ``` first, then open the project by clicking ``` File ``` -> ``` Open ``` :

   <table><tr><td width="810">
      
      ``` Code.ino ```

   </td></tr></table><br>
   
2. Fill in the ``` Additional Board Manager URLs ``` in Arduino IDE

   <table><tr><td width="810">
         
      Click ``` File ``` -> ``` Preferences ``` -> enter the ``` Boards Manager Url ``` by copying the following link :
      
      ```
      https://dl.espressif.com/dl/package_esp32_index.json
      ```

   </td></tr></table><br>
   
3. ``` Board Setup ``` in Arduino IDE

   <table>
      <tr><th width="810">

      How to setup the ``` DOIT ESP32 DEVKIT V1 ``` board
            
      </th></tr>
      <tr><td width="810">
         
      • Click ``` Tools ``` -> ``` Board ``` -> ``` Boards Manager ``` -> Install ``` esp32 ```.
   
      • Then selecting a board by clicking: ``` Tools ``` -> ``` Board ``` -> ``` ESP32 Arduino ``` -> ``` DOIT ESP32 DEVKIT V1 ```.

      </td></tr>
   </table><br>
   
4. ``` Change the Board Speed ``` in Arduino IDE

   <table><tr><td width="810">
         
      Click ``` Tools ``` -> ``` Upload Speed ``` -> ``` 115200 ```

   </td></tr></table><br>
   
5. ``` Install Library ``` in Arduino IDE

   <table><tr><td width="810">
         
      Download all the library zip files. Then paste it in the: ``` C:\Users\Computer_Username\Documents\Arduino\libraries ```

   </td></tr></table><br>

6. ``` Port Setup ``` in Arduino IDE

   <table><tr><td width="810">
         
      Click ``` Port ``` -> Choose according to your device port ``` (you can see in device manager) ```

   </td></tr></table><br>

7. Change the ``` WiFi Name ```, ``` WiFi Password ```, and so on according to what you are currently using.<br><br>

8. Before uploading the program, please click: ``` Verify ```.<br><br>

9. If there is no error in the program code, then please click: ``` Upload ```.<br><br>
    
10. Some things you need to do when using the ``` ESP32 board ``` :

    <table><tr><td width="810">
       
       • If ``` ESP32 board ``` cannot process ``` Source Code ``` totally -> Press ``` EN (RST) ``` button -> ``` Restart ```.

       • If ``` ESP32 board ``` cannot process ``` Source Code ``` automatically then :<br>

      - When information: ``` Uploading... ``` has appeared -> immediately press and hold the ``` BOOT ``` button.<br>

      - When information: ``` Writing at .... (%) ``` has appeared -> release the ``` BOOT ``` button.

      • If message: ``` Done Uploading ``` has appeared -> ``` The previously entered program can already be operated ```.

      • Do not press the ``` BOOT ``` and ``` EN ``` buttons at the same time as this may switch to ``` Upload Firmware ``` mode.

    </td></tr></table><br>

11. If there is still a problem when uploading the program, then try checking the ``` driver ``` / ``` port ``` / ``` others ``` section.

<br><br>

## Database
1. Open ``` XAMPP ```, then start the ``` MySQL ``` section to run a database server locally.<br><br>

2. Access the ``` browser ``` first in order to open the database admin panel, please copy the following link: ``` localhost/phpmyadmin/ ```.<br><br>

3. Create a database called ``` aws ```.<br><br>

4. Open the ``` aws ``` database and Import ``` aws.sql ``` in the ``` Automatic-Weather-System/Src/ ``` directory.

<br><br>

## Telegram Bot Setup
1. Open <a href="https://t.me/botfather">@BotFather</a>.<br><br>

2. Type ``` /newbot ```.<br><br>

3. Type the desired bot name, for example: ``` AWS IOT BOT ```.<br><br>

4. Type the desired bot username, for example: ``` aws_iot_indo_bot ```.<br><br>

5. Also do it for bot image settings, bot descriptions, and so on according to your needs.<br><br>

6. Copy ``` your telegram bot API token ``` -> then paste it into the Node-RED flow section. 

<br><br>

## Node-RED Configuration
1. Open ``` Command Prompt (CMD) ```, then enter the following command to install Node-RED :

   <table><tr><td width="810">

   ```
   npm install -g --unsafe-perm node-red
   ```

   </td></tr></table>

   Wait until the installation is complete.<br><br>
   
2. To keep Node-RED secure, You need to set up authentication by running the following command :

   <table><tr><td width="810">

   ```
   node-red admin init
   ```

   </td></tr></table>

   Please select the option as shown in the ``` Node-RED Authentication ``` section of Highlights. For the username and password, please choose your own as needed.<br><br>
   
3. Next, run Node-RED using the following command :

   <table><tr><td width="810">

   ```
   node-red
   ```

   </td></tr></table>

   Wait until the initialization process is complete and a message appears indicating that the server has started successfully.<br><br>

4. After that, Node-RED is ready to be accessed via a web browser using the device's IP address on port 1880.<br><br>

5. Then log in using the account you have configured as a security measure in Node-RED.<br><br>

6. Install all the required Node-RED palettes.<br><br>

7. Open the ``` Import ``` menu in Node-RED, then import ``` flow_nodered.json ``` in the ``` Automatic-Weather-System/Src/ ``` directory. Make sure all Node-RED flows have been successfully loaded.<br><br>

8. Then, to run the flow, click ``` Deploy ```.

<br><br>

## Get Started
1. Download and extract this repository.<br><br>
    
2. Make sure you have the necessary electronic components.<br><br>
   
3. Make sure your components are designed according to the diagram.<br><br>
      
4. Configure your device according to the settings above.<br><br> 
 
5. Please enjoy [Done].

<br><br>

## Highlights

<table>
<tr>
<th width="840">Device</th>
</tr>
<tr>
<td align="center"><img src="Assets/Documentation/Experiment/Device.jpg" alt="device"></td>
</tr>
</table>
<table>
<tr>
<th width="840" colspan="2">Node-RED Authentication</th>
</tr>
<tr>
<td width="420" align="center"><img src="Assets/Documentation/Experiment/NodeRED Admin/Config-1.jpg" alt="config-1"></td>
<td width="420" align="center"><img src="Assets/Documentation/Experiment/NodeRED Admin/Config-2.jpg" alt="config-2"></td>
</tr>
<tr>
<td width="840" colspan="2" align="center"><img src="Assets/Documentation/Experiment/NodeRED Admin/Login.jpg" alt="login"></td>
</tr>
</table>
<table>
<tr>
<th width="840">Node-RED Dashboard</th>
</tr>
<tr>
<td align="center"><img src="Assets/Documentation/Experiment/NodeRED Dashboard.jpg" alt="dashboard"></td>
</tr>
</table>
<table>
<tr>
<th width="840">Telegram Bot Menu</th>
</tr>
<tr>
<td align="center"><img src="Assets/Documentation/Experiment/Telegram Bot Menu.jpg" alt="telegram-bot-menu"></td>
</tr>
</table>
<table>
<tr>
<th width="840" colspan="2">Monitoring Status</th>
</tr>
<tr>
<td width="840" colspan="2" align="center"><img src="Assets/Documentation/Experiment/Monitoring Status/Inject.jpg" alt="monitoring-inject"></td>
</tr>
<tr>
<td width="420" align="center"><img src="Assets/Documentation/Experiment/Monitoring Status/Safe.jpg" alt="safe"></td>
<td width="420" align="center"><img src="Assets/Documentation/Experiment/Monitoring Status/Danger.jpg" alt="danger"></td>
</tr>
</table>
<table>
<tr>
<th width="840" colspan="2">Early Warning System</th>
</tr>
<tr>
<td width="420" align="center"><img src="Assets/Documentation/Experiment/Early Warning System/Inject.jpg" alt="telegram-bot-inject"></td>
</tr>
<tr>
<td width="420" align="center"><img src="Assets/Documentation/Experiment/Early Warning System/Telegram Bot Alert.jpg" alt="telegram-bot-alert"></td>
</tr>
</table>

<br>
<strong>More information:</strong> <a href="https://github.com/cakraawijaya/Automatic-Weather-System/blob/master/Assets/Documentation/Report/Portofolio%20Pelatihan%20Sertifikasi%20BNSP%20IIoT%20-%20Devan%20Cakra%20Mudra%20Wijaya-63-81.pdf"><u>Click Here</u></a>

<br><br><br>

## Appreciation
If this work is useful to you, then support this work as a form of appreciation to the author by clicking the ``` ⭐Star ``` button at the top of the repository.

<br><br>

## Disclaimer
This application is the result of the development of the Edutic.id x BNSP Bootcamp 2026. I do not deny that I still use third-party services in this work, including: libraries, frameworks, and so on.
