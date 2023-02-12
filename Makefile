CC=g++
CFLAGS=-fsanitize=address,undefined -fno-omit-frame-pointer -g -Wall -Wshadow -std=c++2a -Wno-unused-result -Wno-sign-compare -Wno-char-subscripts #-fuse-ld=gold

# CC=g++
# CFLAGS=-g -Wall

% :: %.cpp
	$(CC) $(CFLAGS) $< -o $@

# ./$@ < in > out
# clean:
# 	rm -rf ./*