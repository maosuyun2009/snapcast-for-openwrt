CXXFLAGS  += -std=c++0x -Wall -Wno-unused-function -O3 -pthread -DVERSION=\"$(VERSION)\" -I.. # -static-libgcc -static-libstdc++
LDFLAGS = -lboost_system -lboost_program_options -lasound -lavahi-client -lavahi-common -latomic
TARGET = snapclient
OBJ = snapClient.o stream.o alsaPlayer.o clientConnection.o timeProvider.o decoder/pcmDecoder.o controller.o browseAvahi.o ../message/pcmChunk.o ../common/log.o ../message/sampleFormat.o
BIN = snapclient

all:	$(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(BIN) $(OBJ) $(LDFLAGS)
	#strip $(BIN)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BIN) $(OBJ) *~
