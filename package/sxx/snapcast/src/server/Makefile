TARGET  = snapserver

CXXFLAGS  = -std=c++0x -Wall -Wno-unused-function -O3 -pthread -DVERSION=\"$(VERSION)\" -I..
#LDFLAGS = -lrt -lboost_system -lboost_program_options -lvorbis -lvorbisenc -logg -lFLAC -lavahi-client -lavahi-common
#LDFLAGS = -lrt -lboost_system -lboost_program_options -lavahi-client -lavahi-common
#LDFLAGS = -lboost_system -lboost_program_options -lavahi-client -lavahi-common
LDFLAGS = -lboost_system -lboost_program_options -lavahi-client -lavahi-common

OBJ = snapServer.o controlServer.o encoder/encoderFactory.o encoder/pcmEncoder.o serverSession.o publishAvahi.o pipeReader.o ../common/log.o ../message/pcmChunk.o ../message/sampleFormat.o
BIN = snapserver

all:	$(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(BIN) $(OBJ) $(LDFLAGS)
	#strip $(BIN)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BIN) $(OBJ) *~
