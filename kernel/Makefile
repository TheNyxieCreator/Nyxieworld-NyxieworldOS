TARGET=nyxieworldos.bin
GNU=as
CXX=g++
DEBUG=-g
WARN=-Wall -Werror
LD=ld
CXXFLAGS = $(DEBUG) $(OPT) $(WARN)
CXXFLAGS += -w -m64 -fno-use-cxa-atexit -nostdlib -fno-builtin -fno-rtti -fno-exceptions -fno-leading-underscore
ASFLAGS = --64
LDFLAGS = -melf64_x86_64

objs = loader.o kernel.o main.o

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

%.o: %.s
	$(GNU) $(ASFLAGS) -o $@ $<

$(TARGET): linker.ld $(objs)
	$(LD) $(LDFLAGS) -T $< -o $@ $(objs)

