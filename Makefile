bin:=main
file:=test
lib:=-lfmt
sanitizer:= -fsanitize=address -fsanitize=undefined
warning:= -Wall -Werror -Wextra -Wpedantic
flags:= -g $(warning)  $(sanitizer)
run: build

build:
	@g++ $(file).cpp $(flags) -o $(bin) -std=c++20 $(lib)&& ./$(bin)

clean:
	rm -rf $(file).o $(bin)

.PHONY: run build clean
