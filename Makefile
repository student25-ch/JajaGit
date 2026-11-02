CC = gcc
CFLAGS = -Wall -O2
LDFLAGS = -lz -lcrypto -lssl

SRC = jajagit.c \
error/error.c \
util/util.c \
fsutil/fsutil.c \
sha1/sha1.c \
zlib_wrap/zlib_wrap.c \
obj/obj.c \
treeblob/treeblob.c \
index/index.c \
refs/refs.c \
pack/pack.c \
socket/socket.c \
tls/tls.c \
httpgit/httpgit.c \
cmd/cmd_init.c \
cmd/cmd_add.c \
cmd/cmd_commit.c \
cmd/cmd_log.c \
cmd/cmd_ls.c \
cmd/cmd_checkout.c \
cmd/cmd_clone.c \
cmd/cmd_pull.c \
cmd/cmd_help.c

OBJ = $(SRC:.c=.o)
TARGET = jajagit

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean
