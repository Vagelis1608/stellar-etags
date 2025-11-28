## Hanshow Stellar ESL firmware, modified to display info from a Remote device

Example/Basic program to upload the data with: https://github.com/Vagelis1608/esl-etag-raspbian

Currently supported models are the L3N@ and Pro-266R-N

Use their respective branches.



## This page is translated via Google translate, with minor manual fixes


### Applicable model L3N@ (Note: only suitable for L3N@ 2.9-inch devices, other models of the original project may no longer be compatible)



### final effect


- web upload pictures
![Bluetooth Management](/images/web.jpg)

- clock mode 2, picture mode
![Clock Mode 2, Picture Mode](/images/1553702163.jpg)

![Clock Mode 2, Picture Mode](/images/1587504241.jpg)



### Flash into the firmware steps
- 1. Remove the battery cover and observe whether the motherboard is as shown in the figure below. (Or check whether the master control is TLSR8359)

![Welding icon](/USB_UART_Flashing_connection.jpg)

- 2. Solder GND, VCC, RX, RTS four wires.
- 3. Use the usb2ttl module (CH340) to link the four soldered wires. Where rx is connected to tx, tx is connected to rx, vcc is connected to 3.3v, and GND is connected to GND. The RTS flying wire is connected to the third pin of the chip CH340G (you can also not solder it, manually connect it to GND before programming).
- 4. Open https://atc1441.github.io/ATC_TLSR_Paper_UART_Flasher.html, the default baud rate is 460800, Atime is the default, and the file is Firmware/ATC_Paper.bin
- 5. Click unlock first, then click write to flush, and wait for completion. On success, the screen will refresh automatically.

### Project compilation

```cmd

     cd Firmware
     makeit.exe clean && makeit.exe -j12

```

Prompt content after success:

```
'Create Flash image (binary format)'
'Invoking: TC32 Create Extended Listing'
'Invoking: Print Size'
"tc32_windows\\bin\\"tc32-elf-size -t ./out/ATC_Paper.elf
copy from `./out/ATC_Paper.elf' [elf32-littletc32] to `./out/../ATC_Paper.bin' [binary]
    text data bss dec hex filename
   75608 4604 25341 105553 19c51 ./out/ATC_Paper.elf
   75608 4604 25341 105553 19c51 (TOTALS)
'Finished building: sizeddummy'
' '
tl_fireware_tools.py v0.1 dev
Firmware CRC32: 0xe62d501e
'Finished building: out/../ATC_Paper.bin'
' '
'Finished building: out/ATC_Paper.lst'
' '
```

### Bluetooth link and OTA update
- 1. The TTL TX line must be disconnected first, otherwise the Bluetooth connection will not work.
- 2. OTA upgrade: https://atc1441.github.io/ATC_TLSR_Paper_OTA_writing.html

### upload image
- 1. Run `cd web_tools && python -m http.server`
- 2. Open http://127.0.0.1:8000 and link Bluetooth on the page
- 3. Select a picture and upload it. After uploading, you can add text or draw text manually. The dithering algorithm can also be set.
- 4. Send to the device, wait for the screen to refresh


### Resolved/Unresolved Issues
- [x] compile error
- [x] Brushing does not take effect
- [x] Wrong/abnormal screen area
- [x] Bluetooth cannot be connected/Bluetooth OTA upgrade
- [ ] Automatic model identification
- [x] python image generation script
- [x] Send pictures via bluetooth, the display size is not correct
- [x] Add notify after uploading pictures via bluetooth
- [x] Add scene and support switching
- [x] Picture mode
- [x] web supports image switching
- [x] Add new time scene
- [x] Support setting year, month and day
- [x] web supports drawing editing, uploading pictures directly, black and white dithering algorithm
- [x] Three-color dithering algorithm, three-color display support on the device side, Bluetooth transmission support
- [x] Is the data abnormal after epd buffer is refreshed (occasional black bars on the left or right)?
- [x] Chinese display (some Chinese are displayed in bitmap, not all Chinese are supported)

### Original readme.md

[README_EN.md](/README_en.md) (For other models, please refer to the original project, this project only supports L3N@ 2.9-inch devices)
[README_CN.md](/README_cn.md) (This is the original readme file..)

> Note:
> Modified based on the project [ATC_TLSR_Paper](https://github.com/atc1441/ATC_TLSR_Paper).


### material

- [TLSR8359 Specification Sheet](/docs/DS_TLSR8359-E_Datasheet for Telink ULP 2.4GHz RF SoC TLSR8359.pdf)
- [tlsr8x5x Bluetooth Development Manual (Chinese)](/docs/Telink Kite BLE SDK Developer Handbook Chinese.pdf)
- [Screen Driver Manual SSD1680.pdf](/docs/SSD1680.pdf)
