#include "keyCode.h"
#include "keyboard.h"

const uint8_t  KeyboardReportDescriptor[76] = {
  0x05, 0x01,                         // Usage Page (Generic Desktop)
  0x09, 0x06,                         // Usage (Keyboard)
  0xA1, 0x01,                         // Collection (Application)
  0x05, 0x07,                         //     Usage Page (Key Codes)
  0x19, 0xe0,                         //     Usage Minimum (224)
  0x29, 0xe7,                         //     Usage Maximum (231)
  0x15, 0x00,                         //     Logical Minimum (0)
  0x25, 0x01,                         //     Logical Maximum (1)
  0x75, 0x01,                         //     Report Size (1)
  0x95, 0x08,                         //     Report Count (8)
  0x81, 0x02,                         //     Input (Data, Variable, Absolute)

  0x95, 0x01,                         //     Report Count (1)
  0x75, 0x08,                         //     Report Size (8)
  0x81, 0x01,                         //     Input (Constant) reserved byte(1)

  0x95, 0x05,                         //     Report Count (5)
  0x75, 0x01,                         //     Report Size (1)
  0x05, 0x08,                         //     Usage Page (Page# for LEDs)
  0x19, 0x01,                         //     Usage Minimum (1)
  0x29, 0x05,                         //     Usage Maximum (5)
  0x91, 0x02,                         //     Output (Data, Variable, Absolute), Led report
  0x95, 0x01,                         //     Report Count (1)
  0x75, 0x03,                         //     Report Size (3)
  0x91, 0x01,                         //     Output (Data, Variable, Absolute), Led report padding

  0x95, 0x06,                         //     Report Count (6)
  0x75, 0x08,                         //     Report Size (8)
  0x15, 0x00,                         //     Logical Minimum (0)
  0x25, 0x65,                         //     Logical Maximum (101)
  0x05, 0x07,                         //     Usage Page (Key codes)
  0x19, 0x00,                         //     Usage Minimum (0)
  0x29, 0x65,                         //     Usage Maximum (101)
  0x81, 0x00,                         //     Input (Data, Array) Key array(6 bytes)


  0x09, 0x05,                         //     Usage (Vendor Defined)
  0x15, 0x00,                         //     Logical Minimum (0)
  0x26, 0xFF, 0x00,                   //     Logical Maximum (255)
  0x75, 0x08,                         //     Report Count (2)
  0x95, 0x02,                         //     Report Size (8 bit)
  0xB1, 0x02,                         //     Feature (Data, Variable, Absolute)

  0xC0                                // End Collection (Application)
};
const uint8_t HIDInfo[4]={
  0x11,
  0x01,
  0x00,
  0x03
};

