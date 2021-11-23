AUDIO_ENABLE         = no   # Audio output on port C6
BLUETOOTH_ENABLE     = no   # Enable Bluetooth with the Adafruit EZ-Key HID
BOOTLOADER           = qmk-dfu        # Using elite-c controllers
COMMAND_ENABLE       = no   # Commands for debug and configuration
CONSOLE_ENABLE       = no         # Console for debug
BOOTMAGIC_ENABLE      = no
EXTRAKEY_ENABLE      = yes  # Audio control and System control(+450)
LTO_ENABLE           = yes
MIDI_ENABLE          = no   # MIDI controls
MOUSEKEY_ENABLE      = no   # Mouse keys(+4700)
OLED_DRIVER          = SSD1306
OLED_ENABLE          = yes
SWAP_HANDS_ENABLE    = no   # Enable one-hand typing
RGBLIGHT_ENABLE      = no

ifeq ($(strip $(THEME)), godspeed)
    OPT_DEFS += -DTHEME_GODSPEED
else ifeq ($(strip $(THEME)), pulse)
    OPT_DEFS += -DTHEME_PULSE
else ifeq ($(strip $(THEME)), laser)
    OPT_DEFS += -DTHEME_LASER
else
	OPT_DEFS += -DTHEME_CORNE
endif
