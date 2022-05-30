
.PHONY: all
all: run

.PHONY: libconsumer/libconsumer.so
libconsumer/libconsumer.so:
	$(MAKE) -C libconsumer libconsumer.so

.PHONY: libproducer/libproducer.so
libproducer/libproducer.so:
	$(MAKE) -C libproducer libproducer.so

test: src/test.cc libconsumer/libconsumer.so libproducer/libproducer.so
	$(CXX) \
		-Ilibconsumer/src -Llibconsumer -lconsumer \
		-Ilibproducer/src -Llibproducer -lproducer \
		$< -o $@

.PHONY: run
run: test
	LD_LIBRARY_PATH=libconsumer:libproducer ./test

.PHONY: clean
clean:
	$(MAKE) -C libconsumer clean
	$(MAKE) -C libproducer clean
	rm -f test
