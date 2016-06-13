.PHONY: all
all:
	make -C ./src
	make -C ./bin
	make -C ./test
install:
	make -C ./src install
	make -C ./bin install
uninstall:
	make -C ./src uninstall
	make -C ./bin uninstall
clean:
	make -C ./src clean
	make -C ./bin clean
	make -C ./test clean
.PHONY: test   #here PHONY is really useful...
test:
	make -C ./src build
	make -C ./test build
	make -C ./test test