extern const uint8_t _asciimap[128] PROGMEM;
#define SHIFT 0x80
const uint8_t _asciimap[128] = {
	0x00,             // NUL
	0x00,             // SOH
	0x00,             // STX
	0x00,             // ETX
	0x00,             // EOT
	0x00,             // ENQ
	0x00,             // ACK
	0x00,             // BEL
	0x2a,			// BS	Backspace
	0x2b,			// TAB	Tab
	0x28,			// LF	Enter
	0x00,             // VT
	0x00,             // FF
	0x00,             // CR
	0x00,             // SO
	0x00,             // SI
	0x00,             // DEL
	0x00,             // DC1
	0x00,             // DC2
	0x00,             // DC3
	0x00,             // DC4
	0x00,             // NAK
	0x00,             // SYN
	0x00,             // ETB
	0x00,             // CAN
	0x00,             // EM
	0x00,             // SUB
	0x00,             // ESC
	0x00,             // FS
	0x00,             // GS
	0x00,             // RS
	0x00,             // US

	0x2c,		   //  ' '
	0x1e|SHIFT,	   // !
	0x34|SHIFT,	   // "
	0x20|SHIFT,    // #
	0x21|SHIFT,    // $
	0x22|SHIFT,    // %
	0x24|SHIFT,    // &
	0x34,          // '
	0x26|SHIFT,    // (
	0x27|SHIFT,    // )
	0x25|SHIFT,    // *
	0x2e|SHIFT,    // +
	0x36,          // ,
	0x2d,          // -
	0x37,          // .
	0x38,          // /
	0x27,          // 0
	0x1e,          // 1
	0x1f,          // 2
	0x20,          // 3
	0x21,          // 4
	0x22,          // 5
	0x23,          // 6
	0x24,          // 7
	0x25,          // 8
	0x26,          // 9
	0x33|SHIFT,      // :
	0x33,          // ;
	0x36|SHIFT,      // <
	0x2e,          // =
	0x37|SHIFT,      // >
	0x38|SHIFT,      // ?
	0x1f|SHIFT,      // @
	0x04|SHIFT,      // A
	0x05|SHIFT,      // B
	0x06|SHIFT,      // C
	0x07|SHIFT,      // D
	0x08|SHIFT,      // E
	0x09|SHIFT,      // F
	0x0a|SHIFT,      // G
	0x0b|SHIFT,      // H
	0x0c|SHIFT,      // I
	0x0d|SHIFT,      // J
	0x0e|SHIFT,      // K
	0x0f|SHIFT,      // L
	0x10|SHIFT,      // M
	0x11|SHIFT,      // N
	0x12|SHIFT,      // O
	0x13|SHIFT,      // P
	0x14|SHIFT,      // Q
	0x15|SHIFT,      // R
	0x16|SHIFT,      // S
	0x17|SHIFT,      // T
	0x18|SHIFT,      // U
	0x19|SHIFT,      // V
	0x1a|SHIFT,      // W
	0x1b|SHIFT,      // X
	0x1c|SHIFT,      // Y
	0x1d|SHIFT,      // Z
	0x2f,          // [
	0x31,          // bslash
	0x30,          // ]
	0x23|SHIFT,    // ^
	0x2d|SHIFT,    // _
	0x35,          // `
	0x04,          // a
	0x05,          // b
	0x06,          // c
	0x07,          // d
	0x08,          // e
	0x09,          // f
	0x0a,          // g
	0x0b,          // h
	0x0c,          // i
	0x0d,          // j
	0x0e,          // k
	0x0f,          // l
	0x10,          // m
	0x11,          // n
	0x12,          // o
	0x13,          // p
	0x14,          // q
	0x15,          // r
	0x16,          // s
	0x17,          // t
	0x18,          // u
	0x19,          // v
	0x1a,          // w
	0x1b,          // x
	0x1c,          // y
	0x1d,          // z
	0x2f|SHIFT,    // {
	0x31|SHIFT,    // |
	0x30|SHIFT,    // }
	0x35|SHIFT,    // ~
	0				// DEL
};
BLEKeyboard::BLEKeyboard(){
  Report=new BLECharacteristic("2A4D", BLERead | BLENotify,8);
  HIDInformation=new BLECharacteristic("2A4A", BLERead,4);
  HIDControlPoint=new BLEUnsignedCharCharacteristic("2A4C", BLEWriteWithoutResponse);
  ProtocolMode=new BLEUnsignedCharCharacteristic("2A4E", BLERead | BLEWriteWithoutResponse);
  ReportMap=new BLECharacteristic("2A4B", BLERead,76);
  //ReportOutput=new BLEUnsignedCharCharacteristic("2A4D", BLERead | BLENotify | BLEWrite | BLEWriteWithoutResponse);
  BootKeyboardInputReport=new BLECharacteristic("2A22", BLERead | BLENotify,8);
  BootKeyboardOutputReport=new BLEUnsignedCharCharacteristic("2A32", BLERead | BLEWrite | BLENotify);
}
void BLEKeyboard::begin(BLEPeripheral &BLEPer){
  releaseAll();
  // add service and characteristic:
  BLEPer.addAttribute(*Report);
  BLEPer.addAttribute(*HIDInformation);
  BLEPer.addAttribute(*ProtocolMode);
  BLEPer.addAttribute(*HIDControlPoint);
  BLEPer.addAttribute(*ReportMap);
  //BLEPer.addAttribute(*ReportOutput);
  BLEPer.addAttribute(*BootKeyboardInputReport);
  BLEPer.addAttribute(*BootKeyboardOutputReport);

  ProtocolMode->setValue(1);
  //ReportOutput->setValue(0);
  ReportMap->setValue(KeyboardReportDescriptor,76);
  BootKeyboardInputReport->setValue(KeyboardReport,8);
  BootKeyboardOutputReport->setValue(0);
  HIDInformation->setValue(HIDInfo,4);
}
void BLEKeyboard::releaseAll(void){
  KeyboardReport[0] = 0;
  KeyboardReport[1] = 0;
  KeyboardReport[2] = 0;
  KeyboardReport[3] = 0;
  KeyboardReport[4] = 0;
  KeyboardReport[5] = 0;
  KeyboardReport[6] = 0;
  KeyboardReport[7] = 0;
  sendReport(KeyboardReport);
}
void BLEKeyboard::sendReport(uint8_t* keys){
	Report->setValue(keys,8);
}
size_t BLEKeyboard::press(uint8_t k){
	uint8_t i;
	if (k >= 136) {			// it's a non-printing key (not a modifier)
		k = k - 136;
	} else if (k >= 128) {	// it's a modifier key
		KeyboardReport[0] |= (1<<(k-128));
		k = 0;
	} else {				// it's a printing key
		k = pgm_read_byte(_asciimap + k);
		if (!k) {
			setWriteError();
			return 0;
		}
		if (k & 0x80) {						// it's a capital letter or other character reached with shift
			KeyboardReport[0] |= 0x02;	// the left shift modifier
			k &= 0x7F;
		}
	}

	// Add k to the key report only if it's not already present
	// and if there is an empty slot.
	if (KeyboardReport[2+0] != k && KeyboardReport[2+1] != k &&
		  KeyboardReport[2+2] != k && KeyboardReport[2+3] != k &&
		  KeyboardReport[2+4] != k && KeyboardReport[2+5] != k) {

		for (i=0; i<6; i++) {
			if (KeyboardReport[2+i] == 0x00) {
				KeyboardReport[2+i] = k;
				break;
			}
		}
		if (i == 6) {
			setWriteError();
			return 0;
		}
	}
	sendReport(KeyboardReport);
	return 1;
}
size_t BLEKeyboard::release(uint8_t k){
	uint8_t i;
	if (k >= 136) {			// it's a non-printing key (not a modifier)
		k = k - 136;
	} else if (k >= 128) {	// it's a modifier key
		KeyboardReport[0] &= ~(1<<(k-128));
		k = 0;
	} else {				// it's a printing key
		k = pgm_read_byte(_asciimap + k);
		if (!k) {
			return 0;
		}
		if (k & 0x80) {							// it's a capital letter or other character reached with shift
			KeyboardReport[0] &= ~(0x02);	// the left shift modifier
			k &= 0x7F;
		}
	}

	// Test the key report to see if k is present.  Clear it if it exists.
	// Check all positions in case the key is present more than once (which it shouldn't be)
	for (i=0; i<6; i++) {
		if (0 != k && KeyboardReport[2+i] == k) {
			KeyboardReport[2+i] = 0x00;
		}
	}

	sendReport(KeyboardReport);
	return 1;
}
size_t BLEKeyboard::write(uint8_t c){
	uint8_t p = press(c);  // Keydown
	release(c);            // Keyup
	return p;              // just return the result of press() since release() almost always returns 1
}
