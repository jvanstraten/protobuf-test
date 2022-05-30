
# Directory to take proto files from.
PROTO_SRC_DIR = substrait/proto

# Directory to generate proto cc/h files into.
PROTO_GEN_DIR = gen

# Find the base of all protobuf source files in PROTO_SRC_DIR.
PROTOS = $(basename $(shell cd $(PROTO_SRC_DIR) && find -name '*.proto'))

# Convert the bases to the input and output filenames.
PROTOS_IN  = $(patsubst %,$(PROTO_SRC_DIR)/%.proto,$(PROTOS))
PROTOS_CPP = $(patsubst %,$(PROTO_GEN_DIR)/%.pb.cc,$(PROTOS))
PROTOS_H   = $(patsubst %,$(PROTO_GEN_DIR)/%.pb.h,$(PROTOS))

# All C++ files for libconsumer.
COMPILE_CPP = src/consumer.cc $(PROTOS_CPP)
COMPILE_H = src/consumer.h $(PROTOS_H)
COMPILE_O = $(COMPILE_CPP:.cc=.o)

OUTPUT = libconsumer.so

.PHONY: all
all: $(OUTPUT)

# Generates the proto files.
.INTERMEDIATE: protobuf
$(PROTOS_CPP) $(PROTOS_H): protobuf
protobuf: $(PROTOS_IN)
	mkdir -p $(PROTO_GEN_DIR)
	protoc -I $(PROTO_SRC_DIR) --cpp_out=$(PROTO_GEN_DIR) $(PROTOS_IN)

# Compile the source files.
%.o: %.cc $(COMPILE_H)
	$(CXX) -c -std=c++11 -fPIC -I$(PROTO_GEN_DIR) $< -o $@

# Compile the .so file.
$(OUTPUT): $(COMPILE_O)
	$(CXX) -shared -std=c++11 -lprotobuf -I$(PROTO_GEN_DIR) $^ -o $@

.PHONY: clean
clean:
	rm -f $(OUTPUT) $(COMPILE_O)
	rm -rf $(PROTO_GEN_DIR)
