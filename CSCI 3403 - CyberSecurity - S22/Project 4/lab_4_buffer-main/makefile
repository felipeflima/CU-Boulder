#
#  Note: You must run ./setcookie before running make.
#

CC := gcc
CFLAGS := -g -m32 -static -Wno-implicit-function-declaration -U_FORTIFY_SOURCE -gdwarf-4
LDFLAGS := -g
LDLIBS :=

targets := target0 target1 target2 target3 target4

.PHONY: default clean install uninstall

default: $(targets) permissions

target0: CFLAGS += -fno-stack-protector -z execstack 
target1: CFLAGS += -fno-stack-protector -z execstack 
target2: CFLAGS += -fno-stack-protector -z execstack 
target3: CFLAGS += -fno-stack-protector -z execstack 
target4: CFLAGS += -fno-stack-protector

target0: target0.c helper.c
target1: target1.c helper.c
target2: target2.c helper.c
target3: target3.c helper.c
target4: target4.c helper.c

clean:
	rm -f $(targets)

permissions:
	sudo chown root:ubuntu target[234]
	sudo chmod 6777 target[234]
