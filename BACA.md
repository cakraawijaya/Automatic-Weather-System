[![Open Source Love](https://badges.frapsoft.com/os/v1/open-source.svg?style=flat)](https://github.com/ellerbrock/open-source-badges/)
[![License: GPL-3.0](https://img.shields.io/badge/License-GPL-%2D3.0-blue.svg?logo=github&color=%23F7DF1E)](https://opensource.org/license/gpl-3.0)
![GitHub last commit](https://img.shields.io/github/last-commit/cakraawijaya/Automatic-Weather-System?logo=Codeforces&logoColor=white&color=%23F7DF1E)
![Project](https://img.shields.io/badge/Project-ESP32-light.svg?style=flat&logo=espressif&logoColor=white&color=%23F7DF1E)
![Type](https://img.shields.io/badge/Type-BNSP%20IIoT%20Project-light.svg?style=flat&logo=gitbook&logoColor=white&color=%23F7DF1E)

# Automatic Weather System
Sistem pemantauan cuaca secara real-time — memantau ketinggian air sungai, suhu, dan kelembapan dengan visualisasi dasbor langsung, pencatatan data historis, peringatan dini, serta pengendalian ambang batas yang tersinkronisasi melalui Telegram.

<br><br>

## Kebutuhan Proyek
| Bagian | Deskripsi |
| --- | --- |
| Papan Pengembangan | DOIT ESP32 DEVKIT V1 |
| Editor Kode | Arduino IDE 1.8.19 (Versi Lama yang Stabil) |
| Driver | CP210X USB Driver |
| Dukungan Aplikasi | • Node.js<br>• Bot Telegram |
| Platform Integrasi | Node-RED |
| Broker MQTT | EMQX |
| Protokol Komunikasi | Message Queuing Telemetry Transport (MQTT) |
| Arsitektur IoT | 3 Lapisan |
| Bahasa Pemrograman | C/C++ |
| Pustaka Arduino | • WiFi (bawaan)<br>• DHT sensor library oleh Adafruit (Versi: 1.4.6)<br>• PubSubClient oleh Nick O'Leary (Versi: 2.8)<br>• ArduinoJson oleh Benoit Blanchon (Versi: 6.19.4) |
| Palet Node-RED | • node-red (bawaan)<br>• node-red-dashboard<br>• node-red-node-mysql<br>• node-red-contrib-telegrambot |
| Sensor | • DHT11: Suhu & Kelembapan Udara (x1)<br>• HC-SR04: Sensor Ultrasonik (x1) |
| Komponen Lainnya | • Kabel USB Mikro - USB tipe A (x1)<br>• Papan ekspansi ESP32 (x1)<br>• Adaptor DC 9V 1A (x1)<br>• Kabel jumper (1 set)<br>• Breadboard (x1) |

<br><br>

## Unduh & Instal
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

## Rancangan Proyek

<table>
<tr>
<th width="840">Arsitektur</th>
</tr>
<tr>
<td align="center"><img src="Assets/Documentation/Diagram/Architecture.jpg" alt="architecture"></td>
</tr>
</table>
<table>
<tr>
<th width="840">Desain Perangkat Lunak</th>
</tr>
<tr>
<td align="center"><img src="Assets/Documentation/Diagram/Flowchart Firmware.jpg" alt="flowchart"></td>
</tr>
</table>
<table>
<tr>
<th width="420">Diagram Ilustrasi</th>
<th width="420">Diagram Blok</th>
</tr>
<tr>
<td align="center"><img src="Assets/Documentation/Diagram/Pictorial Diagram.jpg" alt="pictorial-diagram"></td>
<td align="center"><img src="Assets/Documentation/Diagram/Block Diagram.jpg" alt="block-diagram"></td>
</tr>
</table>
<table>
<tr>
<th width="840">Pengkabelan</th>
</tr>
<tr>
<td align="center"><img src="Assets/Documentation/Table/Device Wiring.jpg" alt="wiring"></td>
</tr>
</table>

<br><br>

## Pengaturan Arduino IDE
1. Buka ``` Arduino IDE ``` terlebih dahulu, kemudian buka proyek dengan cara klik ``` File ``` -> ``` Open ``` : 

   <table><tr><td width="810">
      
      ``` Code.ino ```
         
   </td></tr></table><br>
   
2. Isi ``` Url Pengelola Papan Tambahan ``` di Arduino IDE

   <table><tr><td width="810">

      Klik ``` File ``` -> ``` Preferences ``` -> masukkan ``` Boards Manager Url ``` dengan menyalin tautan berikut :
      
      ```
      https://dl.espressif.com/dl/package_esp32_index.json
      ```
         
   </td></tr></table><br>
   
3. ``` Pengaturan Board ``` di Arduino IDE

   <table>
      <tr><th width="810">

      Cara mengatur board ``` DOIT ESP32 DEVKIT V1 ```
            
      </th></tr>
      <tr><td width="810">
         
      • Klik ``` Tools ``` -> ``` Board ``` -> ``` Boards Manager ``` -> Instal ``` esp32 ```.

      • Kemudian pilih papan dengan mengklik: ``` Tools ``` -> ``` Board ``` -> ``` ESP32 Arduino ``` -> ``` DOIT ESP32 DEVKIT V1 ```.

      </td></tr>
   </table><br>
   
4. ``` Ubah Kecepatan Papan ``` di Arduino IDE

   <table><tr><td width="810">

      Klik ``` Tools ``` -> ``` Upload Speed ``` -> ``` 115200 ```
         
   </td></tr></table><br>
   
5. ``` Instal Pustaka ``` di Arduino IDE

   <table><tr><td width="810">

      Unduh semua file zip pustaka. Kemudian tempelkan di: ``` C:\Users\Computer_Username\Documents\Arduino\libraries ```
         
   </td></tr></table><br>

6. ``` Pengaturan Port ``` di Arduino IDE

   <table><tr><td width="810">

      Klik ``` Port ``` -> Pilih sesuai dengan port perangkat anda ``` (anda dapat melihatnya di Device Manager) ```
         
   </td></tr></table><br>

7. Ubah ``` Nama WiFi ```, ``` Kata Sandi WiFi ```, dan sebagainya sesuai dengan apa yang anda gunakan saat ini.<br><br>

8. Sebelum mengunggah program, silakan klik: ``` Verify ```.<br><br>

9. Jika tidak ada kesalahan dalam kode program, silakan klik: ``` Upload ```.<br><br>
    
10. Beberapa hal yang perlu anda lakukan saat menggunakan ``` board ESP32 ``` :

    <table><tr><td width="810">
       
       • Jika ``` board ESP32 ``` tidak dapat memproses ``` Source Code ``` secara total -> Tekan tombol ``` EN (RST) ``` -> ``` Restart ```.

       • Jika ``` board ESP32 ``` tidak dapat memproses ``` Source Code ``` secara otomatis maka :<br>

      - Ketika informasi: ``` Uploading... ``` telah muncul -> segera tekan dan tahan tombol ``` BOOT ```.<br>

      - Ketika informasi: ``` Writing at .... (%) ``` telah muncul -> lepaskan tombol ``` BOOT ```.

       • Jika pesan: ``` Done Uploading ``` telah muncul -> ``` Program yang diisikan tadi sudah bisa dioperasikan ```.

       • Jangan tekan tombol ``` BOOT ``` dan ``` EN ``` secara bersamaan karena hal ini bisa beralih ke mode ``` Unggah Firmware ```.

    </td></tr></table><br>

11. Jika masih ada masalah saat unggah program, maka coba periksa pada bagian ``` driver ``` / ``` port ``` / ``` yang lainnya ```.

<br><br>

## Basis data
1. Buka ``` XAMPP ```, lalu tekan tombol mulai di bagian ``` MySQL ``` untuk menjalankan server database secara lokal.<br><br>

2. Akses ``` peramban ``` terlebih dahulu untuk membuka panel admin basis data, silakan salin tautan berikut: ``` localhost/phpmyadmin/ ```.<br><br>
   
3. Buat basis data bernama ``` aws ```.<br><br>

4. Buka basis data ``` aws ``` dan Impor ``` aws.sql ``` di direktori ``` Automatic-Weather-System/Src/ ```.

<br><br>

## Pengaturan Bot Telegram
1. Buka <a href="https://t.me/botfather">@BotFather</a>.<br><br>

2. Ketik ``` /newbot ```.<br><br>

3. Ketik nama bot yang diinginkan, contoh: ``` AWS IOT BOT ```.<br><br>

4. Ketik nama pengguna bot yang diinginkan, contoh: ``` aws_iot_indo_bot ```.<br><br>

5. Lakukan juga untuk pengaturan gambar bot, deskripsi bot, dan lain sebagainya menyesuaikan dengan kebutuhan anda.<br><br>

6. Salin ``` API token bot telegram anda ``` -> kemudian tempelkan ke bagian flow Node-RED.

<br><br>

## Konfigurasi Node-RED
1. Buka ``` Command Prompt (CMD) ```, lalu masukkan perintah berikut untuk menginstal Node-RED :

   <table><tr><td width="810">

   ```
   npm install -g --unsafe-perm node-red
   ```

   </td></tr></table>

   Tunggu hingga proses instalasi selesai.<br><br>
   
2. Untuk menjaga keamanan Node-RED, Anda perlu mengatur autentikasi dengan menjalankan perintah berikut :

   <table><tr><td width="810">

   ```
   node-red admin init
   ```

   </td></tr></table>

   Silakan pilih opsi seperti yang ditunjukkan pada bagian ``` Autentikasi Node-RED ``` di bagian Sorotan. Untuk username dan password, silakan tentukan sendiri sesuai kebutuhan.<br><br>
   
3. Selanjutnya, jalankan Node-RED menggunakan perintah berikut :

   <table><tr><td width="810">

   ```
   node-red
   ```

   </td></tr></table>

   Tunggu hingga proses inisialisasi selesai dan muncul pesan yang menunjukkan bahwa server telah berhasil dimulai.<br><br>

4. Setelah itu, Node-RED siap diakses melalui browser web menggunakan alamat IP perangkat pada port 1880.<br><br>

5. Kemudian, login menggunakan akun yang telah Anda konfigurasikan sebagai langkah keamanan di Node-RED.<br><br>

6. Instal semua palet Node-RED yang diperlukan.<br><br>

7. Buka menu ``` Import ``` di Node-RED, lalu impor ``` flow_nodered.json ``` di direktori ``` Automatic-Weather-System/Src/ ```. Pastikan semua flow Node-RED telah berhasil dimuat.<br><br>

8. Kemudian, untuk menjalankan flow tersebut, klik ``` Deploy ```.

<br><br>

## Memulai
1. Unduh dan ekstrak repositori ini.<br><br>
   
2. Pastikan anda memiliki komponen elektronik yang diperlukan.<br><br>
   
3. Pastikan komponen anda telah dirancang sesuai dengan diagram.<br><br>
    
4. Konfigurasikan perangkat anda menurut pengaturan di atas.<br><br>

5. Selamat menikmati [Selesai].

<br><br>

## Sorotan

<table>
<tr>
<th width="840">Perangkat</th>
</tr>
<tr>
<td align="center"><img src="Assets/Documentation/Experiment/Device.jpg" alt="device"></td>
</tr>
</table>
<table>
<tr>
<th width="840" colspan="2">Autentikasi Node-RED</th>
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
<th width="840">Dasbor Node-RED</th>
</tr>
<tr>
<td align="center"><img src="Assets/Documentation/Experiment/NodeRED Dashboard.jpg" alt="dashboard"></td>
</tr>
</table>
<table>
<tr>
<th width="840">Menu Bot Telegram</th>
</tr>
<tr>
<td align="center"><img src="Assets/Documentation/Experiment/Telegram Bot Menu.jpg" alt="telegram-bot-menu"></td>
</tr>
</table>
<table>
<tr>
<th width="840" colspan="2">Pemantauan Status</th>
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
<th width="840" colspan="2">Sistem Peringatan Dini</th>
</tr>
<tr>
<td width="420" align="center"><img src="Assets/Documentation/Experiment/Early Warning System/Inject.jpg" alt="telegram-bot-inject"></td>
</tr>
<tr>
<td width="420" align="center"><img src="Assets/Documentation/Experiment/Early Warning System/Telegram Bot Alert.jpg" alt="telegram-bot-alert"></td>
</tr>
</table>

<br>
<strong>Informasi lebih lanjut:</strong> <a href="https://github.com/cakraawijaya/Automatic-Weather-System/blob/master/Assets/Documentation/Report/Portofolio%20Pelatihan%20Sertifikasi%20BNSP%20IIoT%20-%20Devan%20Cakra%20Mudra%20Wijaya-63-81.pdf"><u>Click Here</u></a>

<br><br><br>

## Apresiasi
Jika karya ini bermanfaat bagi anda, maka dukunglah karya ini sebagai bentuk apresiasi kepada penulis dengan mengklik tombol ``` ⭐Bintang ``` di bagian atas repositori.

<br><br>

## Penafian
Aplikasi ini merupakan hasil pengembangan dari Bootcamp Edutic.id x BNSP 2026. Saya tidak memungkiri bahwa saya masih menggunakan layanan pihak ketiga dalam pengerjaan ini, antara lain: library, framework, dan lain sebagainya.
