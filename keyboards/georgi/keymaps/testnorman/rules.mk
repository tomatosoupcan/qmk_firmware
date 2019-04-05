#----------------------------------------------------------------------------
# make georgi:default:dfu
# Make sure you have dfu-programmer installed!
#----------------------------------------------------------------------------

#Debug options
VERBOSE					 = yes
CONSOLE_ENABLE			 = yes
DEBUG_MATRIX_SCAN_RATE   = no
DEBUG_MATRIX			 = no
KEYBOARD_SHARED_EP       = yes
CUSTOM_MATRIX			 = yes
MOUSEKEY_ENABLE			 = no
NO_REPEAT				 = yes



# A bunch of stuff that you shouldn't touch unless you
# know what you're doing.
#
# No touchy, capiche?
SRC += matrix.c i2c_master.c
ifeq ($(strip $(DEBUG_MATRIX)), yes)
    OPT_DEFS += -DDEBUG_MATRIX
endif
ifeq ($(strip $(NO_REPEAT)), yes)
    OPT_DEFS += -DNO_REPEAT
endif
